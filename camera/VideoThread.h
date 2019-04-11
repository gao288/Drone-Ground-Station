
#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include <QThread>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/videoio.hpp"
#include "VideoFaceDetector.h"
#include "GimbalUtil.h"

 
class VideoThread : public QThread
{
    Q_OBJECT

    GimbalController gc;
public:
    explicit VideoThread(QObject *parent = 0);
    void run();
 
signals:
    void frameCaptured(cv::Mat*);

};
#endif
