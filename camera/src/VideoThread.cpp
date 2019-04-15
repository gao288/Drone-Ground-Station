#include "../inc/VideoThread.h"
#include <QDebug>
#include <iostream>
#include <string>


const cv::String    WINDOW_NAME("Camera video");
const cv::String    CASCADE_FILE("../../camera/haarcascade_frontalface_default.xml"); 

VideoThread::VideoThread( int id,QObject *parent, GimbalController* gc) : QThread(parent), gc(gc), Camera_id(id){}

void VideoThread::run(){
    cv::VideoCapture camera(VideoThread::Camera_id);
	//cv::VideoCapture camera("D:\\video.mp4");
    
	if (!camera.isOpened()) {
		//fprintf(stderr, "Error getting camera...\n");
		//exit(1);
		this->terminate();
		return;
	}

	//cv::namedWindow(WINDOW_NAME, cv::WINDOW_KEEPRATIO | cv::WINDOW_AUTOSIZE);

	VideoFaceDetector detector(CASCADE_FILE, camera);
	cv::Mat frame;
	double fps = 0, time_per_frame;
	while (true)
	{
		auto start = cv::getCPUTickCount();
		detector >> frame;
		auto end = cv::getCPUTickCount();

		time_per_frame = (end - start) / cv::getTickFrequency();
		fps = (15 * fps + (1 / time_per_frame)) / 16;

		if (detector.isFaceFound())
		{
			cv::rectangle(frame, detector.face(), cv::Scalar(255, 0, 0));
            cv::Point facePos = detector.facePosition();
			cv::circle(frame, facePos, 30, cv::Scalar(0, 255, 0));
            gc->updateFace(facePos.x, facePos.y);
		}
        else {
            gc->updateFace(320, 240);
        }

		emit frameCaptured(&frame);
		if (cv::waitKey(25) == 27) break;
	}
}
