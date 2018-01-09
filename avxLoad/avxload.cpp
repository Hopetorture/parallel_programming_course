#include "avxload.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QCryptographicHash>
#include <immintrin.h>
#include "md5_avx2.h"
#include <QDebug>

AVXLoad::AVXLoad()
{
    this->workloadName = "avx load";
}

QStringList AVXLoad::startLoad(QMap<QString, QVariant> args)
{

    //__mm2
    uint32_t res[8];
    res[0] = 0; res[1] = 1; res[2] = 2; res[3] = 3; res[4] = 4; res[5] = 5; res[6] = 6; res[7] = 7;
    //_mm256_mul_epu32();
    __m256i ymm0 = _mm256_set_epi32(res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);
    __m256i ymm1 = _mm256_loadu_si256((const __m256i*)res);

    //_mm256_load_si256((__m256*) res/*, ymm0*/);
    QByteArray arr = "test";
    arr.constData(); arr.length();
    //MD5Update(&d->md5Context, (const unsigned char *)data, length);

    if (!readDict())
        throw new QString("could not read dict");

    startTimer();
    //std::cout << "single thread calculations" << std::endl;

    for (const QString  &s : passwdDict){
        md5::md5_t h;
        h.process((void*)s.toLocal8Bit().data(), s.toLocal8Bit().length());
        char res [16];
        void * sign = (void*)&res;
        h.finish(sign);
        char buffer[4096];
        md5::sig_to_string(sign, buffer, sizeof(buffer));
        qDebug() << QString(buffer);
    }

//    for (const QString &out : resultsHex)
//        std::cout << out.toStdString() << std::endl;
    stopTimer();
    return resultsHex;
}

QString AVXLoad::avxMd5(const QString &s)
{

}
