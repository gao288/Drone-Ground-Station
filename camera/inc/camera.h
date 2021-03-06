#ifndef CAMERA_H
#define CAMERA_H

#include <QCameraInfo>
#include <QMainWindow>
#include <QPushButton>
#include "VideoThread.h"
#include "GimbalUtil.h"

namespace Ui {
class camera;
}

class camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit camera(QWidget *parent = nullptr);
    ~camera();
    VideoThread *vt;
    void OnFrameCaptured(const cv::Mat*);

private slots:
    void on_Start_clicked();
    void on_Stop_clicked();

    void on_slider1_valueChanged(int value);
    void on_slider2_valueChanged(int value);
    void on_slider3_valueChanged(int value);
    void on_slider4_valueChanged(int value);
    void on_ArmButton_clicked();

    void on_slider1_left_clicked();
    void on_slider2_left_clicked();
    void on_slider3_left_clicked();
    void on_slider4_left_clicked();
    void on_slider1_right_clicked();
    void on_slider2_right_clicked();
    void on_slider3_right_clicked();
    void on_slider4_right_clicked();

    void on_facetrack_clicked();
private:
    Ui::camera *ui;
    GimbalController* gc;

};

#endif // CAMERA_H
