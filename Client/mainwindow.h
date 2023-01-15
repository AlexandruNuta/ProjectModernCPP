#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMouseEvent>

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

    void Load_MA_Question();

    void Load_NA_Question();

    void on_pushButton_SubmitAnswer_clicked();   

    void on_pushButton_JoinRoom_clicked();

    void on_pushButton_Join_clicked();

    void on_pushButton_CreateRoom_clicked();

    void on_pushButton_Create_clicked();

    void on_pushButton_CreateRoomBack_clicked();

    void on_pushButton_JoinRoomBack_clicked();

    void on_pushButton_RoomBack_clicked();

    void on_pushButton_Fullscreen_clicked();

    void on_pushButton_Windowed_clicked();

    void something();

private:
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H
