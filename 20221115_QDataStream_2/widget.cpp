#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDataStream>
#include <QListWidget>
#include <QIntValidator>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    QIntValidator *valSrc = new QIntValidator(0, 65535);
    ui->lineEditSrcPort->setValidator(valSrc);
    QIntValidator *valDst = new QIntValidator(0, 65535);
    ui->lineEditDstPort->setValidator(valDst);
}

Widget::~Widget()
{
    delete ui;
}

QDataStream & operator<<(QDataStream & stream, const UDPPacker &udp)
{
    stream<<udp.m_srcPort;
    stream<<udp.m_dstPort;
    stream<<udp.m_length;
    stream<<udp.m_checksum;

    stream.writeRawData(udp.m_data.data(), udp.m_data.size());

    return stream;
}

QDataStream & operator>>(QDataStream & stream, UDPPacker &udp)
{
    stream>>udp.m_srcPort;
    stream>>udp.m_dstPort;
    stream>>udp.m_length;
    stream>>udp.m_checksum;

    int nMsgLen = udp.m_length - 8;
    char *buff = new char[nMsgLen];

    stream.readRawData(buff, nMsgLen);
    udp.m_data.setRawData(buff, nMsgLen);

    return stream;
}

void Widget::on_pushButtonAddUDP_clicked()
{
    QString strSrcPort = ui->lineEditSrcPort->text().trimmed();
    QString strDstPort = ui->lineEditDstPort->text().trimmed();
    QString strMsg = ui->lineEditMsg->text().trimmed();

    if(strSrcPort.isEmpty() || strDstPort.isEmpty() || strMsg.isEmpty())
    {
        QMessageBox::warning(this, tr("add pack"), tr("add pack error"));
        return;
    }

    UDPPacker udp;
    QByteArray baMsg = strMsg.toUtf8();
    udp.m_srcPort = strSrcPort.toUShort();
    udp.m_dstPort = strDstPort.toUShort();
    udp.m_length = 8 + baMsg.size();
    udp.m_checksum = 0;
    udp.m_data = baMsg;

    QByteArray baAll;
    QDataStream dsOut(&baAll, QIODevice::ReadWrite);
    dsOut<<udp;

    QString strAll = baAll.toHex();
    ui->listWidget->addItem(strAll);
}

void Widget::on_pushButtonDelUDP_clicked()
{
    int nCurRow = ui->listWidget->currentRow();

    if(nCurRow < 0)
    {
        return;
    }

    ui->listWidget->takeItem(nCurRow);
}

void Widget::on_pushButtonSave_clicked()
{
    int nCount = ui->listWidget->count();
    if(nCount < 1)
    {
        return;
    }

    QString strFileName = QFileDialog::getSaveFileName(this,
                                    tr("save UDP file"),
                                    tr("."),
                                    tr("UDP files(*.udp);;All files(*)"));
    if(strFileName.isEmpty())
    {
        return;
    }

    QFile fileOut(strFileName);
    if(!fileOut.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, tr("save UDP files"),
                             tr("open save file failed")+fileOut.errorString());
        return;
    }

    QDataStream dsOut(&fileOut);
    dsOut<<qint32(nCount);

    UDPPacker udpCur;
    for(int i = 0; i < nCount; i++)
    {
        QString strHex = ui->listWidget->item(i)->text();
        QByteArray baCur = QByteArray::fromHex(strHex.toUtf8());

        QDataStream dsIn(baCur);
        dsIn>>udpCur;
        dsOut<<udpCur;
    }

    QMessageBox::information(this, tr("save udp package"),
                             tr("save udp package finished!"));
}

void Widget::on_pushButtonLoad_clicked()
{
    QString strFileName = QFileDialog::getOpenFileName(this,
                        tr("open udp file"),
                        tr("."),
                       tr("udp files(*.udp);;All files(*)"));
    if(strFileName.isEmpty())
    {
        return;
    }

    QFile fileIn(strFileName);
    if(!fileIn.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("open udp file"), tr("open udp file failed")
                             +fileIn.errorString());
        return;
    }

    QDataStream dsIn(&fileIn);
    qint32 nCount;
    dsIn>>nCount;

    if(nCount < 1)
    {
        QMessageBox::warning(this, tr("load udp package"), tr("load failed"));
        return;
    }

    ui->listWidget->clear();

    UDPPacker udpCur;

    for(int i = 0; i < nCount; i++)
    {
        if(dsIn.status() != QDataStream::Ok)
        {
            qDebug()<<tr("read %1 package failed: %2").arg(i).arg(dsIn.status());
            break;
        }

        dsIn>>udpCur;

        QByteArray baCur;
        QDataStream dsOut(&baCur, QIODevice::ReadWrite);
        dsOut<<udpCur;
        QString strHex = baCur.toHex();
        ui->listWidget->addItem(strHex);
    }

    QMessageBox::information(this, tr("load udp package"),
                            tr("load udp package finisj"));
}

void Widget::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow < 0)
    {
        return;
    }

    QString strHex = ui->listWidget->item(currentRow)->text();
    QByteArray baAll = QByteArray::fromHex(strHex.toUtf8());
    QDataStream dsIn(baAll);

    UDPPacker udp;
    dsIn>>udp;

    ui->lineEditSrcPort->setText(tr("%1").arg(udp.m_srcPort));
    ui->lineEditDstPort->setText(tr("%1").arg(udp.m_dstPort));
    ui->lineEditMsg->setText(QString::fromUtf8(udp.m_data));
}







































