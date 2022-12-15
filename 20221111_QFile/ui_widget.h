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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditSrcFile;
    QPushButton *pushButtonBrowseSrc;
    QPushButton *pushButtonLoad;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditDstFile;
    QPushButton *pushButtonBrowseDst;
    QPushButton *pushButtonSave;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditIP;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditPort;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEditHostName;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEditWorkGroup;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(564, 325);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(label);

        lineEditSrcFile = new QLineEdit(Widget);
        lineEditSrcFile->setObjectName(QStringLiteral("lineEditSrcFile"));

        horizontalLayout->addWidget(lineEditSrcFile);

        pushButtonBrowseSrc = new QPushButton(Widget);
        pushButtonBrowseSrc->setObjectName(QStringLiteral("pushButtonBrowseSrc"));

        horizontalLayout->addWidget(pushButtonBrowseSrc);

        pushButtonLoad = new QPushButton(Widget);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));

        horizontalLayout->addWidget(pushButtonLoad);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(label_2);

        lineEditDstFile = new QLineEdit(Widget);
        lineEditDstFile->setObjectName(QStringLiteral("lineEditDstFile"));

        horizontalLayout_2->addWidget(lineEditDstFile);

        pushButtonBrowseDst = new QPushButton(Widget);
        pushButtonBrowseDst->setObjectName(QStringLiteral("pushButtonBrowseDst"));

        horizontalLayout_2->addWidget(pushButtonBrowseDst);

        pushButtonSave = new QPushButton(Widget);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        horizontalLayout_2->addWidget(pushButtonSave);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(Widget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(80, 0));

        horizontalLayout_3->addWidget(label_3);

        lineEditIP = new QLineEdit(Widget);
        lineEditIP->setObjectName(QStringLiteral("lineEditIP"));

        horizontalLayout_3->addWidget(lineEditIP);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(80, 0));

        horizontalLayout_4->addWidget(label_4);

        lineEditPort = new QLineEdit(Widget);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        horizontalLayout_4->addWidget(lineEditPort);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(80, 0));

        horizontalLayout_5->addWidget(label_5);

        lineEditHostName = new QLineEdit(Widget);
        lineEditHostName->setObjectName(QStringLiteral("lineEditHostName"));

        horizontalLayout_5->addWidget(lineEditHostName);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(80, 0));

        horizontalLayout_6->addWidget(label_6);

        lineEditWorkGroup = new QLineEdit(Widget);
        lineEditWorkGroup->setObjectName(QStringLiteral("lineEditWorkGroup"));

        horizontalLayout_6->addWidget(lineEditWorkGroup);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\346\272\220\346\226\207\344\273\266:", Q_NULLPTR));
        pushButtonBrowseSrc->setText(QApplication::translate("Widget", "\346\265\217\350\247\210\346\272\220", Q_NULLPTR));
        pushButtonLoad->setText(QApplication::translate("Widget", "\345\212\240\350\275\275\351\205\215\347\275\256", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\347\233\256\347\232\204\346\226\207\344\273\266:", Q_NULLPTR));
        pushButtonBrowseDst->setText(QApplication::translate("Widget", "\346\265\217\350\247\210\347\233\256\347\232\204", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\351\205\215\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "IP:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "Port:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "HostName:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "WorkGroup:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
