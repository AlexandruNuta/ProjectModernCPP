#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
