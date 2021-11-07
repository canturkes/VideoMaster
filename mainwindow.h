#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browseButton_clicked();

    void on_openVideoButton_clicked();

    void on_closeVideoButton_clicked();

    void on_applyButton_clicked();

    void on_savePathSetButton_clicked();

    void on_saveFrameButton_clicked();

    void on_videoFileNameLineEdit_textChanged(const QString &arg1);

    void on_stepSpinBox_valueChanged(int arg1);

    void on_scaleSpinBox_valueChanged(double arg1);

    void on_heqCheckBox_clicked(bool checked);

    void on_rotateSpinBox_valueChanged(int arg1);

    void on_bilinearRadioBox_clicked(bool checked);

    void on_bicubicRadioBox_clicked(bool checked);

    void on_boomLoopDelaySpinBox_valueChanged(int arg1);

    void on_gammaDoubleSpinBox_valueChanged(double arg1);

    void on_cropTopSpinBox_valueChanged(int arg1);

    void on_cropBottomSpinBox_valueChanged(int arg1);

    void on_cropLeftSpinBox_valueChanged(int arg1);

    void on_cropRightSpinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
