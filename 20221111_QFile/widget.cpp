#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QMessageBox>
#include <QRegExp>
#include <QRegExpValidator>
#include <QIntValidator>
#include <QFileDialog>
#include <QFile>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //定义 IPv4 正则表达式，注意 "\\" 就是一个反斜杠
    QRegExp re("^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}"
               "(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");

    QRegExpValidator *reVali = new QRegExpValidator(re);

    ui->lineEditIP->setValidator(reVali);

    QIntValidator *intVali = new QIntValidator(0, 65535);
    ui->lineEditPort->setValidator(intVali);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonBrowseSrc_clicked()
{
    QString strSrcName = QFileDialog::getOpenFileName(
                this,
                tr("打开配置文件"),
                tr(""),
                tr("Text files(*.txt);;All files(*)"));

    if(strSrcName.isEmpty())
    {
        return;
    }
    else
    {
        ui->lineEditSrcFile->setText(strSrcName);
    }
}

void Widget::on_pushButtonLoad_clicked()
{
    QString strSrc = ui->lineEditSrcFile->text();

    if(strSrc.isEmpty())
    {
        return;
    }

    QFile fileIn(strSrc);
    if(!fileIn.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("open error"),
                             tr("open file error")+fileIn.errorString());
        return;
    }

    while (!fileIn.atEnd()) {
        QByteArray baLine = fileIn.readLine();
        baLine = baLine.trimmed();
        if(baLine.startsWith("#"))
        {
            continue;
        }

        AnalyzeOneLine(baLine);
    }

    QMessageBox::information(this, tr("load config"), tr("load config finish!!"));
}

void Widget::on_pushButtonBrowseDst_clicked()
{
    QString strDstName = QFileDialog::getSaveFileName(this, tr("save config file"), tr(""),
                                                      tr("Text files(*.txt);;All files(8)"));

    if(strDstName.isEmpty())
    {
        return;
    }
    else
    {
        ui->lineEditDstFile->setText(strDstName);
    }
}

void Widget::on_pushButtonSave_clicked()
{
    QString strSaveName = ui->lineEditDstFile->text();

    QString strIP = ui->lineEditIP->text();
    QString strPort = ui->lineEditPort->text();
    QString strHostName = ui->lineEditHostName->text();
    QString strWOrkGroup = ui->lineEditWorkGroup->text();

    if(strSaveName.isEmpty() || strIP.isEmpty() || strPort.isEmpty()||
            strHostName.isEmpty() || strWOrkGroup.isEmpty())
    {
        QMessageBox::warning(this, tr("save configure"), tr("need to save file name and all value of configure"));
        return;
    }

    QFile fileOut(strSaveName);
    if(!fileOut.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("open file failed"), fileOut.errorString());
        return;
    }

    QByteArray baTemp = "ip = ";
    baTemp += strIP.toLocal8Bit() + "\n";
    fileOut.write(baTemp);
    baTemp = "port = ";
    baTemp += strPort.toLocal8Bit() + "\n";
    fileOut.write(baTemp);
    baTemp = "hostname = ";
    baTemp += strHostName.toLocal8Bit() + "\n";
    fileOut.write(baTemp);
    baTemp = "workgroup = ";
    baTemp += strWOrkGroup.toLocal8Bit() + "\n";
    fileOut.write(baTemp);

    QMessageBox::information(this, tr("save configure"), tr("save configure success!"));
}

void Widget::AnalyzeOneLine(const QByteArray &baLine)
{
    QList<QByteArray> list = baLine.split('=');
    if(list.count() < 2)
    {
        return;
    }

    QByteArray optionName = list[0].trimmed().toLower();
    QByteArray optionValue = list[1].trimmed();
    QString strValue = QString::fromLocal8Bit(optionValue);

    if("ip" == optionName)
    {
        ui->lineEditIP->setText(strValue);
        return;
    }

    if("port" == optionName)
    {
        ui->lineEditPort->setText(strValue);
        return;
    }

    if("hostname" == optionName)
    {
        ui->lineEditHostName->setText(strValue);
        return;
    }

    if("workgroup" == optionName)
    {
        ui->lineEditWorkGroup->setText(strValue);
        return;
    }
}


















