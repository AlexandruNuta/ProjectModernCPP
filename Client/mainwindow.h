#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <vector>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_SignIn_clicked();

    void on_pushButton_Register_clicked();

    void on_pushButton_SignUp_clicked();

    void on_pushButton_LoginPage_Back_clicked();

    void on_pushButton_RegisterPage_Back_clicked();

    void on_pushButton_Options_clicked();

    void on_pushButton_OptionsPage_Back_clicked();

    void on_pushButton_Play_clicked(); 

    void on_pushButton_JoinRoom_clicked();

    void on_pushButton_Join_clicked();

    void on_pushButton_CreateRoom_clicked();

    void on_pushButton_Create_clicked();

    void on_pushButton_CreateRoomBack_clicked();

    void on_pushButton_JoinRoomBack_clicked();

    void on_pushButton_RoomBack_clicked();

    void on_pushButton_Fullscreen_clicked();

    void on_pushButton_Windowed_clicked();

    void updateLoadingPoints();

    void on_pushButton_ExitRoom_clicked();

    void on_regionButton_clicked();

    void on_pushButton_Profile_clicked();

    void on_pushButton_Profile_Back_clicked();

    void on_pushButton_Ready_clicked();

    void updateStartMatchTimerLabel();

    void update_label_MAQuestion_RemainingTime();

    void update_label_NA_QuestionAnsweringRemainingTime();

    void update_label_QuestionAnsweringResultsRemainingTime();

    void on_answerButton1_clicked();

    void on_answerButton2_clicked();

    void on_answerButton3_clicked();

    void on_answerButton4_clicked();

    void update_label_label_RegionChoosingRemainingTime();

private:
    Ui::MainWindow *ui;

public:
    void GenerateMap(int cols, int rows);
    void ChangeMatchHistory(QString matchHistory);
    void ShowMatchResults();
    void EnterMatch();
    void StartMatch();
    void MA_QuestionAnsweringPhase();
    void NA_QuestionAnsweringPhase();
    void Load_MA_Question();
    void Load_NA_Question();
    void QuestionAnsweringResultsPhase();
    void ShowQuestionAnsweringResults();
    void RegionChoosingPhase();

private:
    QTimer* loadingPointsTimer = new QTimer(this);
    QTimer* startMatchTimer = new QTimer(this);
    QTimer* MA_AnsweringTimer = new QTimer(this);
    QTimer* NA_AnsweringTimer = new QTimer(this);
    QTimer* ShowQuestionResultsTimer = new QTimer(this);
    QTimer* RegionChoosingTimer = new QTimer(this);
    int remainingTime;
    int playersReadyNumber = 4;
    int players;
};

#endif // MAINWINDOW_H
