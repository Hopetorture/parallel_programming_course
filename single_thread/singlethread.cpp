#include "singlethread.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QCryptographicHash>
//SingleThread::SingleThread() : AbstractWorkload()
//{

//}

SingleThread::SingleThread() : AbstractWorkload(){
    this->workloadName = "Single thread load";
}


//SingleThread::~SingleThread()
//{

//}

QStringList SingleThread::startLoad(QMap<QString, QVariant> args)
{
    if (!readDict())
        throw new QString("could not read dict");

    startTimer();    
    //std::cout << "single thread calculations" << std::endl;

    for (const QString  &s : passwdDict){
        resultsHex.append(QString(QCryptographicHash::hash(s.toUtf8(), QCryptographicHash::Md5).toHex()));
    }

//    for (const QString &out : resultsHex)
//        std::cout << out.toStdString() << std::endl;
    stopTimer();
    return resultsHex;
}
