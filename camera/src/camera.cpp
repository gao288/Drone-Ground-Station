#include "../inc/camera.h"
#include "ui_camera.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


camera::camera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::camera),
    gc(nullptr)
{
    ui->setupUi(this);
    
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    int count = 0;
    foreach (const QCameraInfo &cameraInfo, cameras) {
        // if (cameraInfo.deviceName() == "mycamera")
        //     camera = new QCamera(cameraInfo);
       std::cout<<cameraInfo.deviceName().toStdString()<<std::endl;
       ui->AvailableCameras->addItem(QString::number(count++));
       
    }
    //QPushButton *Start = new QPushButton(this);
    //QObject::connect(ui->Start, SIGNAL(clicked()),this, SLOT(on_Start_clicked));
    
    // TODO: add a box  to select usb source
    gc = new GimbalController("/dev/ttyUSB0");
}

void camera::OnFrameCaptured(const cv::Mat *frame){
    QImage imgIn= QImage((uchar*) frame->data, frame->cols, frame->rows, frame->step, QImage::Format_RGB888);
    imgIn = imgIn.scaled(600,480,Qt::KeepAspectRatio);
    ui->video->setPixmap(QPixmap::fromImage(imgIn.rgbSwapped()));
}


camera::~camera(){
    delete ui;
}


void camera::on_Start_clicked(){
    vt = new VideoThread(camera::ui->AvailableCameras->currentIndex(), this, gc);
    connect(vt, &VideoThread::frameCaptured,this,&camera::OnFrameCaptured);
    vt->start();
}


void camera::on_Stop_clicked(){
    vt->terminate();
}



void camera::on_slider1_valueChanged(int value)
{
    std::cout<<value<<std::endl;
}
void camera::on_slider1_left_clicked(){

    camera::ui->slider1->setValue(ui->slider1->value() - 1);
}
void camera::on_slider2_left_clicked(){
    
    camera::ui->slider2->setValue(ui->slider2->value() - 1);
}
void camera::on_slider3_left_clicked(){
    
    camera::ui->slider3->setValue(ui->slider3->value() - 1);
}
void camera::on_slider4_left_clicked(){
    
    camera::ui->slider4->setValue(ui->slider4->value() - 1);
}
void camera::on_slider1_right_clicked(){

    camera::ui->slider1->setValue(ui->slider1->value() + 1);
}
void camera::on_slider2_right_clicked(){
 
    camera::ui->slider2->setValue(ui->slider2->value() + 1);
}
void camera::on_slider3_right_clicked(){
 
    camera::ui->slider3->setValue(ui->slider3->value() + 1);
}
void camera::on_slider4_right_clicked(){
    
    camera::ui->slider4->setValue(ui->slider4->value() + 1);
}

void camera::on_ArmButton_clicked()
{
    camera::ui->slider1->setValue(10);
}


void camera::on_facetrack_clicked()
{

}