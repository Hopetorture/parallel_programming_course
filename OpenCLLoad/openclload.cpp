#include "openclload.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <iostream>
//#include <CL/cl.hpp>
//#include <CL/cl.h>
//#include <CL/cl_platform.h>
//#include <CL/opencl.h>


OpenCLLoad::OpenCLLoad()
{
   this->workloadName = "opencl load: ";
}

QStringList OpenCLLoad::startLoad(QMap<QString, QVariant> args)
{
    if (!readDict())
        throw new QString("could not read dict");

    startTimer();
    //std::cout << "single thread calculations" << std::endl;

    for (const QString  &s : passwdDict){
        //resultsHex.append(QString(QCryptographicHash::hash(s.toUtf8(), QCryptographicHash::Md5).toHex()));
    }

//    for (const QString &out : resultsHex)
//        std::cout << out.toStdString() << std::endl;
    stopTimer();
    return resultsHex;
}
