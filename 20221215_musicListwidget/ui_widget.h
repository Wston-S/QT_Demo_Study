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
#include <QtWidgets/QCheckBox>
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
    QLineEdit *lineEditTemplate;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonExportM3U;
    QCheckBox *checkBoxAutoSort;
    QCheckBox *checkBoxReverse;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonFind;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral("../20221212_QlistWidget/icon/pcba.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        lineEditTemplate = new QLineEdit(Widget);
        lineEditTemplate->setObjectName(QStringLiteral("lineEditTemplate"));

        verticalLayout->addWidget(lineEditTemplate);


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

        pushButtonExportM3U = new QPushButton(Widget);
        pushButtonExportM3U->setObjectName(QStringLiteral("pushButtonExportM3U"));

        verticalLayout_2->addWidget(pushButtonExportM3U);

        checkBoxAutoSort = new QCheckBox(Widget);
        checkBoxAutoSort->setObjectName(QStringLiteral("checkBoxAutoSort"));

        verticalLayout_2->addWidget(checkBoxAutoSort);

        checkBoxReverse = new QCheckBox(Widget);
        checkBoxReverse->setObjectName(QStringLiteral("checkBoxReverse"));

        verticalLayout_2->addWidget(checkBoxReverse);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButtonFind = new QPushButton(Widget);
        pushButtonFind->setObjectName(QStringLiteral("pushButtonFind"));

        verticalLayout_2->addWidget(pushButtonFind);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButtonAdd->setText(QApplication::translate("Widget", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButtonDel->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButtonExportM3U->setText(QApplication::translate("Widget", "\345\257\274\345\207\272m3u", Q_NULLPTR));
        checkBoxAutoSort->setText(QApplication::translate("Widget", "\350\207\252\345\212\250\346\216\222\345\272\217", Q_NULLPTR));
        checkBoxReverse->setText(QApplication::translate("Widget", "\351\200\206\345\272\217\346\216\222\345\210\227", Q_NULLPTR));
        pushButtonFind->setText(QApplication::translate("Widget", "\346\237\245\346\211\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
