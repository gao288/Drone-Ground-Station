#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>
#include "VideoThread.h"
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

private:
    Ui::camera *ui;
};

#endif // CAMERA_H
