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
    ui->stackedWidget->setCurrentWidget(ui->page_LoginMenu);
    ui->passwordField->setEchoMode(QLineEdit::Password);
    connect(loadingPointsTimer, SIGNAL(timeout()), this, SLOT(updateLoadingPoints())); 
    connect(startMatchTimer, SIGNAL(timeout()), this, SLOT(updateStartMatchTimerLabel()));
    connect(MA_AnsweringTimer, SIGNAL(timeout()), this, SLOT(update_label_MAQuestion_RemainingTime()));
    connect(ShowQuestionResultsTimer, SIGNAL(timeout()), this, SLOT(update_label_QuestionAnsweringResultsRemainingTime()));
    connect(NA_AnsweringTimer, SIGNAL(timeout()), this, SLOT(update_label_NA_QuestionAnsweringRemainingTime()));
    connect(RegionChoosingTimer, SIGNAL(timeout()), this, SLOT(update_label_label_RegionChoosingRemainingTime()));
    ui->label_MatchStarting->setVisible(false);
    ui->label_MatchStartingTime->setVisible(false);
    loadingPointsTimer->start(150);
    GenerateMap(6,4);

    ui->label_ReadyPlayersNumber->setText("3");

    //ui->stackedWidget->setCurrentWidget(ui->page_MatchResults);
    //ShowMatchResults();
    //ShowQuestionResults();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->usernameField->text();
    QString password = ui->passwordField->text();

    if (username == "utilizator" && password == "admin")
    {
        QMessageBox::information(this, "Success", "You have successfully logged in");
        ui->stackedWidget->setCurrentWidget(ui->page_GameMenu);
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

    QString question = "What is the capital of France?";
    QString correctAnswer = "";
    QStringList answers;
    answers.append("Paris");
    answers.append("Madrid");
    answers.append("London");
    answers.append("Rome");

    ui->MultipleAnswerQuestionLabel->setText(question);
    ui->answerButton1->setText(answers.at(0));
    ui->answerButton2->setText(answers.at(1));
    ui->answerButton3->setText(answers.at(2));
    ui->answerButton4->setText(answers.at(3));
}

void MainWindow::Load_NA_Question()
{
    ui->NumericalAnswerQuestionLabel->setText("");

    QString question = "What is the result of 9 multiplied by 8?";
    QString correctAnswer = "72";

    ui->NumericalAnswerQuestionLabel->setText(question);
}

void MainWindow::on_pushButton_SignIn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Login);
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
    ui->stackedWidget->setCurrentWidget(ui->page_Register);
}


void MainWindow::on_pushButton_LoginPage_Back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_LoginMenu);
}


void MainWindow::on_pushButton_RegisterPage_Back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_LoginMenu);
}


void MainWindow::on_pushButton_Options_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Options);
}


void MainWindow::on_pushButton_OptionsPage_Back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_GameMenu);
}


void MainWindow::on_pushButton_Play_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_RoomMenu);
}

void MainWindow::on_pushButton_JoinRoom_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_JoinRoom);
}


void MainWindow::on_pushButton_Join_clicked()
{
    QString room_id = "5043";
    auto introduced_room_id = ui->JoinRoomIDField->text();
    if(introduced_room_id.length()==0)
    {
        QMessageBox::warning(this, "Error", "Please enter the room ID");
    }
    else if(introduced_room_id == room_id)
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
        startMatchTimer->stop();
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
        regionButton->setText("300");
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

void MainWindow::on_pushButton_Profile_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Profile);
}


void MainWindow::on_pushButton_Profile_Back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_GameMenu);
}

void MainWindow::ChangeMatchHistory(QString matchHistory)
{
    ui->label_Matches_History->setText(matchHistory);
}

void MainWindow::ShowMatchResults()
{
    players = 4;
    if(players == 2)
    {
        ui->label_Winner->setText("Winner:   player1");
        ui->label_2ndPlace->setText("2nd Place:   player2");
        ui->label_3rdPlace->setVisible(false);
        ui->label_4thPlace->setVisible(false);
    }

    if(players == 3)
    {
        ui->label_Winner->setText("Winner:   player1");
        ui->label_2ndPlace->setText("2nd Place:   player2");
        ui->label_3rdPlace->setText("3rd Place:   player3");
        ui->label_4thPlace->setVisible(false);
    }

    if(players == 4)
    {
        ui->label_Winner->setText("Winner:   player1");
        ui->label_2ndPlace->setText("2nd Place:   player2");
        ui->label_3rdPlace->setText("3rd Place:   player3");
        ui->label_4thPlace->setText("4th Place:   player4");
    }
}

void MainWindow::ShowQuestionAnsweringResults()
{
    players = 4;

    QString correctAnswer = "Paris";
    QString Player1Answer = "Paris";
    QString Player2Answer = "London";
    QString Player3Answer = "Paris";
    QString Player4Answer = "Rome";

    if(players == 2)
    {
        ui->label_Player1_answer->setText("player1:   " + Player1Answer);
        ui->label_Player2_answer->setText("player2:   " + Player2Answer);
        ui->label_Player3_answer->setVisible(false);
        ui->label_Player4_answer->setVisible(false);
        if(Player1Answer == correctAnswer)
        {
            ui->label_Player1_answer->setStyleSheet("background-color: rgb(170, 255, 0);");
        }
        else
        {
            ui->label_Player1_answer->setStyleSheet("background-color: rgb(255, 77, 17);");
        }
        if(Player2Answer == correctAnswer)
        {
            ui->label_Player2_answer->setStyleSheet("background-color: rgb(170, 255, 0);");
        }
        else
        {
            ui->label_Player2_answer->setStyleSheet("background-color: rgb(255, 77, 17);");
        }
    }

    if(players == 3)
    {
        ui->label_Player1_answer->setText("player1:   " + Player1Answer);
        ui->label_Player2_answer->setText("player2:   " + Player2Answer);
        ui->label_Player3_answer->setText("player3:   " + Player3Answer);
        ui->label_Player4_answer->setVisible(false);
        if(Player1Answer == correctAnswer)
        {
            ui->label_Player1_answer->setStyleSheet("background-color: rgb(170, 255, 0);");
        }
        else
        {
            ui->label_Player1_answer->setStyleSheet("background-color: rgb(255, 77, 17);");
        }
        if(Player2Answer == correctAnswer)
        {
            ui->label_Player2_answer->setStyleSheet("background-color: rgb(170, 255, 0);");
        }
        else
        {
            ui->label_Player2_answer->setStyleSheet("background-color: rgb(255, 77, 17);");
        }
        if(Player3Answer == correctAnswer)
        {
            ui->label_Player3_answer->setStyleSheet("background-color: rgb(170, 255, 0);");
        }
        else
        {
            ui->label_Player3_answer->setStyleSheet("background-color: rgb(255, 77, 17);");
        }
    }

    if(players == 4)
    {
        ui->label_Player1_answer->setText("player1:   " + Player1Answer);
        ui->label_Player2_answer->setText("player2:   " + Player2Answer);
        ui->label_Player3_answer->setText("player3:   " + Player3Answer);
        ui->label_Player4_answer->setText("player4:   " + Player4Answer);
        if(Player1Answer == correctAnswer)
        {
            ui->label_Player1_answer->setStyleSheet("background-color: rgb(170, 255, 0);");
        }
        else
        {
            ui->label_Player1_answer->setStyleSheet("background-color: rgb(255, 77, 17);");
        }
        if(Player2Answer == correctAnswer)
        {
            ui->label_Player2_answer->setStyleSheet("background-color: rgb(170, 255, 0);");
        }
        else
        {
            ui->label_Player2_answer->setStyleSheet("background-color: rgb(255, 77, 17);");
        }
        if(Player3Answer == correctAnswer)
        {
            ui->label_Player3_answer->setStyleSheet("background-color: rgb(170, 255, 0);");
        }
        else
        {
            ui->label_Player3_answer->setStyleSheet("background-color: rgb(255, 77, 17);");
        }
        if(Player4Answer == correctAnswer)
        {
            ui->label_Player4_answer->setStyleSheet("background-color: rgb(170, 255, 0);");
        }
        else
        {
            ui->label_Player4_answer->setStyleSheet("background-color: rgb(255, 77, 17);");
        }
    }
}

void MainWindow::QuestionAnsweringResultsPhase()
{
    ui->stackedWidget->setCurrentWidget(ui->page_QuestionResults);
    ShowQuestionAnsweringResults();

    remainingTime = 8;
    ui->label_QuestionAnsweringResultsRemainingTime->setText(QString("%1").arg(remainingTime));
    ShowQuestionResultsTimer->start(1000);
}

void MainWindow::update_label_QuestionAnsweringResultsRemainingTime()
{
    remainingTime--;
    if (remainingTime < 0)
    {
        ShowQuestionResultsTimer->stop();
        RegionChoosingPhase();
    }
    ui->label_QuestionAnsweringResultsRemainingTime->setText(QString("%1").arg(remainingTime));
}

void MainWindow::EnterMatch()
{
    int playersNumber = 4;
    if(playersReadyNumber == playersNumber)
    {
        StartMatch();
    }
}

void MainWindow::StartMatch()
{
    loadingPointsTimer->stop();
    ui->point1->setVisible(false);
    ui->point2->setVisible(false);
    ui->point3->setVisible(false);

    ui->label_MatchStartingTime->setVisible(true);
    ui->label_MatchStarting->setVisible(true);

    remainingTime = 5;
    ui->label_MatchStartingTime->setText(QString("%1").arg(remainingTime));
    startMatchTimer->start(1000);
}

void MainWindow::updateStartMatchTimerLabel()
{
    remainingTime--;
    if (remainingTime < 0)
    {
        startMatchTimer->stop();
        MA_QuestionAnsweringPhase();
    }
    ui->label_MatchStartingTime->setText(QString("%1").arg(remainingTime));
}

void MainWindow::MA_QuestionAnsweringPhase()
{
    ui->stackedWidget->setCurrentWidget(ui->page_MAQScreen);
    Load_MA_Question();

    remainingTime = 12;
    ui->label_MAQuestion_RemainingTime->setText(QString("%1 seconds").arg(remainingTime));
    MA_AnsweringTimer->start(1000);
}

void MainWindow::update_label_MAQuestion_RemainingTime()
{
    remainingTime--;
    if (remainingTime < 0)
    {
        MA_AnsweringTimer->stop();
        QuestionAnsweringResultsPhase();
    }
    ui->label_MAQuestion_RemainingTime->setText(QString("%1 seconds").arg(remainingTime));
}

void MainWindow::NA_QuestionAnsweringPhase()
{
    ui->stackedWidget->setCurrentWidget(ui->page_NAQScreen);
    Load_NA_Question();

    remainingTime = 12;
    ui->label_NA_QuestionAnsweringRemainingTime->setText(QString("%1 seconds").arg(remainingTime));
    NA_AnsweringTimer->start(1000);
}

void MainWindow::update_label_NA_QuestionAnsweringRemainingTime()
{
    remainingTime--;
    if (remainingTime < 0)
    {
        NA_AnsweringTimer->stop();
        QuestionAnsweringResultsPhase();
    }
    ui->label_NA_QuestionAnsweringRemainingTime->setText(QString("%1 seconds").arg(remainingTime));
}

void MainWindow::on_pushButton_Ready_clicked()
{
    ui->pushButton_Ready->setEnabled(false);
    ui->label_ReadyPlayersNumber->setText("4");
    EnterMatch();
}


void MainWindow::on_answerButton1_clicked()
{
    ui->answerButton1->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.511, cy:0.494318, radius:0.5, fx:0.511, fy:0.494318, stop:0 rgba(57, 109, 36, 255), stop:1 rgba(139, 200, 114, 255));");
    ui->answerButton2->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
    ui->answerButton3->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
    ui->answerButton4->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
}


void MainWindow::on_answerButton2_clicked()
{
    ui->answerButton2->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.511, cy:0.494318, radius:0.5, fx:0.511, fy:0.494318, stop:0 rgba(57, 109, 36, 255), stop:1 rgba(139, 200, 114, 255));");
    ui->answerButton1->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
    ui->answerButton3->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
    ui->answerButton4->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
}


void MainWindow::on_answerButton3_clicked()
{
    ui->answerButton3->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.511, cy:0.494318, radius:0.5, fx:0.511, fy:0.494318, stop:0 rgba(57, 109, 36, 255), stop:1 rgba(139, 200, 114, 255));");
    ui->answerButton1->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
    ui->answerButton2->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
    ui->answerButton4->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
}


void MainWindow::on_answerButton4_clicked()
{
    ui->answerButton4->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.511, cy:0.494318, radius:0.5, fx:0.511, fy:0.494318, stop:0 rgba(57, 109, 36, 255), stop:1 rgba(139, 200, 114, 255));");
    ui->answerButton1->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
    ui->answerButton2->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
    ui->answerButton3->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(179, 171, 171, 255), stop:1 rgba(213, 211, 204, 255));");
}

void MainWindow::RegionChoosingPhase()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Map);

    remainingTime = 8;
    ui->label_RegionChoosingRemainingTime->setText(QString("%1 seconds").arg(remainingTime));
    RegionChoosingTimer->start(1000);
}

void MainWindow::update_label_label_RegionChoosingRemainingTime()
{
    remainingTime--;
    if (remainingTime < 0)
    {
        RegionChoosingTimer->stop();
        NA_QuestionAnsweringPhase();
    }
    ui->label_RegionChoosingRemainingTime->setText(QString("%1 seconds").arg(remainingTime));
}
