#include "../inc/VideoThread.h"
#include <QDebug>
#include <iostream>
#include <string>


const cv::String    WINDOW_NAME("Camera video");
const cv::String    CASCADE_FILE("../../camera/haarcascade_frontalface_default.xml"); 

VideoThread::VideoThread(QObject *parent) : QThread(parent), gc("/dev/ttyUSB0"){}

void VideoThread::run(){
    cv::VideoCapture camera(1);
	//cv::VideoCapture camera("D:\\video.mp4");
    
	if (!camera.isOpened()) {
		fprintf(stderr, "Error getting camera...\n");
		exit(1);
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

		//printf("Time per frame: %3.3f\tFPS: %3.3f\n", time_per_frame, fps);

		if (detector.isFaceFound())
		{
			cv::rectangle(frame, detector.face(), cv::Scalar(255, 0, 0));
            cv::Point facePos = detector.facePosition();
			cv::circle(frame, facePos, 30, cv::Scalar(0, 255, 0));

            gc.updateFace(facePos.x, facePos.y);
		}
        else {
            gc.updateFace(0, 0);
        }


		emit frameCaptured(&frame);
		if (cv::waitKey(25) == 27) break;
	}
}
