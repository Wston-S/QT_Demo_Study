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
    QLineEdit *lineEditName;
    QLabel *label_2;
    QLineEdit *lineEditAge;
    QLabel *label_3;
    QLineEdit *lineEditWeight;
    QPushButton *pushButtonAdd;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonDel;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonSaveDS;
    QPushButton *pushButtonLoadDS;

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

        lineEditName = new QLineEdit(Widget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        horizontalLayout->addWidget(lineEditName);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditAge = new QLineEdit(Widget);
        lineEditAge->setObjectName(QStringLiteral("lineEditAge"));

        horizontalLayout->addWidget(lineEditAge);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEditWeight = new QLineEdit(Widget);
        lineEditWeight->setObjectName(QStringLiteral("lineEditWeight"));

        horizontalLayout->addWidget(lineEditWeight);

        pushButtonAdd = new QPushButton(Widget);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        horizontalLayout->addWidget(pushButtonAdd);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_2->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButtonDel = new QPushButton(Widget);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));

        verticalLayout->addWidget(pushButtonDel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButtonSaveDS = new QPushButton(Widget);
        pushButtonSaveDS->setObjectName(QStringLiteral("pushButtonSaveDS"));

        verticalLayout->addWidget(pushButtonSaveDS);

        pushButtonLoadDS = new QPushButton(Widget);
        pushButtonLoadDS->setObjectName(QStringLiteral("pushButtonLoadDS"));

        verticalLayout->addWidget(pushButtonLoadDS);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(lineEditName, lineEditAge);
        QWidget::setTabOrder(lineEditAge, lineEditWeight);
        QWidget::setTabOrder(lineEditWeight, pushButtonAdd);
        QWidget::setTabOrder(pushButtonAdd, pushButtonDel);
        QWidget::setTabOrder(pushButtonDel, listWidget);
        QWidget::setTabOrder(listWidget, pushButtonSaveDS);
        QWidget::setTabOrder(pushButtonSaveDS, pushButtonLoadDS);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\344\275\223\351\207\215\357\274\232", Q_NULLPTR));
        pushButtonAdd->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\350\241\214", Q_NULLPTR));
        pushButtonDel->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\350\241\214", Q_NULLPTR));
        pushButtonSaveDS->setText(QApplication::translate("Widget", "\344\277\235\345\255\230DS", Q_NULLPTR));
        pushButtonLoadDS->setText(QApplication::translate("Widget", "\345\212\240\350\275\275DS", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
