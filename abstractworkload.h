#ifndef ABSTRACTWORKLOAD_H
#define ABSTRACTWORKLOAD_H

#include <QMap>
#include <QString>
#include <QVariant>
#include <chrono>


class AbstractWorkload
{
public:
    AbstractWorkload();
    virtual ~AbstractWorkload(){}

    virtual QStringList startLoad(QMap<QString, QVariant> args){return QStringList();}
    void setDictPath(const QString &s){dictPath = s;}
    //void setPrecision(auto p);

     //enum class precision{milsec, micsec, nansec, sec};
protected:
    void startTimer();
    void stopTimer();
    bool readDict();

    QString workloadName = "";
    std::chrono::high_resolution_clock::time_point startTime;
    QString dictPath;
    QStringList passwdDict;
    QStringList resultsHex;
    //precision precision__;    
};

#endif // ABSTRACTWORKLOAD_H
