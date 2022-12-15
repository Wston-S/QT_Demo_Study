#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mycontroll.h"
#include "myqthread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    MyControl *myctl;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
