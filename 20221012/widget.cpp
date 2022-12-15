#include "widget.h"
#include "ui_widget.h"
#include "mycontroll.h"
#include "myqthread.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFont ft;
    ft.setPointSize(10);
    ui->label->setFont(ft);
    ui->label->setAutoFillBackground(true);
    ui->label->setText("2022.10.12\n\nQt线程：\n1、采用moveToThread方式\n2、继承自QThread,override run方法");

    myctl = new MyControl();

    qDebug()<<"widget-->, my thread id is "<<QThread::currentThreadId();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    myctl->statrWork0();
    ui->pushButton_2->setEnabled(false);
}

void Widget::on_pushButton_clicked()
{
    Myqthread * mt = new Myqthread();
    mt->start();
    ui->pushButton->setEnabled(false);
}
