#ifndef MYWORK_H
#define MYWORK_H

#include <QDebug>
#include <QThread>
#include <QObject>

class MyWoker : public QObject
{
    Q_OBJECT

public:
    MyWoker(QObject *parent = nullptr){}

public slots:
    void doMyWorker(int paramter)
    {
        while (true)
        {
            static int cnt = 0;

            qDebug()<<"do my work: "<<cnt++<<", my thread id is "<<QThread::currentThreadId();
            QThread::sleep(1);

            if(cnt >= 10)
            {
                break;
            }
        }

        emit FinishworkSig(123);
    }

signals:
    void FinishworkSig(int);

};

#endif // MYWORK_H
