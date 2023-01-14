#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QTimer>
#include <QMessageBox>
#include <QErrorMessage>
#include <QWindow>
#include <QPalette>
#include <QPixmap>
#include <QString>
#include <QSize>
#include <QPaintEvent>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_Exit, &QPushButton::clicked, this, &QWidget::close);
    setWindowTitle("Triviador");
    ui->stackedWidget->setCurrentIndex(0);
    ui->passwordField->setEchoMode(QLineEdit::Password);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLoadingPoints()));
    timer->start(150);
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

void MainWindow::updateLoadingPoints()
{
    static int currentPoint = 1;
    if (currentPoint == 1) {
        ui->point1->setVisible(true);
        ui->point2->setVisible(false);
        ui->point3->setVisible(false);
    } else if (currentPoint == 2) {
        ui->point1->setVisible(false);
        ui->point2->setVisible(true);
        ui->point3->setVisible(false);
    } else {
        ui->point1->setVisible(false);
        ui->point2->setVisible(false);
        ui->point3->setVisible(true);
    }
    currentPoint++;
    if (currentPoint > 3) {
        currentPoint = 1;
    }
    update();
}

void MainWindow::on_pushButton_ExitRoom_clicked()
{
    QMessageBox msgBox;

    msgBox.setText("Are you sure you want to exit this room?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    msgBox.setDefaultButton(QMessageBox::No);

    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes) {
        ui->stackedWidget->setCurrentWidget(ui->page_RoomMenu);
    } else {
     }
}

void MainWindow::GenerateMap(int cols, int rows)
{
    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->mapView->setScene(scene);

    for (int i = 0; i < cols; i++)
        for(int j=0; j< rows; j++)
        {
            QPushButton* regionButton = new QPushButton();
            regionButton->setFixedSize(80, 80);
            regionButton->setGeometry(i * 80, j * 80, 80, 80);
            regionButton->setCursor(Qt::PointingHandCursor);
            regionButton->setMouseTracking(true);
            regionButton->setStyleSheet("background-color: lightgray;");
            connect(regionButton, &QPushButton::clicked, this, &MainWindow::on_regionButton_clicked);

            scene->addWidget(regionButton);
        }
}

void MainWindow::on_regionButton_clicked()
{
    int playerNr = 1;
    QPushButton* regionButton = qobject_cast<QPushButton*>(sender());

    if(playerNr==1)
    {
        regionButton->setStyleSheet("background-color: red;");
    }
    else if(playerNr==2)
    {
        regionButton->setStyleSheet("background-color: blue;");
    }
    else if(playerNr==3)
    {
        regionButton->setStyleSheet("background-color: green;");
    }
    else if(playerNr==4)
    {
        regionButton->setStyleSheet("background-color: yellow;");
    }
}
