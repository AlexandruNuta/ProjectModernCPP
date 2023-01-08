/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_3;
    QPushButton *pushButton_goto_page_2;
    QWidget *page_2;
    QLabel *label_2;
    QPushButton *pushButton_goto_page_3;
    QWidget *page_3;
    QLabel *label;
    QPushButton *pushButton_goto_page_1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(757, 365);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(350, 20, 49, 16));
        pushButton_goto_page_2 = new QPushButton(page);
        pushButton_goto_page_2->setObjectName("pushButton_goto_page_2");
        pushButton_goto_page_2->setGeometry(QRect(20, 10, 75, 24));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 20, 49, 16));
        pushButton_goto_page_3 = new QPushButton(page_2);
        pushButton_goto_page_3->setObjectName("pushButton_goto_page_3");
        pushButton_goto_page_3->setGeometry(QRect(30, 20, 75, 24));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label = new QLabel(page_3);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 20, 49, 16));
        pushButton_goto_page_1 = new QPushButton(page_3);
        pushButton_goto_page_1->setObjectName("pushButton_goto_page_1");
        pushButton_goto_page_1->setGeometry(QRect(30, 10, 75, 24));
        stackedWidget->addWidget(page_3);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 757, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "page 1", nullptr));
        pushButton_goto_page_2->setText(QCoreApplication::translate("MainWindow", "Go to page 2", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "page 2", nullptr));
        pushButton_goto_page_3->setText(QCoreApplication::translate("MainWindow", "Go to page 3", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "page 3", nullptr));
        pushButton_goto_page_1->setText(QCoreApplication::translate("MainWindow", "Go to page 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
