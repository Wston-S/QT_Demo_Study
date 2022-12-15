#include <QCoreApplication>
#include <QTextStream>
#include <iostream>

void Funcs(int nCode, QTextStream &tsIn, QTextStream &tsOut);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream tsIn(stdin);
    QTextStream tsOut(stdout);

    while(true)
    {
        QString strFuns = a.tr("功能代码:\n"
                               "1.输入整形数\n"
                               "2.输入浮点数\n"
                               "3.输入单词\n"
                               "4.输入整行句子\n"
                               "9.退出程序\n"
                               "请输入功能代码: ");

        tsOut<<strFuns<<flush;

        int nCode;
        tsIn>>nCode;

        if(9 == nCode)
        {
            tsOut<<a.tr("程序结束")<<endl;
            return 0;
        }
        else
        {
            Funcs(nCode, tsIn, tsOut);
        }
    }

    return a.exec();
}

void Funcs(int nCode, QTextStream &tsIn, QTextStream &tsOut)
{
    tsOut<<endl;
    QString strOut;
    QString strIn;
    int nNum;
    double dblValue;

    switch (nCode) {
    case 1:
        strOut = qApp->tr("input a int number:");
        tsOut<<strOut<<flush;
        tsIn>>nNum;
        strOut = qApp->tr("your input int number is: %1").arg(nNum);
        tsOut<<strOut<<endl;
        break;

    case 2:
        strOut = qApp->tr("input a float number:");
        tsOut<<strOut<<flush;
        tsIn>>dblValue;
        strOut = qApp->tr("your input float number is:%1").arg(dblValue);
        tsOut<<strOut<<endl;
        break;

    case 3:
        strOut = qApp->tr("input a word:");
        tsOut<<strOut<<flush;
        tsIn>>strIn;
        strOut = qApp->tr("your input word is:%1").arg(strIn);
        tsOut<<strOut<<endl;
        break;

    case 4:
        strOut = qApp->tr("input a string:");
        tsOut<<strOut<<flush;
        tsIn.skipWhiteSpace();
        strIn = tsIn.readLine();
        strOut = qApp->tr("your input is %1").arg(strIn);
        tsOut<<strOut<<endl;
        break;

    default:
        strOut = qApp->tr("unknow common, please again");
        tsOut<<strOut<<endl;
        break;
    }

    tsOut<<endl;

    if(tsIn.status() != QTextStream::Ok)
    {
        tsIn.readLine();
        tsIn.resetStatus();
    }
}
















