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
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_SignIn;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_SignUp;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *usernameField;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *passwordField;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_Login;
    QPushButton *pushButton_LoginPage_Back;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QWidget *page_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
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
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_Register;
    QPushButton *pushButton_RegisterPage_Back;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QWidget *page_4;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_10;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_Play;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_Options;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_Exit;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_2;
    QWidget *page_5;
    QLabel *label_8;
    QPushButton *pushButton_OptionsPage_Back;
    QWidget *page_6;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *MultipleAnswerQuestionLabel;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *answerButton1;
    QPushButton *answerButton2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *answerButton3;
    QPushButton *answerButton4;
    QWidget *page_7;
    QLabel *label_9;
    QGroupBox *groupBox_6;
    QLabel *NumericalAnswerQuestionLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *NumericalAnswerField;
    QPushButton *pushButton_SubmitAnswer;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(756, 377);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackedWidget {\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"}\n"
""));
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        gridLayout_3 = new QGridLayout(page_1);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(page_1);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setLayoutDirection(Qt::LeftToRight);
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(true);
        groupBox_2->setCheckable(false);
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(25);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(250, 100, 250, 100);
        pushButton_SignIn = new QPushButton(groupBox_2);
        pushButton_SignIn->setObjectName("pushButton_SignIn");

        horizontalLayout_3->addWidget(pushButton_SignIn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);

        pushButton_SignUp = new QPushButton(groupBox_2);
        pushButton_SignUp->setObjectName("pushButton_SignUp");

        horizontalLayout_3->addWidget(pushButton_SignUp);

        horizontalLayout_3->setStretch(0, 10);
        horizontalLayout_3->setStretch(1, 10);
        horizontalLayout_3->setStretch(2, 10);

        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName("groupBox");
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

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        pushButton_Login = new QPushButton(groupBox);
        pushButton_Login->setObjectName("pushButton_Login");

        horizontalLayout_9->addWidget(pushButton_Login);

        pushButton_LoginPage_Back = new QPushButton(groupBox);
        pushButton_LoginPage_Back->setObjectName("pushButton_LoginPage_Back");

        horizontalLayout_9->addWidget(pushButton_LoginPage_Back);


        verticalLayout_2->addLayout(horizontalLayout_9);


        gridLayout_2->addWidget(groupBox, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 0, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 1, 3, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout = new QGridLayout(page_3);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 1, 4, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 0, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(page_3);
        groupBox_3->setObjectName("groupBox_3");
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

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        pushButton_Register = new QPushButton(groupBox_3);
        pushButton_Register->setObjectName("pushButton_Register");

        horizontalLayout_13->addWidget(pushButton_Register);

        pushButton_RegisterPage_Back = new QPushButton(groupBox_3);
        pushButton_RegisterPage_Back->setObjectName("pushButton_RegisterPage_Back");

        horizontalLayout_13->addWidget(pushButton_RegisterPage_Back);


        verticalLayout_3->addLayout(horizontalLayout_13);


        gridLayout->addWidget(groupBox_3, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 3, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        gridLayout_4 = new QGridLayout(page_4);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(-1, -1, -1, 25);
        groupBox_7 = new QGroupBox(page_4);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setFlat(true);
        verticalLayout_6 = new QVBoxLayout(groupBox_7);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_10);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        pushButton_Play = new QPushButton(groupBox_7);
        pushButton_Play->setObjectName("pushButton_Play");

        verticalLayout_7->addWidget(pushButton_Play);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_13);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_12);

        pushButton_Options = new QPushButton(groupBox_7);
        pushButton_Options->setObjectName("pushButton_Options");

        verticalLayout_7->addWidget(pushButton_Options);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_11);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_14);

        pushButton_Exit = new QPushButton(groupBox_7);
        pushButton_Exit->setObjectName("pushButton_Exit");

        verticalLayout_7->addWidget(pushButton_Exit);


        verticalLayout_6->addLayout(verticalLayout_7);


        gridLayout_4->addWidget(groupBox_7, 3, 1, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_9, 1, 1, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_17, 3, 2, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_8, 4, 1, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_16, 3, 0, 1, 1);

        label_2 = new QLabel(page_4);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 2, 1, 1, 1);

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
        gridLayout_5 = new QGridLayout(page_6);
        gridLayout_5->setObjectName("gridLayout_5");
        groupBox_8 = new QGroupBox(page_6);
        groupBox_8->setObjectName("groupBox_8");
        verticalLayout_9 = new QVBoxLayout(groupBox_8);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(-1, -1, -1, 10);
        groupBox_5 = new QGroupBox(groupBox_8);
        groupBox_5->setObjectName("groupBox_5");
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName("verticalLayout_4");
        MultipleAnswerQuestionLabel = new QLabel(groupBox_5);
        MultipleAnswerQuestionLabel->setObjectName("MultipleAnswerQuestionLabel");
        MultipleAnswerQuestionLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(MultipleAnswerQuestionLabel);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(200);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        answerButton1 = new QPushButton(groupBox_5);
        answerButton1->setObjectName("answerButton1");

        horizontalLayout_7->addWidget(answerButton1);

        answerButton2 = new QPushButton(groupBox_5);
        answerButton2->setObjectName("answerButton2");

        horizontalLayout_7->addWidget(answerButton2);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(200);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        answerButton3 = new QPushButton(groupBox_5);
        answerButton3->setObjectName("answerButton3");

        horizontalLayout_8->addWidget(answerButton3);

        answerButton4 = new QPushButton(groupBox_5);
        answerButton4->setObjectName("answerButton4");

        horizontalLayout_8->addWidget(answerButton4);


        verticalLayout_4->addLayout(horizontalLayout_8);


        verticalLayout_9->addWidget(groupBox_5);


        gridLayout_5->addWidget(groupBox_8, 0, 0, 1, 1);

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
        layoutWidget = new QWidget(page_7);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(310, 170, 101, 54));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        NumericalAnswerField = new QLineEdit(layoutWidget);
        NumericalAnswerField->setObjectName("NumericalAnswerField");

        verticalLayout_5->addWidget(NumericalAnswerField);

        pushButton_SubmitAnswer = new QPushButton(layoutWidget);
        pushButton_SubmitAnswer->setObjectName("pushButton_SubmitAnswer");

        verticalLayout_5->addWidget(pushButton_SubmitAnswer);

        stackedWidget->addWidget(page_7);

        verticalLayout->addWidget(stackedWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 756, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Welcome to Login page!", nullptr));
        pushButton_SignIn->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        pushButton_SignUp->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Username: ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Password:  ", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_LoginPage_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        groupBox_3->setTitle(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Enter a Username: ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Enter a Password:   ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Confirm Password:", nullptr));
        pushButton_Register->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        pushButton_RegisterPage_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        groupBox_7->setTitle(QString());
        pushButton_Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        pushButton_Options->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("MainWindow", "Exit game", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Not Available Yet", nullptr));
        pushButton_OptionsPage_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        groupBox_8->setTitle(QString());
        groupBox_5->setTitle(QString());
        MultipleAnswerQuestionLabel->setText(QCoreApplication::translate("MainWindow", "Question", nullptr));
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
