#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QListWidget>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QFileInfo>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->checkBoxAutoSort->setCheckState(Qt::Checked);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonAdd_clicked()
{
    QStringList slist = QFileDialog::getOpenFileNames(
                this,
                tr("add more music files"),
                tr("."),
                tr("Music files(*.mp3 *.wma *.wav);;All files(*)"));

    int nCount = slist.count();
    if(nCount < 1)
    {
        return;
    }

    for(int i = 0; i < nCount; i++)
    {
        QListWidgetItem *theItem = new QListWidgetItem(ui->listWidget);
        QFileInfo fi(slist[i]);
        theItem->setText(fi.completeBaseName());
        theItem->setToolTip(fi.absoluteFilePath());
    }
}

void Widget::on_pushButtonDel_clicked()
{
    int theRow;
    QList<QListWidgetItem *> itemList = ui->listWidget->selectedItems();

    int nCount = itemList.count();
    if(nCount < 1)
    {
        return;
    }

    for(int i = 0; i < nCount; i++)
    {
        theRow = ui->listWidget->row(itemList[i]);
        ui->listWidget->takeItem(theRow);
        delete itemList[i];
        itemList[i] = NULL;
    }

    itemList.clear();

    if(0 != ui->listWidget->count())
    {
        if(theRow+1 > ui->listWidget->count())
        {
            ui->listWidget->item(theRow-1)->setSelected(true);
        }
        else
        {
            ui->listWidget->item(theRow)->setSelected(true);
        }
    }
}

void Widget::on_pushButtonExportM3U_clicked()
{
    int nCount = ui->listWidget->count();
    if(nCount < 1)
    {
        return;
    }

    QString strName = QFileDialog::getSaveFileName(
                this,
                tr("save as M3U file"),
                tr("."),
                tr("M3U files(*.m3u)"));
    if(strName.isEmpty())
    {
        return;
    }

    QFile fileOut(strName);
    if(!fileOut.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(
                    this,
                    tr("open file"),
                    tr("can't open the file, please check fike power"));
        return;
    }

    QTextStream tsOut(&fileOut);
    tsOut<<tr("#EXTM3U")<<endl;
    for(int i = 0; i < nCount; i++)
    {
        QString strCurName = ui->listWidget->item(i)->toolTip();
        tsOut<<strCurName<<endl;
    }
}

void Widget::on_pushButtonFind_clicked()
{
    QString strTemplate = ui->lineEditTemplate->text();
    if(strTemplate.isEmpty())
    {
        return;
    }

    ui->listWidget->setCurrentItem(NULL, QItemSelectionModel::Clear);
    QList<QListWidgetItem *> list =
            ui->listWidget->findItems(strTemplate, Qt::MatchContains);
    int nCount = list.count();
    if(nCount < 1)
    {
        QMessageBox::information(this,
                                 tr("find items"),
                                 tr("find not natch item"));
        return;
    }

    ui->listWidget->setCurrentItem(list[0]);
    ui->listWidget->scrollToItem(list[0], QAbstractItemView::PositionAtTop);

    for(int i = 0; i < nCount; i++)
    {
        list[i]->setSelected(true);
    }

    ui->listWidget->setFocus();

}

void Widget::on_checkBoxAutoSort_clicked(bool checked)
{
    if(checked)
    {
        ui->listWidget->setSortingEnabled(true);
        ui->checkBoxReverse->setEnabled(true);
        if(ui->checkBoxReverse->checkState() != Qt::Checked)
        {
            ui->listWidget->sortItems(Qt::AscendingOrder);
        }
        else
        {
            ui->listWidget->sortItems(Qt::DescendingOrder);
        }
    }
    else
    {
        ui->listWidget->setSortingEnabled(false);
        ui->checkBoxReverse->setEnabled(false);
    }
}

void Widget::on_checkBoxReverse_clicked(bool checked)
{
    if(!checked)
    {
        ui->listWidget->sortItems(Qt::AscendingOrder);
    }
    else
    {
        ui->listWidget->sortItems(Qt::DescendingOrder);
    }
}




















