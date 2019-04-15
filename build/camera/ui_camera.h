/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camera
{
public:
    QWidget *centralWidget;
    QLabel *video;
    QCheckBox *AutoMode;
    QSlider *slider1;
    QSlider *slider2;
    QSlider *slider3;
    QSlider *slider4;
    QComboBox *AvailableCameras;
    QPushButton *Start;
    QPushButton *Stop;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *camera)
    {
        if (camera->objectName().isEmpty())
            camera->setObjectName(QString::fromUtf8("camera"));
        camera->resize(974, 540);
        centralWidget = new QWidget(camera);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        video = new QLabel(centralWidget);
        video->setObjectName(QString::fromUtf8("video"));
        video->setEnabled(true);
        video->setGeometry(QRect(40, 40, 651, 401));
        AutoMode = new QCheckBox(centralWidget);
        AutoMode->setObjectName(QString::fromUtf8("AutoMode"));
        AutoMode->setGeometry(QRect(761, 305, 85, 20));
        slider1 = new QSlider(centralWidget);
        slider1->setObjectName(QString::fromUtf8("slider1"));
        slider1->setGeometry(QRect(760, 340, 161, 31));
        slider1->setOrientation(Qt::Horizontal);
        slider2 = new QSlider(centralWidget);
        slider2->setObjectName(QString::fromUtf8("slider2"));
        slider2->setGeometry(QRect(760, 370, 160, 31));
        slider2->setOrientation(Qt::Horizontal);
        slider3 = new QSlider(centralWidget);
        slider3->setObjectName(QString::fromUtf8("slider3"));
        slider3->setGeometry(QRect(760, 400, 160, 31));
        slider3->setOrientation(Qt::Horizontal);
        slider4 = new QSlider(centralWidget);
        slider4->setObjectName(QString::fromUtf8("slider4"));
        slider4->setGeometry(QRect(760, 430, 160, 31));
        slider4->setOrientation(Qt::Horizontal);
        AvailableCameras = new QComboBox(centralWidget);
        AvailableCameras->setObjectName(QString::fromUtf8("AvailableCameras"));
        AvailableCameras->setGeometry(QRect(760, 224, 161, 32));
        Start = new QPushButton(centralWidget);
        Start->setObjectName(QString::fromUtf8("Start"));
        Start->setGeometry(QRect(759, 261, 81, 31));
        Stop = new QPushButton(centralWidget);
        Stop->setObjectName(QString::fromUtf8("Stop"));
        Stop->setGeometry(QRect(840, 261, 81, 31));
        camera->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(camera);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 974, 22));
        camera->setMenuBar(menuBar);
        mainToolBar = new QToolBar(camera);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        camera->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(camera);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        camera->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        video->setBuddy(video);
#endif // QT_NO_SHORTCUT

        retranslateUi(camera);

        QMetaObject::connectSlotsByName(camera);
    } // setupUi

    void retranslateUi(QMainWindow *camera)
    {
        camera->setWindowTitle(QApplication::translate("camera", "camera", nullptr));
        video->setText(QString());
        AutoMode->setText(QApplication::translate("camera", "AutoMode", nullptr));
        Start->setText(QApplication::translate("camera", "Start", nullptr));
        Stop->setText(QApplication::translate("camera", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class camera: public Ui_camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
