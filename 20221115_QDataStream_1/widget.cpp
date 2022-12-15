#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <QListWidgetItem>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonAdd_clicked()
{
    QString strName = ui->lineEditName->text().trimmed();
    QString strAge = ui->lineEditAge->text().trimmed();
    QString strWeight = ui->lineEditWeight->text().trimmed();

    if(strName.isEmpty() || strAge.isEmpty()|| strWeight.isEmpty())
    {
        QMessageBox::warning(this, tr("add row"), tr("please input name,age,and weight"));
        return;
    }

    qint32 nAge = strAge.toInt();
    double dblWeight = strWeight.toDouble();

    if(nAge<0 || dblWeight>600)
    {
        QMessageBox::warning(this, tr("add row"), tr("add row error"));
        return;
    }

    if(dblWeight < 0.1)
    {
        QMessageBox::warning(this, tr("add row"), tr("the weight is error"));
        return;
    }

    QString strAll;
    QTextStream tsLine(&strAll);
    tsLine<<strName<<"\t"<<nAge<<"\t"<<fixed<<qSetRealNumberPrecision(2)<<dblWeight;
    ui->listWidget->addItem(strAll);
}

void Widget::on_pushButtonDel_clicked()
{
    int nCurRow = ui->listWidget->currentRow();

    if(nCurRow<0) return;

    ui->listWidget->takeItem(nCurRow);
}

void Widget::on_pushButtonSaveDS_clicked()
{
    int nCount = ui->listWidget->count();

    if(nCount < 1)
    {
        return;
    }

    QString strFileName = QFileDialog::getSaveFileName(this, tr("save as DS file"),
                                   tr("."),
                                    tr("DS files(*.ds);;All files(*)"));\
    if(strFileName.isEmpty())
    {
        return;
    }

    QFile fileOut(strFileName);
    if(!fileOut.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, tr("can't open file"), tr("can't open file ")
                             + fileOut.errorString());
        return;
    }

    QDataStream dsOut(&fileOut);
    dsOut.setVersion(QDataStream::Qt_4_8);
    dsOut<<qint16(0x4453);
    dsOut<<qint16(0x0100);
    dsOut<<qint32(nCount);

    QString strCurName;
    qint32 nCurAge;
    double dblWeight;

    for(int i = 0; i <nCount; i++)
    {
        QString strLine = ui->listWidget->item(i)->text();
        QTextStream tsLine(&strLine);
        tsLine>>strCurName>>nCurAge>>dblWeight;
        dsOut<<strCurName<<nCurAge<<dblWeight;
    }

    QMessageBox::information(this, tr("save DS file"), tr("save DS file success"));
}

void Widget::on_pushButtonLoadDS_clicked()
{
    QString strFileName = QFileDialog::getOpenFileName(this,
                                tr("open DS file"),
                                  tr("."),
                                  tr("DS files(*.ds);;All files(*)"));

    if(strFileName.isEmpty())
    {
        return;
    }

    QFile fileIn(strFileName);
    if(!fileIn.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("open DS file"), tr("open DS file failed")+
                             fileIn.errorString());
        return;
    }

    QDataStream dsIn(&fileIn);

    qint16 nDS;
    qint16 nVersion;
    qint32 nCount;

    dsIn>>nDS>>nVersion>>nCount;

    qDebug()<<"nDS = "<<nDS;
    qDebug()<<"nVersion = "<<nVersion;
    qDebug()<<"nCount = "<<nCount;

    if(0x4453 != nDS)
    {
        QMessageBox::warning(this, tr("open file"), tr("the file isn't DS file"));
        return;
    }

    if(0x0100 != nVersion)
    {
        QMessageBox::warning(this, tr("open file"), tr("the file isn't 1.00 version"));
        return;
    }
    else
    {
        dsIn.setVersion(QDataStream::Qt_4_8);
    }

    if(nCount < 1)
    {
        QMessageBox::warning(this, tr("open file"),tr("the file count is < 1"));
        return;
    }

    QString strCurName;
    qint32 nCurAge;
    double dblWeight;

    ui->listWidget->clear();
    for(int i = 0; i < nCount; i++)
    {
        if(dsIn.status() != QDataStream::Ok)
        {
            qDebug()<<tr("the %1 row error: %2").arg(i).arg(dsIn.status());
            break;
        }

        dsIn>>strCurName>>nCurAge>>dblWeight;

        QString strLine = tr("%1\t%2\t%3").arg(strCurName)
                .arg(nCurAge).arg(dblWeight, 0, 'f', 3);
        ui->listWidget->addItem(strLine);
    }

    QMessageBox::information(this, tr("load DS file"), tr("load DS file finish!"));
}

void Widget::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow < 0) return;

    QString strLine = ui->listWidget->item(currentRow)->text();
    QTextStream tsLine(&strLine);

    QString strName;
    int Age;
    double dblWeight;

    tsLine>>strName>>Age>>dblWeight;

    ui->lineEditName->setText(strName);
    ui->lineEditAge->setText(tr("%1").arg(Age));
    ui->lineEditWeight->setText(tr("%1").arg(dblWeight));
}












































