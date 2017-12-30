#include "pthreadsload.h"
#include <iostream>
#include <pthread.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCryptographicHash>

PthreadsLoad::PthreadsLoad()
{
    this->workloadName = "Pthreads load: ";
}

void* ptLoad(void* ptr){
    QStringList* list;
    list = (QStringList*) ptr;
    QStringList *result = new QStringList();
    int i = 0;
    for (const QString &s: *list){
        result->append(QString(QCryptographicHash::hash(s.toUtf8(), QCryptographicHash::Md5).toHex()));
        i++;
    }
    return (void *)result;
}

QStringList PthreadsLoad::startLoad(QMap<QString, QVariant> args)
{
    int num_threads = 4;
    for (int i = 0; i < num_threads; i++){
        QStringList dic;
        QStringList res;
        this->dicts.append(dic);
        this->results.append(res);
    }

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
    for (int i = 0; i < num_threads; i++){
        for(unsigned int j = 0; j < 250000; j++){
            if (!in.atEnd())
                dicts[i].append(QString(in.readLine()).remove("\n"));
        }
    }
    f.close();
    startTimer();
    QList<pthread_t*> threadpool;

    for (int i = 0; i < num_threads; i++){
        pthread_t *tr = new pthread_t;
        void * data = (void*)&dicts[i];
        pthread_create(tr, NULL, &ptLoad, data);
        threadpool.push_back(tr);

    }

    for (int i = 0; i < num_threads; i++){
        void **data;
        pthread_join(*threadpool[i], data);
        QStringList *r = (QStringList*)*data;
        resultsHex.append(*r);
        delete threadpool[i];
    }

    stopTimer();
    return resultsHex;
}
