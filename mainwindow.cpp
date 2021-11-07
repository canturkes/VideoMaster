#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include <functional>
#include <atomic>
#include <thread>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

namespace {

    QString videoFileName;
    cv::VideoCapture vid;

    std::string savePath = "D:/imgs/"; // default --change

    int MAX_FRAME_INDEX;

    std::atomic<double> scale = 1.0;
    std::atomic<int> rotateMode = -1;
    std::atomic<int> interpMode = cv::INTER_LINEAR;
    std::atomic<bool> histEqualize = false;
    std::atomic<double> gammaCorr = 1.0;

    std::atomic<int> cropT = 0;
    std::atomic<int> cropB = 0;
    std::atomic<int> cropL = 0;
    std::atomic<int> cropR = 0;

    std::atomic<int> step = 1;

    const cv::String windowName = "Frame";
    std::atomic<int> currentFrameIndex = 0;

    cv::Mat rawFrame;
    cv::Mat scaledFrame;
    cv::Mat rotatedFrame;
    cv::Mat croppedFrame;
    cv::Mat finalFrame;

    cv::Mat gammaLUT(1,256,CV_8U);

    bool boomLoopEnable = false;
    bool boomEnable = false;
    bool loopEnable = false;
    bool reverseLoop = false;
    int boomLoopFrom;
    int boomLoopTo;
    std::atomic<int> boomLoopDelay = 25;

    std::atomic<bool> THREAD_ACTIVE = false;
    std::atomic<bool> RUN_PERMISSION = false;
}

void runFreeMode(Ui::MainWindow*);
void runBoomLoopMode(Ui::MainWindow*);
std::string createTimeStamp();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Welcome. No video.");
    ui->statusbar->addPermanentWidget(ui->locationHorizontalSlider);
    ui->locationHorizontalSlider->setEnabled(false);
}

MainWindow::~MainWindow()
{
    RUN_PERMISSION.store(false, std::memory_order_release);

    while(THREAD_ACTIVE.load(std::memory_order_acquire))
        std::this_thread::yield();

    if (vid.isOpened())
        vid.release();

    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    videoFileName = QFileDialog::getOpenFileName(this, "Open a video", "D://", "MP4 File (*.mp4)"); // --change
    ui->videoFileNameLineEdit->setText(videoFileName);
}

void MainWindow::on_openVideoButton_clicked()
{
    if ( vid.isOpened() ) {
        QMessageBox::warning(this, "Warning", "A video has already been opened.\nPress 'Close' first.");
    }
    else if (videoFileName == "") {
        QMessageBox::warning(this, "Warning", "Invalid file name.");
    }
    else {
        vid.open(videoFileName.toStdString());

        if (!vid.isOpened()) {
            QMessageBox::warning(this, "Warning", "Video cannot be opened.");
        }
        else {
            MAX_FRAME_INDEX = vid.get(cv::CAP_PROP_FRAME_COUNT) - 1;

            ui->statusbar->showMessage("Video opened. Max. frame index: " + QString::number(MAX_FRAME_INDEX));
            ui->jumpToSpinBox->setRange(0, MAX_FRAME_INDEX);
            ui->boomLoopToSpinBox->setRange(0,MAX_FRAME_INDEX);
            ui->boomLoopFromSpinBox->setRange(0,MAX_FRAME_INDEX);
            ui->stepSpinBox->setRange(1,MAX_FRAME_INDEX);
            ui->locationHorizontalSlider->setRange(0,MAX_FRAME_INDEX);

            ui->jumpToSpinBox->setValue(0);
            ui->stepSpinBox->setValue(1);

            ui->boomLoopToSpinBox->setValue(0);
            ui->boomLoopFromSpinBox->setValue(0);
            ui->boomLoopDelaySpinBox->setValue(25);
            ui->boomLoopEnableCheckBox->setChecked(false);
            ui->loopCheckBox->setChecked(false);

            ui->cfiLabel->setText(QString::number(0));
            ui->locationHorizontalSlider->setValue(0);

            ui->scaleSpinBox->setValue(1.0);
            ui->rotateSpinBox->setValue(0);
            ui->heqCheckBox->setChecked(false);
            ui->bilinearRadioBox->setChecked(true);
            ui->bicubicRadioBox->setChecked(false);
            ui->gammaDoubleSpinBox->setValue(1.0);

            ui->cropTopSpinBox->setValue(0);
            ui->cropBottomSpinBox->setValue(0);
            ui->cropLeftSpinBox->setValue(0);
            ui->cropRightSpinBox->setValue(0);

            step = 1;

            boomLoopEnable = false;
            boomEnable = false;
            loopEnable = false;
            boomLoopTo = 0;
            boomLoopFrom = 0;
            boomLoopDelay = 25;

            scale = 1.0;
            rotateMode = -1;
            histEqualize = false;
            interpMode = cv::INTER_LINEAR;
            gammaCorr = 1.0;
            uchar* p = gammaLUT.ptr();
            for (int i = 0; i < 256; ++i)
                p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, 1.0) * 255.0);

            cropT = 0;
            cropB = 0;
            cropL = 0;
            cropR = 0;

            finalFrame.release();
        }
    }
}

void MainWindow::on_closeVideoButton_clicked()
{
    RUN_PERMISSION.store(false, std::memory_order_release);

    while(THREAD_ACTIVE.load(std::memory_order_acquire))
        std::this_thread::yield();

    if ( vid.isOpened() ) {
        vid.release();
        ui->statusbar->showMessage("No video.");
    }
}

void MainWindow::on_applyButton_clicked()
{
    if (vid.isOpened()) {

        RUN_PERMISSION.store(false, std::memory_order_release);

        while(THREAD_ACTIVE.load(std::memory_order_acquire))
            std::this_thread::yield();

        RUN_PERMISSION.store(true, std::memory_order_release);

        if ( ui->boomLoopEnableCheckBox->isChecked() ) {
        // BoomLoop mode
            boomLoopEnable = true;
            if (ui->loopCheckBox->isChecked()) {
                loopEnable = true;
                boomEnable = false;
                if (ui->reverseCheckBox->isChecked()) {
                    reverseLoop = true;
                } else {
                    reverseLoop = false;
                }
            } else {
                loopEnable = false;
                boomEnable = true;
            }
            boomLoopFrom = ui->boomLoopFromSpinBox->value();
            boomLoopTo = ui->boomLoopToSpinBox->value();

            if ( boomLoopFrom < boomLoopTo ) {
                std::thread tBoomerang(&runBoomLoopMode, std::ref(ui));
                tBoomerang.detach();
            }
            else {
                QMessageBox::warning(this, "Warning", "'from' <= 'to' in boom/loop mode.");
            }
        }
        else {
        // Free Mode
            boomLoopEnable = false;
            boomEnable = false;
            loopEnable = false;
            currentFrameIndex = ui->jumpToSpinBox->value();
            std::thread tRunFree(&runFreeMode, std::ref(ui));
            tRunFree.detach();
        }
    }
    else {
        QMessageBox::warning(this, "Warning", "No video has been opened yet.");
    }
}

void runFreeMode(Ui::MainWindow* ui) {

    THREAD_ACTIVE.store(true, std::memory_order_release);

    ui->statusbar->showMessage("Free mode.");

    while ( RUN_PERMISSION.load(std::memory_order_acquire) )
    {
        vid.set(cv::CAP_PROP_POS_FRAMES, currentFrameIndex);
        ui->cfiLabel->setText(QString::number(currentFrameIndex));
        ui->locationHorizontalSlider->setValue(currentFrameIndex);

        vid.read(rawFrame);

        if (rawFrame.empty()) {
            qDebug() << "Empty frame at index: " << currentFrameIndex << '\n';
            break;
        }

        if (rotateMode != -1)
            cv::rotate(rawFrame, rotatedFrame, rotateMode);
        else rotatedFrame = rawFrame;

        if (scale != 1.0) {
            cv::resize(rotatedFrame, scaledFrame ,cv::Size(),scale,scale,interpMode);
        }
        else scaledFrame = rotatedFrame;

        // cropping
        int rowStartIdx;
        int rowEndIdx;
        int colStartIdx;
        int colEndIdx;

        if (cropT.load() == 0) rowStartIdx = 0;
        else rowStartIdx = static_cast<int>(floor(cropT.load()/100.0 * scaledFrame.rows));

        if (cropB.load() == 0) rowEndIdx = scaledFrame.rows;
        else rowEndIdx = static_cast<int>(ceil((100-cropB.load())/100.0 * scaledFrame.rows));

        if (cropL.load() == 0) colStartIdx = 0;
        else colStartIdx = static_cast<int>(floor(cropL.load()/100.0 * scaledFrame.cols));

        if (cropR.load() == 0) colEndIdx = scaledFrame.cols;
        else colEndIdx = static_cast<int>(ceil((100-cropR.load())/100.0 * scaledFrame.cols));

        croppedFrame = scaledFrame(cv::Range(rowStartIdx,rowEndIdx),cv::Range(colStartIdx,colEndIdx));

        if (histEqualize) {
            cv::Mat channels[3];
            cv::split(croppedFrame,channels);
            for(unsigned c = 0; c < 3 ;c++)
                cv::equalizeHist(channels[c],channels[c]);
            cv::merge(channels,3,finalFrame);
        }
        else finalFrame = croppedFrame;

        if(gammaCorr != 1.0)
            cv::LUT(finalFrame,gammaLUT,finalFrame);

        cv::imshow(windowName, finalFrame);
        int key = cv::waitKey(0);

        if(key==int('q'))
            break;
        else if(key == int('d')) {
            if ( currentFrameIndex + step <= MAX_FRAME_INDEX )
                currentFrameIndex += step;
            else currentFrameIndex = MAX_FRAME_INDEX;
        }
        else if(key == int('a')) {
            if ( currentFrameIndex - step >= 0 )
                currentFrameIndex -= step;
            else currentFrameIndex = 0;
        }
    }

    cv::destroyWindow(windowName);
    ui->statusbar->showMessage("Video opened. Maximum frame index: " + QString::number(MAX_FRAME_INDEX));
    THREAD_ACTIVE.store(false, std::memory_order_release);
}

void runBoomLoopMode(Ui::MainWindow* ui)
{
    THREAD_ACTIVE.store(true, std::memory_order_release);

    currentFrameIndex = boomLoopFrom;

    std::vector<cv::Mat> boomLoopFrames;

    if (loopEnable)
        ui->statusbar->showMessage("Loop is loading...");
    else
        ui->statusbar->showMessage("Boomerang is loading...");

    for (int i = boomLoopFrom ; i<= boomLoopTo ; i++) {
        vid.set(cv::CAP_PROP_POS_FRAMES, i);

        cv::Mat dummyFrame;
        vid.read(dummyFrame);

        if (dummyFrame.empty()) {
            qDebug() << "Empty frame at index: " << i << '\n';
            break;
        }

        if (rotateMode != -1)
            cv::rotate(dummyFrame, dummyFrame,rotateMode);

        if (scale != 1.0)
            cv::resize(dummyFrame, dummyFrame,cv::Size(),scale,scale,interpMode);

        int rowStartIdx;
        int rowEndIdx;
        int colStartIdx;
        int colEndIdx;

        if (cropT.load() == 0) rowStartIdx = 0;
        else rowStartIdx = static_cast<int>(floor(cropT.load()/100.0 * dummyFrame.rows));

        if (cropB.load() == 0) rowEndIdx = dummyFrame.rows;
        else rowEndIdx = static_cast<int>(ceil((100-cropB.load())/100.0 * dummyFrame.rows));

        if (cropL.load() == 0) colStartIdx = 0;
        else colStartIdx = static_cast<int>(floor(cropL.load()/100.0 * dummyFrame.cols));

        if (cropR.load() == 0) colEndIdx = dummyFrame.cols;
        else colEndIdx = static_cast<int>(ceil((100-cropR.load())/100.0 * dummyFrame.cols));

        dummyFrame = dummyFrame(cv::Range(rowStartIdx,rowEndIdx),cv::Range(colStartIdx,colEndIdx));

        if (histEqualize) {
            cv::Mat channels[3];
            cv::split(dummyFrame,channels);

            for(unsigned c = 0; c < 3 ;c++)
                cv::equalizeHist(channels[c],channels[c]);

            cv::merge(channels,3,dummyFrame);
        }

        if(gammaCorr != 1.0)
            cv::LUT(dummyFrame,gammaLUT,dummyFrame);

        boomLoopFrames.push_back(dummyFrame);
    }

    if (loopEnable) {

        ui->statusbar->showMessage("Loop loaded.");

        if (reverseLoop) {

            currentFrameIndex = boomLoopTo;

            while ( RUN_PERMISSION.load(std::memory_order_acquire) )
            {
                ui->cfiLabel->setText(QString::number(currentFrameIndex));
                ui->locationHorizontalSlider->setValue(currentFrameIndex);

                finalFrame = boomLoopFrames[currentFrameIndex-boomLoopFrom];

                cv::imshow(windowName, finalFrame);
                int key = cv::waitKey(boomLoopDelay);
                if(key==int('q')) break;

                if(currentFrameIndex == boomLoopFrom)
                    currentFrameIndex = boomLoopTo;

                --currentFrameIndex;
            }

        } else {

            while ( RUN_PERMISSION.load(std::memory_order_acquire) )
            {
                ui->cfiLabel->setText(QString::number(currentFrameIndex));
                ui->locationHorizontalSlider->setValue(currentFrameIndex);

                finalFrame = boomLoopFrames[currentFrameIndex-boomLoopFrom];

                cv::imshow(windowName, finalFrame);
                int key = cv::waitKey(boomLoopDelay);

                if(key==int('q')) break;

                if(currentFrameIndex == boomLoopTo)
                    currentFrameIndex = boomLoopFrom;

                currentFrameIndex++;
            }

        }

    } else {

        ui->statusbar->showMessage("Boomerang loaded.");

        bool increase = true;

        while ( RUN_PERMISSION.load(std::memory_order_acquire) )
        {
            ui->cfiLabel->setText(QString::number(currentFrameIndex));
            ui->locationHorizontalSlider->setValue(currentFrameIndex);

            finalFrame = boomLoopFrames[currentFrameIndex-boomLoopFrom];

            cv::imshow(windowName, finalFrame);
            int key = cv::waitKey(boomLoopDelay);

            if(key==int('q')) break;

            if (increase)
                currentFrameIndex++;
            else currentFrameIndex--;

            if(currentFrameIndex == boomLoopTo)
                increase = false;
            if(currentFrameIndex == boomLoopFrom)
                increase = true;
        }

    }

    cv::destroyWindow(windowName);

    boomLoopFrames.clear();

    ui->statusbar->showMessage("Video opened. Max. frame index: " + QString::number(MAX_FRAME_INDEX));

    THREAD_ACTIVE.store(false, std::memory_order_release);
}

void MainWindow::on_savePathSetButton_clicked()
{
    if (ui->savePathLineEdit->text() != "")
    {
        savePath = ui->savePathLineEdit->text().toStdString() + "/";

        try {
            if ( ! std::filesystem::is_directory(savePath) )
                std::filesystem::create_directory(savePath);
        } catch (std::system_error e) {
            qDebug() << e.what() << '\n';
            savePath = "D:/imgs/"; // default save path --change
        }
    }
}

std::string createTimeStamp() {
    auto time_point_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm bt{};
    localtime_s(&bt, &time_point_t);
    std::stringstream oss;
    oss << '_' << std::put_time(&bt, "%F-%H-%M-%S"); // --optional
    return oss.str();
}

void MainWindow::on_saveFrameButton_clicked()
{
    if ( vid.isOpened() ) {
        if (!finalFrame.empty()) {
            if (!boomLoopEnable) {
                auto saveFileName = savePath + "vm_f" + std::to_string(currentFrameIndex) // --optional
                                            + createTimeStamp() + ".png";
                cv::imwrite(saveFileName, finalFrame);
            } else QMessageBox::warning(this, "Warning", "Cannot save during Boomerang mode.");
        } else QMessageBox::warning(this,"Warning","Frame is empty.");
    } else QMessageBox::warning(this, "Warning", "No video has been opened.");
}

void MainWindow::on_videoFileNameLineEdit_textChanged(const QString &arg1)
{
    if ( arg1.endsWith(".mp4") ) { // --optional
        videoFileName = arg1;
    }
}

void MainWindow::on_stepSpinBox_valueChanged(int val)
{
    step.store(val);
}

void MainWindow::on_scaleSpinBox_valueChanged(double val)
{
    scale.store(val);
}

void MainWindow::on_heqCheckBox_clicked(bool checked)
{
    histEqualize.store(checked);
}

void MainWindow::on_rotateSpinBox_valueChanged(int val)
{
    switch (val)
    {
    case 0:
        rotateMode = -1; break;
    case 90:
        rotateMode = cv::ROTATE_90_COUNTERCLOCKWISE; break;
    case 180:
        rotateMode = cv::ROTATE_180; break;
    case 270:
        rotateMode = cv::ROTATE_90_CLOCKWISE; break;
    default:
        rotateMode = -1;
    }
}

void MainWindow::on_bilinearRadioBox_clicked(bool checked)
{
    if (checked)
        interpMode.store(cv::INTER_LINEAR);
    else interpMode.store(cv::INTER_LANCZOS4);
}

void MainWindow::on_bicubicRadioBox_clicked(bool checked)
{
    if (checked)
        interpMode.store(cv::INTER_LANCZOS4);
    else interpMode.store(cv::INTER_LINEAR);
}

void MainWindow::on_boomLoopDelaySpinBox_valueChanged(int val)
{
    boomLoopDelay.store(val);
}

void MainWindow::on_gammaDoubleSpinBox_valueChanged(double val)
{
    uchar* p = gammaLUT.ptr();
    for (int i = 0; i < 256; ++i)
        p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, val) * 255.0);
    gammaCorr.store(val);
}

void MainWindow::on_cropTopSpinBox_valueChanged(int val)
{
    if ( val + cropB.load() <= 99 )
        cropT.store(val);
    else {
        ui->cropTopSpinBox->setValue(99 - cropB.load());
        cropT.store(99-cropB.load());
    }
}

void MainWindow::on_cropBottomSpinBox_valueChanged(int val)
{
    if ( val + cropT.load() <= 99 )
        cropB.store(val);
    else {
        ui->cropBottomSpinBox->setValue(99 - cropT.load());
        cropB.store(99-cropT.load());
    }
}

void MainWindow::on_cropLeftSpinBox_valueChanged(int val)
{
    if ( val + cropR.load() <= 99 )
        cropL.store(val);
    else {
        ui->cropLeftSpinBox->setValue(99 - cropR.load());
        cropL.store(99-cropR.load());
    }
}

void MainWindow::on_cropRightSpinBox_valueChanged(int val)
{
    if ( val + cropL.load() <= 99 )
        cropR.store(val);
    else {
        ui->cropRightSpinBox->setValue(99 - cropL.load());
        cropR.store(99-cropL.load());
    }
}
