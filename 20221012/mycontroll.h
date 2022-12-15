#ifndef MYCONTROLL_H
#define MYCONTROLL_H

#include <QObject>
#include <QThread>
#include <QDebug>

class MyControl : public QObject
{
    Q_OBJECT

public:
    MyControl(QObject * parent = 0);
    ~MyControl();

   QThread myworkThread;

   void statrWork0();

signals:
   void startWork(int);

public slots:
    void waitWorkOver(int para)
    {
        qDebug()<<"this is wait work over, and threadID:"<<QThread::currentThreadId();
    }

};

#endif // MYCONTROLL_H
