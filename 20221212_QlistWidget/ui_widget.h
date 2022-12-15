/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLineEdit *lineEditToolTip;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonViewMode;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonSave;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonEditToolTip;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(Widget);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/butterfly.png"), QSize(), QIcon::Normal, QIcon::Off);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setBackground(brush1);
        __qlistwidgetitem->setForeground(brush);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/club.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/cannon.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon2);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        lineEditToolTip = new QLineEdit(Widget);
        lineEditToolTip->setObjectName(QStringLiteral("lineEditToolTip"));

        verticalLayout->addWidget(lineEditToolTip);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButtonAdd = new QPushButton(Widget);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        verticalLayout_2->addWidget(pushButtonAdd);

        pushButtonDel = new QPushButton(Widget);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));

        verticalLayout_2->addWidget(pushButtonDel);

        pushButtonViewMode = new QPushButton(Widget);
        pushButtonViewMode->setObjectName(QStringLiteral("pushButtonViewMode"));

        verticalLayout_2->addWidget(pushButtonViewMode);

        pushButtonLoad = new QPushButton(Widget);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));

        verticalLayout_2->addWidget(pushButtonLoad);

        pushButtonSave = new QPushButton(Widget);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        verticalLayout_2->addWidget(pushButtonSave);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButtonEditToolTip = new QPushButton(Widget);
        pushButtonEditToolTip->setObjectName(QStringLiteral("pushButtonEditToolTip"));

        verticalLayout_2->addWidget(pushButtonEditToolTip);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Widget", "\350\235\264\350\235\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>+30\346\224\273\345\207\273\345\212\233</p><p>+60\347\247\273\351\200\237</p><p>+30\346\225\217\346\215\267\345\212\233</p><p>+35%\347\211\251\347\220\206\351\227\252\350\272\262</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Widget", "\351\207\221\347\256\215\346\243\222", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem1->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>+100\346\224\273\345\207\273\345\212\233</p><p>+10\351\230\262\345\276\241</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Widget", "\345\244\247\347\202\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem2->setToolTip(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/icon/cannon.png\"/></p><p>+200\346\224\273\345\207\273\345\212\233</p><p>+10%\347\240\264\347\224\262</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        listWidget->setSortingEnabled(__sortingEnabled);

#ifndef QT_NO_TOOLTIP
        pushButtonAdd->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>\346\267\273\345\212\240\346\235\241\347\233\256</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonAdd->setText(QApplication::translate("Widget", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButtonDel->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButtonViewMode->setText(QApplication::translate("Widget", "\345\210\207\346\215\242\346\230\276\347\244\272\346\250\241\345\274\217", Q_NULLPTR));
        pushButtonLoad->setText(QApplication::translate("Widget", "\345\212\240\350\275\275", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("Widget", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButtonEditToolTip->setText(QApplication::translate("Widget", "\347\274\226\350\276\221\345\267\245\345\205\267\346\217\220\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
