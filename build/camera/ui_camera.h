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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QSlider *slider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
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
        slider = new QSlider(centralWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(760, 340, 161, 31));
        slider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(760, 370, 160, 22));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(centralWidget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(760, 400, 160, 22));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_4 = new QSlider(centralWidget);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(760, 430, 160, 22));
        horizontalSlider_4->setOrientation(Qt::Horizontal);
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
    } // retranslateUi

};

namespace Ui {
    class camera: public Ui_camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
