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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditDir;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonEnter;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonDrivers;
    QPushButton *pushButtonParent;
    QListWidget *listWidget;
    QPlainTextEdit *plainTextEditInfo;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 400);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEditDir = new QLineEdit(Widget);
        lineEditDir->setObjectName(QStringLiteral("lineEditDir"));

        horizontalLayout->addWidget(lineEditDir);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonEnter = new QPushButton(Widget);
        pushButtonEnter->setObjectName(QStringLiteral("pushButtonEnter"));
        pushButtonEnter->setMinimumSize(QSize(0, 0));
        pushButtonEnter->setMaximumSize(QSize(10000, 10000));

        horizontalLayout->addWidget(pushButtonEnter);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButtonDrivers = new QPushButton(Widget);
        pushButtonDrivers->setObjectName(QStringLiteral("pushButtonDrivers"));
        pushButtonDrivers->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_2->addWidget(pushButtonDrivers);

        pushButtonParent = new QPushButton(Widget);
        pushButtonParent->setObjectName(QStringLiteral("pushButtonParent"));
        pushButtonParent->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_2->addWidget(pushButtonParent);


        verticalLayout->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        plainTextEditInfo = new QPlainTextEdit(Widget);
        plainTextEditInfo->setObjectName(QStringLiteral("plainTextEditInfo"));

        verticalLayout->addWidget(plainTextEditInfo);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButtonEnter->setText(QApplication::translate("Widget", "\350\277\233\345\205\245", Q_NULLPTR));
        pushButtonDrivers->setText(QApplication::translate("Widget", "\350\216\267\345\217\226\345\210\206\346\240\271\345\214\272", Q_NULLPTR));
        pushButtonParent->setText(QApplication::translate("Widget", "\350\277\233\345\205\245\347\210\266\347\233\256\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
