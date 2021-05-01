#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QStatusBar>
#include<QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    if(username=="Charishma" && password=="1234")
    {
        QMessageBox::information(this,"Login","Username and password is correct");
        //hide();
        info=new Dialog(this);
        info->show();
        statusBar()->showMessage("App will be killerd within 5 secs",5000);
        statusBar()->setStyleSheet("color:#4A6019");

    }
    else{
    QMessageBox::warning(this,"Login","Username and password is not correct");


    }
}

