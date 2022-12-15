#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
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

void Widget::on_pushButtonLoad_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,
                    tr("open file"), tr("."),
                    tr("Text Files(*.txt);;All Files(*)"));
    if(strFile.isEmpty())
    {
        return;
    }

    qDebug()<<"strFile:"<<strFile;
    QFile fileIn(strFile);
    if(!fileIn.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("open file"),
                             tr("open file failed:") + fileIn.errorString());
        return;
    }

    QTextStream tsIn(&fileIn);
    QString strCurName;
    int nCurAge;
    double dbCurWeight;

    ui->listWidget->clear();

    while(!tsIn.atEnd())
    {
        tsIn>>strCurName;
        if(strCurName.isEmpty())
        {
            tsIn.skipWhiteSpace();
            continue;
        }

        if(strCurName.startsWith("#"))
        {
            tsIn.readLine();
            continue;
        }

        tsIn>>nCurAge>>dbCurWeight;

        QString strOut;

        QTextStream tsOut(&strOut);
        tsOut<<strCurName<<"\t"<<nCurAge<<"\t";
        tsOut<<fixed<<qSetRealNumberPrecision(2)<<dbCurWeight;

        ui->listWidget->addItem(strOut);
    }

    QMessageBox::information(this, tr("load form"), tr("load customize form finished"));
}

void Widget::on_pushButtonSave_clicked()
{
    int nCount = ui->listWidget->count();
    if(nCount < 1)
    {
        return;
    }

    QString strFileSave = QFileDialog::getSaveFileName(this, tr("save file"),
                tr("."), tr("XLS files(*.xls);;Text Files(*.txt)"));

    if(strFileSave.isEmpty())
    {
        return;
    }

    QFile fileOut(strFileSave);
    if(!fileOut.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, tr("save file"),
                             tr("open save file failed")+
                             fileOut.errorString());
        return;
    }

    QTextStream tsOut(&fileOut);
    tsOut<<tr("#name\tage\tweight")<<endl;

    for(int i = 0; i < nCount; i++)
    {
        QString strCurAll = ui->listWidget->item(i)->text();
        tsOut<<strCurAll<<endl;
    }

    QMessageBox::information(this, tr("save file"),
                             tr("save form file success"));
}

void Widget::on_pushButtonDelRow_clicked()
{
    int nCurIndex = ui->listWidget->currentRow();
    if(nCurIndex < 0)
    {
        return;
    }
    else
    {
        ui->listWidget->takeItem(nCurIndex);
    }
}

void Widget::on_pushButtonAddRow_clicked()
{
    QString strName = ui->lineEditName->text().trimmed();
    QString strAge = ui->lineEditAge->text().trimmed();
    QString strWeight = ui->lineEditWeight->text().trimmed();

    if(strName.isEmpty() || strAge.isEmpty() || strWeight.isEmpty())
    {
        QMessageBox::warning(this, tr("add row"), tr("please input data"));
        return;
    }

    int nAge = strAge.toInt();
    double dblWeight = strWeight.toDouble();
    if(nAge < 0 || nAge > 600)
    {
        QMessageBox::warning(this, tr("add row"), tr("error data"));
        return;
    }
    if(dblWeight < 0.1)
    {
        QMessageBox::warning(this, tr("add row"), tr("error weight data"));
        return;
    }

    QString strCurAll;
    QTextStream tsAll(&strCurAll);

#if 0
    QString strCurAll = tr("%1\t%2\t%3\t").arg(strName).arg(nAge).
            arg(dblWeight, 0, 'f', 2);
#else
    tsAll<<strName<<"\t"<<nAge<<"\t"<<fixed<<qSetRealNumberPrecision(2)<<dblWeight;
#endif

    ui->listWidget->addItem(strCurAll);
}

void Widget::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow < 0)
    {
        return;
    }

    QString strCurAll = ui->listWidget->item(currentRow)->text();
    QTextStream tsLine(&strCurAll);

    QString strName;
    int nAge;
    double dblWeight;

    tsLine>>strName>>nAge>>dblWeight;

    ui->lineEditName->setText(strName);
    ui->lineEditAge->setText(tr("%1").arg(nAge));
    ui->lineEditWeight->setText(tr("%1").arg(dblWeight));
}

































