#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QIcon>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QDataStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    int nCount = ui->listWidget->count();
    for(int i = 0; i < nCount; i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        item->setFlags(item->flags()|Qt::ItemIsEditable);
        item->setCheckState(Qt::Unchecked);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(NULL == current)
    {
        return;
    }

    QString strToolTip = current->toolTip();
    ui->lineEditToolTip->setText(strToolTip);
}

void Widget::on_listWidget_itemChanged(QListWidgetItem *item)
{
    if(NULL == item)
    {
        return;
    }

    if(item->checkState() != Qt::Checked)
    {
        return;
    }

    int nCount = ui->listWidget->count();
    int nUsingItemsCount = 0;

    for(int i = 0; i < nCount; i++)
    {
        QListWidgetItem *theItem = ui->listWidget->item(i);
        if(theItem->checkState() == Qt::Checked)
        {
            nUsingItemsCount++;
        }
    }

    if(nUsingItemsCount > 6)
    {
        QMessageBox::warning(this, tr("携带数目检查"),
                             tr("最多携带6个装备"));
        item->setCheckState(Qt::Unchecked);
    }
}

void Widget::on_pushButtonAdd_clicked()
{
    QString strItemFileName = QFileDialog::getOpenFileName(
                this,
                tr("选择装备图标文件"),
                tr("."),
                tr("Image files(*.jpg *.png *.bmp);;All files(*)")
                );

    if(strItemFileName.isEmpty())
    {
        return;
    }

    QIcon iconNew(strItemFileName);

    QListWidgetItem *itemNew = new QListWidgetItem(
                iconNew,
                tr("新装备名称"),
                ui->listWidget);

    itemNew->setFlags((itemNew->flags()) | Qt::ItemIsEditable);

    itemNew->setCheckState(Qt::Unchecked);
    ui->listWidget->setCurrentItem(itemNew);
    ui->listWidget->editItem(itemNew);
}

void Widget::on_pushButtonDel_clicked()
{
    int nCurRow = ui->listWidget->currentRow();
    if(nCurRow < 0)
    {
        return;
    }

    QListWidgetItem *temDel = ui->listWidget->takeItem(nCurRow);

    delete temDel;
    temDel = NULL;
}

void Widget::on_pushButtonViewMode_clicked()
{
    QListView::ViewMode vm = ui->listWidget->viewMode();

    if(QListView::ListMode == vm)
    {
        ui->listWidget->setViewMode(QListView::IconMode);
    }
    else
    {
        ui->listWidget->setViewMode(QListView::ListMode);
    }
}

void Widget::on_pushButtonLoad_clicked()
{
    QString strOpenName = QFileDialog::getOpenFileName(
                this,
                tr("open items file"),
                tr("."),
                tr("Items files(*.items)"));

    if(strOpenName.isEmpty())
    {
        return;
    }

    QFile fileOpen(strOpenName);
    if(!fileOpen.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(
                    this,
                    tr("open file"),
                    tr("open file failed, please check file power"));
        return;
    }

    QDataStream dsIn(&fileOpen);
    qint32 nCount;
    dsIn>>nCount;
    if(nCount <= 0)
    {
        QMessageBox::warning(
                    this,
                    tr("file load"),
                    tr("file has not item to load"));
        return;
    }

    ui->listWidget->clear();
    for(qint32 i = 0; i < nCount; i++)
    {
        QListWidgetItem *theItem = new QListWidgetItem(ui->listWidget);
        dsIn>>*theItem;

        theItem->setFlags(theItem->flags()|Qt::ItemIsEditable);
    }
}

void Widget::on_pushButtonSave_clicked()
{
    QString strSaveName = QFileDialog::getSaveFileName(
                this,
                tr("save items file"),
                tr("."),
                tr("Items files(*.items)"));
    if(strSaveName.isEmpty())
    {
        return;
    }

    QFile fileSave(strSaveName);
    if(!fileSave.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(
                    this,
                    tr("open writing file"),
                    tr("open save file failed, please check file name power"));
        return;
    }

    QDataStream dsOut(&fileSave);
    qint32 nCount = ui->listWidget->count();
    dsOut<<nCount;

    for(qint32 i = 0; i < nCount; i++)
    {
        QListWidgetItem *theItem = ui->listWidget->item(i);
        dsOut<<*theItem;
    }
}

void Widget::on_pushButtonEditToolTip_clicked()
{
    QString strNew = ui->lineEditToolTip->text();
    QListWidgetItem * curItem = ui->listWidget->currentItem();
    if(curItem != NULL)
    {
        curItem->setToolTip(strNew);
    }
}













