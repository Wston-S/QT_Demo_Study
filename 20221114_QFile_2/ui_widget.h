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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditName;
    QPushButton *pushButtonBrowse;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonShowPic;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonReadHeader;
    QHBoxLayout *horizontalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelShowPic;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditName = new QLineEdit(Widget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        horizontalLayout->addWidget(lineEditName);

        pushButtonBrowse = new QPushButton(Widget);
        pushButtonBrowse->setObjectName(QStringLiteral("pushButtonBrowse"));

        horizontalLayout->addWidget(pushButtonBrowse);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonShowPic = new QPushButton(Widget);
        pushButtonShowPic->setObjectName(QStringLiteral("pushButtonShowPic"));

        horizontalLayout_2->addWidget(pushButtonShowPic);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButtonReadHeader = new QPushButton(Widget);
        pushButtonReadHeader->setObjectName(QStringLiteral("pushButtonReadHeader"));

        horizontalLayout_2->addWidget(pushButtonReadHeader);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        scrollArea = new QScrollArea(Widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 285, 230));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelShowPic = new QLabel(scrollAreaWidgetContents);
        labelShowPic->setObjectName(QStringLiteral("labelShowPic"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelShowPic->sizePolicy().hasHeightForWidth());
        labelShowPic->setSizePolicy(sizePolicy1);
        labelShowPic->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelShowPic);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_4->addWidget(scrollArea);

        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(textBrowser);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\345\220\215\357\274\232", Q_NULLPTR));
        pushButtonBrowse->setText(QApplication::translate("Widget", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButtonShowPic->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\345\233\276\347\211\207", Q_NULLPTR));
        pushButtonReadHeader->setText(QApplication::translate("Widget", "\350\257\273\345\217\226\345\244\264\351\203\250", Q_NULLPTR));
        labelShowPic->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\345\233\276\347\211\207\345\214\272\345\237\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
