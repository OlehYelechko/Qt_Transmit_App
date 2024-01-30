#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    COMPORT = new QSerialPort();
    COMPORT->setPortName("ttyACM0");
    COMPORT->setBaudRate(QSerialPort::BaudRate::Baud115200);
    COMPORT->setParity(QSerialPort::Parity::NoParity);
    COMPORT->setDataBits(QSerialPort::DataBits::Data8);
    COMPORT->setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    COMPORT->open(QIODevice::ReadWrite);
    if(COMPORT->isOpen())
    {
        qDebug() << "Serial port is connected";
    }
    else
    {
        qDebug() << "Serial port is closed";
        qDebug() << COMPORT->error();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_On_clicked()
{
    if(COMPORT->isOpen())
    {
        COMPORT->write("1");
    }
}


void MainWindow::on_Off_clicked()
{
    if(COMPORT->isOpen())
    {
        COMPORT->write("0");
    }
}

