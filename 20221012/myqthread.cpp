#include "myqthread.h"

void Myqthread::run()
{
    qDebug()<<"myThread run() start to execute";

    while (true) {
        static int cnt = 0;

        qDebug()<<"this run : "<<cnt++<<", my thread id is "<<QThread::currentThreadId();
        QThread::sleep(1);
    }
}

