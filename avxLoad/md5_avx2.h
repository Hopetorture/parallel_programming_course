#ifndef MD5_SSE2_H
#define MD5_SSE2_H

#include <qglobal.h>
#include <qbytearray.h>
#include <qstring.h>
#include <QVector>
#include <immintrin.h>
#include "md5_loc.h"

//namespace md5 {
using uint = quint32;
//const unsigned int MD5_SIZE = (4 * sizeof(unsigned int));   /* 16 */
//const unsigned int MD5_STRING_SIZE = 2 * MD5_SIZE + 1;      /* 33 */
//const unsigned int BLOCK_SIZE = 64;

class md5_t
{
public:
    md5_t();  
    void avx2_md5(const QList<QByteArray> &input);
    void test();
    void prepare_tables();
//    void process(__m256i &input, QVector<const uint> input_length);
//    void finish(void* signature_ = NULL);
//    void get_sig(void* signature_);
//    void get_string(void* str_);

private:
    /* internal functions */
//    void initialise();
//    void process_block(const unsigned char*block);
//    void get_result(void* result);

    __m256i a;                             /* accumulator 1 */
    __m256i b;                             /* accum5ulator 2 */
    __m256i c;                             /* accumulator 3 */
    __m256i d;                             /* accumulator 4 */

    __m256i kv[sizeof(k)/sizeof(*k)];
    __m256i rv[sizeof(r)/sizeof(*r)];


    //unsigned int message_length[2];                     /* length of data */
    //unsigned int stored_size;                               /* length of stored bytes */
    //unsigned char stored[md5::BLOCK_SIZE * 2];  /* stored bytes */

    //bool finished;                                             /* object state */

    //char signature[MD5_SIZE];                         /* stored signature */
    //char  str[MD5_STRING_SIZE];                     /* stored plain text hash */

};

//extern void sig_to_string(const void* signature_, char* str_, const int str_len);
//}//namespace md5

#endif // MD5_SSE2_H
