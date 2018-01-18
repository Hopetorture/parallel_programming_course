#ifndef MD5_SSE2_H
#define MD5_SSE2_H

#include <qglobal.h>
#include <qbytearray.h>
#include <qstring.h>
#include <QVector>
#include <immintrin.h>
#include "md5_loc.h"

using uint = quint32;

class resultPOD{
public:
    uint32_t res_a[8];
    uint32_t res_b[8];
    uint32_t res_c[8];
    uint32_t res_d[8];
};


class md5_t
{
public:
    md5_t();  
    void avx2_md5(const QList<QByteArray> &input, resultPOD *res_ptr);
    void test();
    void prepare_tables();


private:
    __m256i a;                             /* accumulator 1 */
    __m256i b;                             /* accum5ulator 2 */
    __m256i c;                             /* accumulator 3 */
    __m256i d;                             /* accumulator 4 */

    __m256i kv[sizeof(k)/sizeof(*k)];
    __m256i rv[sizeof(r)/sizeof(*r)];

};


#endif // MD5_SSE2_H
