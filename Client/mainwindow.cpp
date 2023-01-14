#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QErrorMessage>
#include <QWindow>
#include <QPalette>
#include <QPixmap>
#include <QString>
#include <QSize>
#include <QPaintEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_Exit, &QPushButton::clicked, this, &QWidget::close);
    setWindowTitle("Triviador");
    ui->stackedWidget->setCurrentIndex(0);
    ui->passwordField->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->usernameField->text();
    QString password = ui->passwordField->text();

    if (username == "ok" && password == "admin")
    {
        QMessageBox::information(this, "Success", "You have successfully logged in");
        ui->stackedWidget->setCurrentIndex(3);
    }
    else
    {
//        QLabel *errorLabel = new QLabel;
//        errorLabel->setText("Incorrect username or password");
//        errorLabel->setVisible(true);
        QMessageBox::information(this, "Login Error", "Incorrect username or password");
        ui->passwordField->clear();
    }
}

void MainWindow::Load_MA_Question()
{
    ui->MultipleAnswerQuestionLabel->setText("");
    ui->answerButton1->setText("");
    ui->answerButton2->setText("");
    ui->answerButton3->setText("");
    ui->answerButton4->setText("");

    QString question = "";
    QString correctAnswer = "";
    QStringList answers;
    answers.append("");
    answers.append("");
    answers.append("");
    answers.append("");

    ui->MultipleAnswerQuestionLabel->setText(question);
    ui->answerButton1->setText(answers.at(0));
    ui->answerButton2->setText(answers.at(1));
    ui->answerButton3->setText(answers.at(2));
    ui->answerButton4->setText(answers.at(3));
}

void MainWindow::Load_NA_Question()
{
    ui->NumericalAnswerQuestionLabel->setText("");

    QString question = "";
    QString correctAnswer = "1";

    ui->NumericalAnswerQuestionLabel->setText(question);
}

void MainWindow::on_pushButton_SignIn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_Register_clicked()
{
    QString username = ui->UsernameRegisterField->text();
    QString password = ui->PasswordRegisterField->text();
    QString confirmPassword = ui->ConfirmPasswordField->text();

    if (password == confirmPassword)
    {
        QMessageBox::information(this, "Success", "You have successfully signed up!");
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        QMessageBox::warning(this, "Error", "The passwords do not match");
    }
}


void MainWindow::on_pushButton_SignUp_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_LoginPage_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_RegisterPage_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_Options_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_OptionsPage_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_Play_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_SubmitAnswer_clicked()
{
    int correctAnswer;
    bool ok;
    int answer = ui->NumericalAnswerField->text().toInt(&ok);
    if (ok)
    {
        //
    }
    else
    {
        QMessageBox::warning(this, "Error", "Please enter a valid answer");
    }
}


void MainWindow::on_pushButton_JoinRoom_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_JoinRoom);
}


void MainWindow::on_pushButton_Join_clicked()
{
    auto room_id = ui->JoinRoomIDField->text();
    if(room_id.length()==0)
    {
        QMessageBox::warning(this, "Error", "Please enter the room ID");
    }
    else if(true)
    {
        ui->stackedWidget->setCurrentWidget(ui->page_CreatedRoom);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Invalid room ID");
    }
}


void MainWindow::on_pushButton_CreateRoom_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_CreateRoom);
}


void MainWindow::on_pushButton_Create_clicked()
{
    auto entered_nr_players = ui->EnterPlayerNumberField->text().toInt();
    if(entered_nr_players==2 || entered_nr_players==3 || entered_nr_players==4)
    {
        ui->stackedWidget->setCurrentWidget(ui->page_CreatedRoom);
    }
    else
    {
        QMessageBox::warning(this, "Error", "The number of players should be 2, 3 or 4");
    }
}


void MainWindow::on_pushButton_CreateRoomBack_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_RoomMenu);
}


void MainWindow::on_pushButton_JoinRoomBack_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_RoomMenu);
}


void MainWindow::on_pushButton_RoomBack_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_GameMenu);
}

void MainWindow::on_pushButton_Fullscreen_clicked()
{
    this->showFullScreen();
}


void MainWindow::on_pushButton_Windowed_clicked()
{
    this->showMaximized();
}
