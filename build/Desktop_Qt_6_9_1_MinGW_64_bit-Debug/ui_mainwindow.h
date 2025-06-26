/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSplitter *splitter;
    QLabel *labelTitle;
    QLabel *label_2;
    QProgressBar *progressBar;
    QLabel *label_3;
    QListWidget *listWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnScan;
    QPushButton *btnClean;
    QPushButton *btnAbout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(10, 10, 771, 541));
        splitter->setOrientation(Qt::Orientation::Vertical);
        labelTitle = new QLabel(splitter);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        splitter->addWidget(labelTitle);
        label_2 = new QLabel(splitter);
        label_2->setObjectName("label_2");
        splitter->addWidget(label_2);
        progressBar = new QProgressBar(splitter);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        splitter->addWidget(progressBar);
        label_3 = new QLabel(splitter);
        label_3->setObjectName("label_3");
        splitter->addWidget(label_3);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName("listWidget");
        splitter->addWidget(listWidget);
        widget = new QWidget(splitter);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnScan = new QPushButton(widget);
        btnScan->setObjectName("btnScan");

        horizontalLayout->addWidget(btnScan);

        btnClean = new QPushButton(widget);
        btnClean->setObjectName("btnClean");

        horizontalLayout->addWidget(btnClean);

        btnAbout = new QPushButton(widget);
        btnAbout->setObjectName("btnAbout");

        horizontalLayout->addWidget(btnAbout);

        splitter->addWidget(widget);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\347\263\273\347\273\237\345\236\203\345\234\276\346\270\205\347\220\206\345\267\245\345\205\267</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\211\253\346\217\217\350\277\233\345\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\211\253\346\217\217\346\227\245\345\277\227", nullptr));
        btnScan->setText(QCoreApplication::translate("MainWindow", "\346\211\253\346\217\217\345\236\203\345\234\276", nullptr));
        btnClean->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\220\206\345\236\203\345\234\276", nullptr));
        btnAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
