#include "VideoThread.h"
#include <QDebug>
#include <iostream>
#include <string>

#define HMID 310
#define VMID 240
#define MAX_MARGIN 50
#define DEAD_BAND 25

const cv::String    WINDOW_NAME("Camera video");
const cv::String    CASCADE_FILE("../../camera/haarcascade_frontalface_default.xml"); 

VideoThread::VideoThread(QObject *parent) : QThread(parent), gc("/dev/ttyUSB0"){}

void VideoThread::run(){
    cv::VideoCapture camera(0);
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

            if(gc.isActive()) {
                if      (detector.facePosition().x > HMID + MAX_MARGIN) gc.writeToUART("x-100\n");
                else if (detector.facePosition().x < HMID - MAX_MARGIN) gc.writeToUART("x 100\n");
                else if (detector.facePosition().x < HMID + DEAD_BAND && 
                         detector.facePosition().x > HMID - DEAD_BAND) gc.writeToUART("x 0\n");
                else    {
                    int val = HMID-detector.facePosition().x;
                    std::string cmd = "x";
                    if(val < 0) {
                        cmd += "-";
                        val *= -1;
                    }
                    else cmd += " ";

                    gc.writeToUART(cmd + std::to_string(val) + "\n");
                }

                if      (detector.facePosition().y > VMID + MAX_MARGIN) gc.writeToUART("y 100\n");
                else if (detector.facePosition().y < VMID - MAX_MARGIN) gc.writeToUART("y-100\n");
                else if (detector.facePosition().y < VMID + DEAD_BAND && 
                         detector.facePosition().y > VMID - DEAD_BAND) gc.writeToUART("y 0\n");
                else    {
                    int val = detector.facePosition().y - VMID;
                    std::string cmd = "y";
                    if(val < 0) {
                        cmd += "-";
                        val *= -1;
                    }
                    else cmd += " ";

                    gc.writeToUART(cmd + std::to_string(val) + "\n");
                }
            }
		}


		emit frameCaptured(&frame);
		//cv::imshow(WINDOW_NAME, frame);
		if (cv::waitKey(25) == 27) break;
	}
}
