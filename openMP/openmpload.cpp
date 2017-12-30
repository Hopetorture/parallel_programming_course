#include "openmpload.h"
#include <QCryptographicHash>
#include <omp.h>
#include <iostream>
#include <vector>

OpenMPLoad::OpenMPLoad()
{
     this->workloadName = "OpenMP thread load";
}

QStringList OpenMPLoad::startLoad(QMap<QString, QVariant> args)
{
    if (!readDict())
        throw new QString("could not read dict");

    startTimer();
    int num_threads = 4;
    omp_set_dynamic(0);
    omp_set_num_threads(num_threads);
    std::vector<QStringList> cacheVec;
    cacheVec.resize(num_threads);
    for (int i = 0; i < num_threads; i++){
        QStringList l;
        cacheVec[i] = l;
    }
    //omp_lock_t *lock = new omp_lock_t();
   // omp_init_lock(lock);
    #pragma omp parallel for
    for (int i = 0; i < passwdDict.length(); i++){
        QString res = QString(QCryptographicHash::hash(passwdDict[i].toUtf8(), QCryptographicHash::Md5).toHex());
        int id = omp_get_thread_num();
        //omp_set_lock(lock);
        QStringList lst = cacheVec[id];
        //omp_unset_lock(lock);
        lst.append(res);
    }
   // omp_destroy_lock(lock);
    for (int i = 0; i < num_threads; i ++){
        resultsHex << cacheVec[i];
    }
    stopTimer();
    return resultsHex;
}
