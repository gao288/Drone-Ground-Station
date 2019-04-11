#include "../inc/camera.h"
#include "ui_camera.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>




camera::camera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::camera)
{
    ui->setupUi(this);

    vt = new VideoThread(this);
    connect(vt, &VideoThread::frameCaptured,this,&camera::OnFrameCaptured);

    vt->start();
}

void camera::OnFrameCaptured(const cv::Mat *frame){
    QImage imgIn= QImage((uchar*) frame->data, frame->cols, frame->rows, frame->step, QImage::Format_RGB888);
    imgIn = imgIn.scaled(600,480,Qt::KeepAspectRatio);
    ui->video->setPixmap(QPixmap::fromImage(imgIn));
    // std::cout << "HelloWorld"<<std::endl;

    // QImage myImage;
    // myImage.load("/Users/MeatBall/Desktop/477/DroneGround/camera/image/1.jpg");
    // ui->video->setPixmap(QPixmap::fromImage(myImage));

}

camera::~camera()
{
    delete ui;
}
