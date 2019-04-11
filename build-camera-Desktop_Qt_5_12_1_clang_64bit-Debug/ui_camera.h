/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camera
{
public:
    QWidget *centralWidget;
    QLabel *video;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *camera)
    {
        if (camera->objectName().isEmpty())
            camera->setObjectName(QString::fromUtf8("camera"));
        camera->resize(400, 300);
        centralWidget = new QWidget(camera);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        video = new QLabel(centralWidget);
        video->setObjectName(QString::fromUtf8("video"));
        video->setGeometry(QRect(20, 10, 361, 221));
        camera->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(camera);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        camera->setMenuBar(menuBar);
        mainToolBar = new QToolBar(camera);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        camera->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(camera);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        camera->setStatusBar(statusBar);

        retranslateUi(camera);

        QMetaObject::connectSlotsByName(camera);
    } // setupUi

    void retranslateUi(QMainWindow *camera)
    {
        camera->setWindowTitle(QApplication::translate("camera", "camera", nullptr));
        video->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class camera: public Ui_camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
