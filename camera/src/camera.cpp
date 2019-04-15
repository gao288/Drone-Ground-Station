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
}

void camera::OnFrameCaptured(const cv::Mat *frame){
    QImage imgIn= QImage((uchar*) frame->data, frame->cols, frame->rows, frame->step, QImage::Format_RGB888);
    imgIn = imgIn.scaled(600,480,Qt::KeepAspectRatio);
    ui->video->setPixmap(QPixmap::fromImage(imgIn.rgbSwapped()));
    
    
}


camera::~camera()
{
    delete ui;
}


void camera::on_Start_clicked(){
    vt = new VideoThread(camera::ui->AvailableCameras->currentIndex(),this);
    connect(vt, &VideoThread::frameCaptured,this,&camera::OnFrameCaptured);
    vt->start();
}
void camera::on_Stop_clicked(){
    vt->terminate();
}

