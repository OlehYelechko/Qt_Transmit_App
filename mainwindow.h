#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>
#include <QMessageBox>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_On_clicked();

    void on_Off_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *COMPORT;
};
#endif // MAINWINDOW_H
