/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *videoFileNameLineEdit;
    QPushButton *openVideoButton;
    QPushButton *browseButton;
    QPushButton *closeVideoButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *savePathLineEdit;
    QPushButton *savePathSetButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QDoubleSpinBox *scaleSpinBox;
    QFrame *line;
    QLabel *label_10;
    QRadioButton *bilinearRadioBox;
    QRadioButton *bicubicRadioBox;
    QFrame *line_2;
    QCheckBox *heqCheckBox;
    QFrame *line_4;
    QLabel *label_16;
    QDoubleSpinBox *gammaDoubleSpinBox;
    QFrame *line_3;
    QLabel *label_5;
    QSpinBox *rotateSpinBox;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_12;
    QSpinBox *cropTopSpinBox;
    QLabel *label_13;
    QSpinBox *cropBottomSpinBox;
    QLabel *label_14;
    QSpinBox *cropLeftSpinBox;
    QLabel *label_15;
    QSpinBox *cropRightSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpinBox *jumpToSpinBox;
    QLabel *label_11;
    QSpinBox *stepSpinBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QCheckBox *loopCheckBox;
    QCheckBox *boomLoopEnableCheckBox;
    QSpinBox *boomLoopFromSpinBox;
    QSpinBox *boomLoopDelaySpinBox;
    QLabel *label_6;
    QLabel *label_4;
    QSpinBox *boomLoopToSpinBox;
    QCheckBox *reverseCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *applyButton;
    QLabel *label_9;
    QLabel *cfiLabel;
    QPushButton *saveFrameButton;
    QSlider *locationHorizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(641, 387);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        videoFileNameLineEdit = new QLineEdit(centralwidget);
        videoFileNameLineEdit->setObjectName(QString::fromUtf8("videoFileNameLineEdit"));

        horizontalLayout_5->addWidget(videoFileNameLineEdit);

        openVideoButton = new QPushButton(centralwidget);
        openVideoButton->setObjectName(QString::fromUtf8("openVideoButton"));

        horizontalLayout_5->addWidget(openVideoButton);

        browseButton = new QPushButton(centralwidget);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        horizontalLayout_5->addWidget(browseButton);

        closeVideoButton = new QPushButton(centralwidget);
        closeVideoButton->setObjectName(QString::fromUtf8("closeVideoButton"));

        horizontalLayout_5->addWidget(closeVideoButton);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        savePathLineEdit = new QLineEdit(centralwidget);
        savePathLineEdit->setObjectName(QString::fromUtf8("savePathLineEdit"));

        horizontalLayout_6->addWidget(savePathLineEdit);

        savePathSetButton = new QPushButton(centralwidget);
        savePathSetButton->setObjectName(QString::fromUtf8("savePathSetButton"));

        horizontalLayout_6->addWidget(savePathSetButton);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        scaleSpinBox = new QDoubleSpinBox(centralwidget);
        scaleSpinBox->setObjectName(QString::fromUtf8("scaleSpinBox"));
        scaleSpinBox->setMinimum(0.500000000000000);
        scaleSpinBox->setMaximum(10.000000000000000);
        scaleSpinBox->setSingleStep(0.050000000000000);
        scaleSpinBox->setValue(1.000000000000000);

        horizontalLayout_4->addWidget(scaleSpinBox);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);

        bilinearRadioBox = new QRadioButton(centralwidget);
        bilinearRadioBox->setObjectName(QString::fromUtf8("bilinearRadioBox"));
        bilinearRadioBox->setChecked(true);

        horizontalLayout_4->addWidget(bilinearRadioBox);

        bicubicRadioBox = new QRadioButton(centralwidget);
        bicubicRadioBox->setObjectName(QString::fromUtf8("bicubicRadioBox"));

        horizontalLayout_4->addWidget(bicubicRadioBox);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_2);

        heqCheckBox = new QCheckBox(centralwidget);
        heqCheckBox->setObjectName(QString::fromUtf8("heqCheckBox"));
        heqCheckBox->setChecked(false);
        heqCheckBox->setTristate(false);

        horizontalLayout_4->addWidget(heqCheckBox);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_4);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_4->addWidget(label_16);

        gammaDoubleSpinBox = new QDoubleSpinBox(centralwidget);
        gammaDoubleSpinBox->setObjectName(QString::fromUtf8("gammaDoubleSpinBox"));
        gammaDoubleSpinBox->setMaximum(3.000000000000000);
        gammaDoubleSpinBox->setSingleStep(0.050000000000000);
        gammaDoubleSpinBox->setValue(1.000000000000000);

        horizontalLayout_4->addWidget(gammaDoubleSpinBox);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_3);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        rotateSpinBox = new QSpinBox(centralwidget);
        rotateSpinBox->setObjectName(QString::fromUtf8("rotateSpinBox"));
        rotateSpinBox->setMaximum(270);
        rotateSpinBox->setSingleStep(90);

        horizontalLayout_4->addWidget(rotateSpinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_8 = new QHBoxLayout(groupBox_3);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_8->addWidget(label_12);

        cropTopSpinBox = new QSpinBox(groupBox_3);
        cropTopSpinBox->setObjectName(QString::fromUtf8("cropTopSpinBox"));
        cropTopSpinBox->setMaximum(99);

        horizontalLayout_8->addWidget(cropTopSpinBox);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_8->addWidget(label_13);

        cropBottomSpinBox = new QSpinBox(groupBox_3);
        cropBottomSpinBox->setObjectName(QString::fromUtf8("cropBottomSpinBox"));

        horizontalLayout_8->addWidget(cropBottomSpinBox);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_8->addWidget(label_14);

        cropLeftSpinBox = new QSpinBox(groupBox_3);
        cropLeftSpinBox->setObjectName(QString::fromUtf8("cropLeftSpinBox"));

        horizontalLayout_8->addWidget(cropLeftSpinBox);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_8->addWidget(label_15);

        cropRightSpinBox = new QSpinBox(groupBox_3);
        cropRightSpinBox->setObjectName(QString::fromUtf8("cropRightSpinBox"));

        horizontalLayout_8->addWidget(cropRightSpinBox);


        horizontalLayout_7->addWidget(groupBox_3);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        jumpToSpinBox = new QSpinBox(groupBox_2);
        jumpToSpinBox->setObjectName(QString::fromUtf8("jumpToSpinBox"));

        horizontalLayout->addWidget(jumpToSpinBox);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout->addWidget(label_11);

        stepSpinBox = new QSpinBox(groupBox_2);
        stepSpinBox->setObjectName(QString::fromUtf8("stepSpinBox"));
        stepSpinBox->setMinimum(1);

        horizontalLayout->addWidget(stepSpinBox);


        horizontalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 4, 1, 1);

        loopCheckBox = new QCheckBox(groupBox);
        loopCheckBox->setObjectName(QString::fromUtf8("loopCheckBox"));

        gridLayout_2->addWidget(loopCheckBox, 0, 2, 1, 1);

        boomLoopEnableCheckBox = new QCheckBox(groupBox);
        boomLoopEnableCheckBox->setObjectName(QString::fromUtf8("boomLoopEnableCheckBox"));

        gridLayout_2->addWidget(boomLoopEnableCheckBox, 0, 1, 1, 1);

        boomLoopFromSpinBox = new QSpinBox(groupBox);
        boomLoopFromSpinBox->setObjectName(QString::fromUtf8("boomLoopFromSpinBox"));

        gridLayout_2->addWidget(boomLoopFromSpinBox, 0, 5, 1, 1);

        boomLoopDelaySpinBox = new QSpinBox(groupBox);
        boomLoopDelaySpinBox->setObjectName(QString::fromUtf8("boomLoopDelaySpinBox"));
        boomLoopDelaySpinBox->setMinimum(1);
        boomLoopDelaySpinBox->setMaximum(1000);
        boomLoopDelaySpinBox->setSingleStep(1);
        boomLoopDelaySpinBox->setValue(25);

        gridLayout_2->addWidget(boomLoopDelaySpinBox, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 4, 1, 1);

        boomLoopToSpinBox = new QSpinBox(groupBox);
        boomLoopToSpinBox->setObjectName(QString::fromUtf8("boomLoopToSpinBox"));

        gridLayout_2->addWidget(boomLoopToSpinBox, 1, 5, 1, 1);

        reverseCheckBox = new QCheckBox(groupBox);
        reverseCheckBox->setObjectName(QString::fromUtf8("reverseCheckBox"));

        gridLayout_2->addWidget(reverseCheckBox, 0, 3, 1, 1);


        horizontalLayout_2->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        applyButton = new QPushButton(centralwidget);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout_3->addWidget(applyButton);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        cfiLabel = new QLabel(centralwidget);
        cfiLabel->setObjectName(QString::fromUtf8("cfiLabel"));

        horizontalLayout_3->addWidget(cfiLabel);

        saveFrameButton = new QPushButton(centralwidget);
        saveFrameButton->setObjectName(QString::fromUtf8("saveFrameButton"));

        horizontalLayout_3->addWidget(saveFrameButton);


        verticalLayout->addLayout(horizontalLayout_3);

        locationHorizontalSlider = new QSlider(centralwidget);
        locationHorizontalSlider->setObjectName(QString::fromUtf8("locationHorizontalSlider"));
        locationHorizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(locationHorizontalSlider);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 641, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        label->setBuddy(videoFileNameLineEdit);
        label_8->setBuddy(savePathLineEdit);
        label_2->setBuddy(scaleSpinBox);
        label_16->setBuddy(gammaDoubleSpinBox);
        label_5->setBuddy(rotateSpinBox);
        label_12->setBuddy(cropTopSpinBox);
        label_13->setBuddy(cropBottomSpinBox);
        label_14->setBuddy(cropLeftSpinBox);
        label_15->setBuddy(cropRightSpinBox);
        label_7->setBuddy(jumpToSpinBox);
        label_11->setBuddy(stepSpinBox);
        label_3->setBuddy(boomLoopFromSpinBox);
        label_6->setBuddy(boomLoopDelaySpinBox);
        label_4->setBuddy(boomLoopToSpinBox);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(videoFileNameLineEdit, openVideoButton);
        QWidget::setTabOrder(openVideoButton, browseButton);
        QWidget::setTabOrder(browseButton, closeVideoButton);
        QWidget::setTabOrder(closeVideoButton, savePathLineEdit);
        QWidget::setTabOrder(savePathLineEdit, savePathSetButton);
        QWidget::setTabOrder(savePathSetButton, scaleSpinBox);
        QWidget::setTabOrder(scaleSpinBox, bilinearRadioBox);
        QWidget::setTabOrder(bilinearRadioBox, bicubicRadioBox);
        QWidget::setTabOrder(bicubicRadioBox, heqCheckBox);
        QWidget::setTabOrder(heqCheckBox, gammaDoubleSpinBox);
        QWidget::setTabOrder(gammaDoubleSpinBox, rotateSpinBox);
        QWidget::setTabOrder(rotateSpinBox, cropTopSpinBox);
        QWidget::setTabOrder(cropTopSpinBox, cropBottomSpinBox);
        QWidget::setTabOrder(cropBottomSpinBox, cropLeftSpinBox);
        QWidget::setTabOrder(cropLeftSpinBox, cropRightSpinBox);
        QWidget::setTabOrder(cropRightSpinBox, jumpToSpinBox);
        QWidget::setTabOrder(jumpToSpinBox, stepSpinBox);
        QWidget::setTabOrder(stepSpinBox, boomLoopEnableCheckBox);
        QWidget::setTabOrder(boomLoopEnableCheckBox, loopCheckBox);
        QWidget::setTabOrder(loopCheckBox, reverseCheckBox);
        QWidget::setTabOrder(reverseCheckBox, boomLoopFromSpinBox);
        QWidget::setTabOrder(boomLoopFromSpinBox, boomLoopDelaySpinBox);
        QWidget::setTabOrder(boomLoopDelaySpinBox, boomLoopToSpinBox);
        QWidget::setTabOrder(boomLoopToSpinBox, applyButton);
        QWidget::setTabOrder(applyButton, saveFrameButton);
        QWidget::setTabOrder(saveFrameButton, locationHorizontalSlider);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Video Master", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Video File: ", nullptr));
        videoFileNameLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter a file path ending with .mp4", nullptr));
        openVideoButton->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        browseButton->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        closeVideoButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Save Path:", nullptr));
        savePathLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter a path without a trailing '/'", nullptr));
        savePathSetButton->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Scale:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Interp:", nullptr));
        bilinearRadioBox->setText(QCoreApplication::translate("MainWindow", "Bilinear", nullptr));
        bicubicRadioBox->setText(QCoreApplication::translate("MainWindow", "Lanczos", nullptr));
        heqCheckBox->setText(QCoreApplication::translate("MainWindow", "Hist. Eq.", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Gamma:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Rotate:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Top:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Bottom:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Left:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Right:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Free Mode", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Jump To:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Step:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Boomerang && Loop", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "From:", nullptr));
        loopCheckBox->setText(QCoreApplication::translate("MainWindow", "Loop", nullptr));
        boomLoopEnableCheckBox->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Delay:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "To:", nullptr));
        reverseCheckBox->setText(QCoreApplication::translate("MainWindow", "Reverse", nullptr));
        applyButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Current Frame Index:", nullptr));
        cfiLabel->setText(QString());
        saveFrameButton->setText(QCoreApplication::translate("MainWindow", "Save Current Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
