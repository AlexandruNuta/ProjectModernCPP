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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QWidget *page_1;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_SignIn;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_SignUp;
    QWidget *page_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *usernameField;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *passwordField;
    QPushButton *pushButton_Login;
    QPushButton *pushButton_LoginPage_Back;
    QWidget *page_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *UsernameRegisterField;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *PasswordRegisterField;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *ConfirmPasswordField;
    QPushButton *pushButton_Register;
    QPushButton *pushButton_RegisterPage_Back;
    QWidget *page_4;
    QLabel *label_2;
    QPushButton *pushButton_Play;
    QPushButton *pushButton_Options;
    QPushButton *pushButton_Exit;
    QWidget *page_5;
    QLabel *label_8;
    QPushButton *pushButton_OptionsPage_Back;
    QWidget *page_6;
    QLabel *label;
    QGroupBox *groupBox_4;
    QLabel *MultipleAnswerQuestionLabel;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *answerButton1;
    QSpacerItem *verticalSpacer_2;
    QPushButton *answerButton2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *answerButton3;
    QSpacerItem *verticalSpacer_3;
    QPushButton *answerButton4;
    QWidget *page_7;
    QLabel *label_9;
    QGroupBox *groupBox_6;
    QLabel *NumericalAnswerQuestionLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *NumericalAnswerField;
    QPushButton *pushButton_SubmitAnswer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(753, 366);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        groupBox_2 = new QGroupBox(page_1);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(210, 60, 311, 191));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_SignIn = new QPushButton(groupBox_2);
        pushButton_SignIn->setObjectName("pushButton_SignIn");

        horizontalLayout_3->addWidget(pushButton_SignIn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);

        pushButton_SignUp = new QPushButton(groupBox_2);
        pushButton_SignUp->setObjectName("pushButton_SignUp");

        horizontalLayout_3->addWidget(pushButton_SignUp);

        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(230, 60, 271, 181));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        usernameField = new QLineEdit(groupBox);
        usernameField->setObjectName("usernameField");

        horizontalLayout->addWidget(usernameField);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        passwordField = new QLineEdit(groupBox);
        passwordField->setObjectName("passwordField");

        horizontalLayout_2->addWidget(passwordField);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton_Login = new QPushButton(groupBox);
        pushButton_Login->setObjectName("pushButton_Login");

        verticalLayout_2->addWidget(pushButton_Login);

        pushButton_LoginPage_Back = new QPushButton(page_2);
        pushButton_LoginPage_Back->setObjectName("pushButton_LoginPage_Back");
        pushButton_LoginPage_Back->setGeometry(QRect(30, 20, 75, 24));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        groupBox_3 = new QGroupBox(page_3);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(200, 40, 331, 241));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        UsernameRegisterField = new QLineEdit(groupBox_3);
        UsernameRegisterField->setObjectName("UsernameRegisterField");

        horizontalLayout_4->addWidget(UsernameRegisterField);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        PasswordRegisterField = new QLineEdit(groupBox_3);
        PasswordRegisterField->setObjectName("PasswordRegisterField");

        horizontalLayout_5->addWidget(PasswordRegisterField);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        ConfirmPasswordField = new QLineEdit(groupBox_3);
        ConfirmPasswordField->setObjectName("ConfirmPasswordField");

        horizontalLayout_6->addWidget(ConfirmPasswordField);


        verticalLayout_3->addLayout(horizontalLayout_6);

        pushButton_Register = new QPushButton(groupBox_3);
        pushButton_Register->setObjectName("pushButton_Register");

        verticalLayout_3->addWidget(pushButton_Register);

        pushButton_RegisterPage_Back = new QPushButton(page_3);
        pushButton_RegisterPage_Back->setObjectName("pushButton_RegisterPage_Back");
        pushButton_RegisterPage_Back->setGeometry(QRect(30, 20, 75, 24));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        label_2 = new QLabel(page_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 20, 49, 16));
        pushButton_Play = new QPushButton(page_4);
        pushButton_Play->setObjectName("pushButton_Play");
        pushButton_Play->setGeometry(QRect(290, 80, 141, 24));
        pushButton_Options = new QPushButton(page_4);
        pushButton_Options->setObjectName("pushButton_Options");
        pushButton_Options->setGeometry(QRect(290, 130, 141, 24));
        pushButton_Exit = new QPushButton(page_4);
        pushButton_Exit->setObjectName("pushButton_Exit");
        pushButton_Exit->setGeometry(QRect(290, 180, 141, 24));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        label_8 = new QLabel(page_5);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(330, 70, 101, 16));
        pushButton_OptionsPage_Back = new QPushButton(page_5);
        pushButton_OptionsPage_Back->setObjectName("pushButton_OptionsPage_Back");
        pushButton_OptionsPage_Back->setGeometry(QRect(30, 20, 75, 24));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        label = new QLabel(page_6);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 20, 49, 16));
        groupBox_4 = new QGroupBox(page_6);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(40, 40, 681, 61));
        MultipleAnswerQuestionLabel = new QLabel(groupBox_4);
        MultipleAnswerQuestionLabel->setObjectName("MultipleAnswerQuestionLabel");
        MultipleAnswerQuestionLabel->setGeometry(QRect(10, 10, 661, 41));
        groupBox_5 = new QGroupBox(page_6);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(40, 140, 681, 171));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        answerButton1 = new QPushButton(groupBox_5);
        answerButton1->setObjectName("answerButton1");

        horizontalLayout_7->addWidget(answerButton1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_7->addItem(verticalSpacer_2);

        answerButton2 = new QPushButton(groupBox_5);
        answerButton2->setObjectName("answerButton2");

        horizontalLayout_7->addWidget(answerButton2);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        answerButton3 = new QPushButton(groupBox_5);
        answerButton3->setObjectName("answerButton3");

        horizontalLayout_8->addWidget(answerButton3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_8->addItem(verticalSpacer_3);

        answerButton4 = new QPushButton(groupBox_5);
        answerButton4->setObjectName("answerButton4");

        horizontalLayout_8->addWidget(answerButton4);


        verticalLayout_4->addLayout(horizontalLayout_8);

        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        label_9 = new QLabel(page_7);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(350, 20, 49, 16));
        groupBox_6 = new QGroupBox(page_7);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(40, 40, 681, 61));
        NumericalAnswerQuestionLabel = new QLabel(groupBox_6);
        NumericalAnswerQuestionLabel->setObjectName("NumericalAnswerQuestionLabel");
        NumericalAnswerQuestionLabel->setGeometry(QRect(10, 10, 661, 41));
        widget = new QWidget(page_7);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(310, 170, 101, 51));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        NumericalAnswerField = new QLineEdit(widget);
        NumericalAnswerField->setObjectName("NumericalAnswerField");

        verticalLayout_5->addWidget(NumericalAnswerField);

        pushButton_SubmitAnswer = new QPushButton(widget);
        pushButton_SubmitAnswer->setObjectName("pushButton_SubmitAnswer");

        verticalLayout_5->addWidget(pushButton_SubmitAnswer);

        stackedWidget->addWidget(page_7);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 753, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Welcome to Login page!", nullptr));
        pushButton_SignIn->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        pushButton_SignUp->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "LogIn", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Username: ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Password:  ", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_LoginPage_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        groupBox_3->setTitle(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Enter a Username: ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Enter a Password:  ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Confirm Password:", nullptr));
        pushButton_Register->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        pushButton_RegisterPage_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        pushButton_Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        pushButton_Options->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("MainWindow", "Exit game", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Not Available Yet", nullptr));
        pushButton_OptionsPage_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "page 6", nullptr));
        groupBox_4->setTitle(QString());
        MultipleAnswerQuestionLabel->setText(QCoreApplication::translate("MainWindow", "Question", nullptr));
        groupBox_5->setTitle(QString());
        answerButton1->setText(QCoreApplication::translate("MainWindow", "answer1", nullptr));
        answerButton2->setText(QCoreApplication::translate("MainWindow", "answer2", nullptr));
        answerButton3->setText(QCoreApplication::translate("MainWindow", "answer3", nullptr));
        answerButton4->setText(QCoreApplication::translate("MainWindow", "answer4", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Page 7", nullptr));
        groupBox_6->setTitle(QString());
        NumericalAnswerQuestionLabel->setText(QCoreApplication::translate("MainWindow", "Question", nullptr));
        pushButton_SubmitAnswer->setText(QCoreApplication::translate("MainWindow", "Submit answer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
