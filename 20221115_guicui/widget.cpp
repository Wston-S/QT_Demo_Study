#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonIn_clicked()
{
    QTextStream tsIn(stdin);
    QTextStream tsOut(stdout);

    QString strOut = tr("please input a string:");
    tsOut<<strOut<<endl;
    QString strMsg = tsIn.readLine();
    ui->lineEditMsg->setText(strMsg);
}

void Widget::on_pushButtonOut_clicked()
{
    QTextStream tsOut(stdout);
    QString strMsg = ui->lineEditMsg->text();
    tsOut<<endl<<tr("output msg:")<<strMsg<<endl;

    qDebug()<<endl<<tr("this is debug message")<<endl;
}
