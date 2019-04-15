#ifndef CAMERA_H
#define CAMERA_H

#include <QCameraInfo>
#include <QMainWindow>
#include <QPushButton>
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

private slots:
    void on_Start_clicked();
    void on_Stop_clicked();
private:
    Ui::camera *ui;


};

#endif // CAMERA_H
