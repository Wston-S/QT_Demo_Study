#ifndef MYQTHREAD_H
#define MYQTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Myqthread : public QThread
{
    Q_OBJECT

public:
    Myqthread(QObject *parent = nullptr)
    {
        qDebug()<<"----------- this QThread Demo ----------";
    }

protected:
    void run() override;

};

#endif // MYQTHREAD_H
