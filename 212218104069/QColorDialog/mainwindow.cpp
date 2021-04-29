#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColorDialog>
#include<QDebug>
#include<QColor>
#include<QPalette>
#include<QFontDialog>
#include<QFont>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_TextColor_pushButton_clicked()
{
    QPalette palette=ui->label->palette();
    QColor color=palette.color(QPalette::WindowText);
    QColor chosencolor=QColorDialog::getColor(color,this,"choose text color");
    if(chosencolor.isValid())
    {
        palette.setColor(QPalette::WindowText,chosencolor);
        ui->label->setPalette(palette);
        qDebug()<<"User chosen a color";
    }
}

void MainWindow::on_BackgroundColor_pushButton_clicked()
{
    QPalette palette=ui->label->palette();
    QColor color=palette.color(QPalette::Window);
    QColor chosencolor=QColorDialog::getColor(color,this,"choose text color");
    if(chosencolor.isValid())
    {
        palette.setColor(QPalette::Window,chosencolor);
        ui->label->setPalette(palette);
        qDebug()<<"User chosen a color";
    }
}

void MainWindow::on_Font_pushButton_clicked()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,QFont("Times New Roman",10),this);
    if(ok)
    {
        ui->label->setFont(font);
    }
    else{
        QMessageBox::information(this,"Message","user didn't chosen any font");
    }
}
