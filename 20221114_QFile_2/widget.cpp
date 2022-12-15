#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug()<<tr("BFH: %1 B").arg(sizeof(BMPFileHeader));
    qDebug()<<tr("BTH: %1 B").arg(sizeof(BMPInfoHeader));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonBrowse_clicked()
{
    QString strName = QFileDialog::getOpenFileName(this,
                            tr("open bmp"),
                                tr("."),
            tr("BMP Files(*.bmp);;All Files(*)"));
   if(strName.isEmpty())
   {
       return;
   }
   else
   {
       ui->lineEditName->setText(strName);
   }
}

void Widget::on_pushButtonShowPic_clicked()
{
    QString strName = ui->lineEditName->text();
    if(strName.isEmpty())
    {
        return;
    }
    else
    {
        ui->labelShowPic->setPixmap(QPixmap(strName));
    }
}

void Widget::on_pushButtonReadHeader_clicked()
{
    QString strName = ui->lineEditName->text();

    if(strName.isEmpty())
    {
        return;
    }

    QFile fileIn(strName);
    if(!fileIn.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("open file"),
                             tr("open file failed")+fileIn.errorString());

        return;
    }

    BMPFileHeader bfh;
    BMPInfoHeader bih;

    qint64 nReadBFH = fileIn.read((char*)&bfh, sizeof(bfh));
    qint64 nReadBIH = fileIn.read((char*)&bih, sizeof(bih));

    if(nReadBFH < sizeof(bfh))
    {
        QMessageBox::warning(this, tr("read bmp file"), tr("read bmp head "
                    "failed, the size is error"));

        fileIn.close();//可以不写,因为fileIn是从栈中分配的,系统会自动回收,但是实际使用肯定还是要写的
        return;
    }

    QString strInfo = tr("file name: %1\r\n\r\n").arg(strName);
    QString strTemp;

    if(bfh.bfType != 0x4D42)
    {
        strTemp = tr("type: no the bmp picture");
        strInfo = strTemp;
    }
    else
    {
        qDebug()<<"bih.biYPelsPerMeter : "<<bih.biYPelsPerMeter;
        strTemp = tr("type: BMP picture\r\n");
        strInfo += strTemp;
        strTemp = tr("width: %1\r\n").arg(bih.biWidth);
        strInfo += strTemp;
        strTemp = tr("Height: %1\r\n").arg(bih.biHeight);
        strInfo += strTemp;
        strTemp = tr("hor: %1 DPI\r\n").arg((int)(bih.biXPelsPerMeter/39.3701));
        strInfo += strTemp;
        strTemp = tr("ver: %1 DPI\r\n").arg((int)(bih.biYPelsPerMeter/39.3701));
        strInfo += strTemp;
        strTemp = tr("color depth: %1\r\n").arg(bih.biBitCount);
        strInfo += strTemp;
        strTemp = tr("frame count: %1\r\n").arg(bih.biPlanes);
        strInfo += strTemp;
    }

    ui->textBrowser->setText(strInfo);
}

void Widget::on_lineEditName_textChanged(const QString &arg1)
{
    QString strName = ui->lineEditName->text();

    if(strName.isEmpty())
    {
        return;
    }

    qDebug()<<"lineedit text:"<<arg1;

    QFile fileIn(strName);
    if(fileIn.exists())
    {
        QPalette palette;
        palette.setColor(QPalette::Text, QColor(0, 0, 0));
        ui->lineEditName->setPalette(palette);
    }
    else
    {
        QPalette palette;
        palette.setColor(QPalette::Text, QColor(255, 0, 0));
        ui->lineEditName->setPalette(palette);
    }
}






















