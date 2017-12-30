#include "stdthreadload.h"
#include "iostream"
#include <QCryptographicHash>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "functional"

StdThreadLoad::StdThreadLoad()
{
    this->workloadName = "std threads: ";
   // for (int i = 0; i < trNum; i++)
        //pool.push_back(new std::thread(&calculateHash));
    //std::cout << trNum << std::endl;

}

QStringList StdThreadLoad::startLoad(QMap<QString, QVariant> args)
{
    QStringList dict1;
    QStringList dict2;
    QStringList dict3;
    QStringList dict4;

    QStringList res1;
    QStringList res2;
    QStringList res3;
    QStringList res4;
    //readDict();
    if (dictPath.isEmpty()){
        qCritical() << "dictionary path is not set";
        throw  new QString();
    }
    QFile f(dictPath);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)){
        qWarning() << "could not read dictionary";
        throw new QString("could not read dict");
    }

    QTextStream in(&f);
    for (unsigned int i = 0; i < 250000; i++){
        if (!in.atEnd())
            dict1.append(QString(in.readLine()).remove("\n"));
    }
    for (unsigned int i = 0; i < 250000; i++){
        if (!in.atEnd())
            dict2.append(QString(in.readLine()).remove("\n"));
    }
    for (unsigned int i = 0; i < 250000; i++){
        if (!in.atEnd())
            dict3.append(QString(in.readLine()).remove("\n"));
    }
    for (unsigned int i = 0; i < 250000; i++){
        if (!in.atEnd())
            dict4.append(QString(in.readLine()).remove("\n"));
    }
    f.close();
    startTimer();

    auto fn = [&](QStringList &&dict,  QStringList &res){
        for (const QString &s : dict){
             res.append(QString(QCryptographicHash::hash(s.toUtf8(),QCryptographicHash::Md5)));
        }
    };
    std::thread tr1(fn, std::move(dict1), std::ref(res1));
    std::thread tr2(fn, std::move(dict2), std::ref(res2));
    std::thread tr3(fn, std::move(dict3), std::ref(res3));
    std::thread tr4(fn, std::move(dict4), std::ref(res4));

    tr1.join();
    tr2.join();
    tr3.join();
    tr4.join();
    resultsHex.append(res1);
    resultsHex.append(res2);
    resultsHex.append(res3);
    resultsHex.append(res4);

    stopTimer();
    return resultsHex;
}


