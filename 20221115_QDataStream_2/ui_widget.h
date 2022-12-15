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
#include <QtWidgets/QLabel>
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
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditSrcPort;
    QLabel *label_2;
    QLineEdit *lineEditDstPort;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditMsg;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAddUDP;
    QPushButton *pushButtonDelUDP;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoad;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditSrcPort = new QLineEdit(Widget);
        lineEditSrcPort->setObjectName(QStringLiteral("lineEditSrcPort"));

        horizontalLayout->addWidget(lineEditSrcPort);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditDstPort = new QLineEdit(Widget);
        lineEditDstPort->setObjectName(QStringLiteral("lineEditDstPort"));

        horizontalLayout->addWidget(lineEditDstPort);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEditMsg = new QLineEdit(Widget);
        lineEditMsg->setObjectName(QStringLiteral("lineEditMsg"));

        horizontalLayout_2->addWidget(lineEditMsg);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_3->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButtonAddUDP = new QPushButton(Widget);
        pushButtonAddUDP->setObjectName(QStringLiteral("pushButtonAddUDP"));

        verticalLayout->addWidget(pushButtonAddUDP);

        pushButtonDelUDP = new QPushButton(Widget);
        pushButtonDelUDP->setObjectName(QStringLiteral("pushButtonDelUDP"));

        verticalLayout->addWidget(pushButtonDelUDP);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButtonSave = new QPushButton(Widget);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        verticalLayout->addWidget(pushButtonSave);

        pushButtonLoad = new QPushButton(Widget);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));

        verticalLayout->addWidget(pushButtonLoad);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label->raise();
        label_2->raise();
        lineEditSrcPort->raise();
        lineEditDstPort->raise();
        lineEditMsg->raise();
        label_3->raise();
        label_3->raise();
        listWidget->raise();
        pushButtonAddUDP->raise();
        pushButtonDelUDP->raise();
        pushButtonSave->raise();
        pushButtonLoad->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\346\272\220\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\347\233\256\347\232\204\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\346\212\245\346\226\207\346\266\210\346\201\257\357\274\232", Q_NULLPTR));
        pushButtonAddUDP->setText(QApplication::translate("Widget", "\346\267\273\345\212\240UDP\345\214\205", Q_NULLPTR));
        pushButtonDelUDP->setText(QApplication::translate("Widget", "\345\210\240\351\231\244UDP\345\214\205", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("Widget", "\344\277\235\345\255\230UDP", Q_NULLPTR));
        pushButtonLoad->setText(QApplication::translate("Widget", "\345\212\240\350\275\275UDP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
