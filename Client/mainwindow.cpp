#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QErrorMessage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_Exit, &QPushButton::clicked, this, &QWidget::close);
    setWindowTitle("Triviador");
    ui->stackedWidget->setCurrentIndex(0);
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

