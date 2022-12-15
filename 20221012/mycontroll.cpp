#include "mycontroll.h"
#include "mywork.h"

MyControl::MyControl(QObject * parent) : QObject(parent)
{
    MyWoker * mywork = new MyWoker();
    mywork->moveToThread(&myworkThread);

    connect(mywork, SIGNAL(FinishworkSig(int)), this, SLOT(waitWorkOver(int)));
    connect(&myworkThread, &QThread::finished, mywork, &QObject::deleteLater);
    connect(this, SIGNAL(startWork(int)), mywork, SLOT(doMyWorker(int)));

    qDebug()<<"------QThread moveToThread Demo-----";
    myworkThread.start();
}

MyControl::~MyControl()
{
    myworkThread.quit();
    myworkThread.wait();
}

void MyControl::statrWork0()
{
    emit startWork(0);
}


