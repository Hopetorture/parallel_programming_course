#include "abstractworkload.h"

#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

AbstractWorkload::AbstractWorkload(){

}

//void AbstractWorkload::setPrecision(p){
//    precision__ = p;
//    if (precision__ == precision::milsec)
//        using tm_t = std::chrono::microseconds;

//}


void AbstractWorkload::startTimer(){
    startTime = std::chrono::high_resolution_clock::now();
}

void AbstractWorkload::stopTimer(){
    std::chrono::high_resolution_clock::time_point stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime).count();
    std::cout << workloadName.toStdString()  << ": " << duration << " ms" << std::endl;
}

bool AbstractWorkload::readDict()
{
    if (dictPath.isEmpty()){
        qCritical() << "dictionary path is not set";
        throw  new QString();
    }
    QFile f(dictPath);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)){
        qWarning() << "could not read dictionary";
        return false;
    }

    QTextStream in(&f);
    while (!in.atEnd()){
        passwdDict.append(QString(f.readLine()).remove("\n"));
    }
    f.close();
    return true;
}
