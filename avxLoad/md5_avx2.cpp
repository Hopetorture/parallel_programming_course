#include "md5_avx2.h"
#include "md5_loc.h"

#include <cassert>
#include <cstring>
#include <string>
#include <iostream>
#include <immintrin.h>
#include <QDebug>

#define H0 0x67452301
#define H1 0xefcdab89
#define H2 0x98badcfe
#define H3 0x10325476




md5_t::md5_t()
{
}

void md5_t::test()
{
}

void md5_t::prepare_tables(){
      int i;
        for(i=0; i<(sizeof(rv)/sizeof(*rv)); i++) {
            rv[i] = _mm256_set1_epi32(r[i]);
        }

        for(i=0; i<(sizeof(kv)/sizeof(*kv)); i++) {
            kv[i] = _mm256_set1_epi32(k[i]);
        }
}

void md5_t::avx2_md5(const QList<QByteArray> &input, resultPOD *res_ptr){
    if (input.size() != 8) throw std::string("input size error");

    __m256i msg_block = _mm256_setr_epi32(
                (quint32)input.at(0).toUInt(),
                (quint32)input.at(1).toUInt(),
                (quint32)input.at(2).toUInt(),
                (quint32)input.at(3).toUInt(),
                (quint32)input.at(4).toUInt(),
                (quint32)input.at(5).toUInt(),
                (quint32)input.at(6).toUInt(),
                (quint32)input.at(7).toUInt());

    a = _mm256_set1_epi32(H0);
    b = _mm256_set1_epi32(H1);
    c = _mm256_set1_epi32(H2);
    d = _mm256_set1_epi32(H3);
    int i=0;
    for(; i<16; i++) {
        __m256i f = _mm256_xor_si256(d, _mm256_and_si256(b, _mm256_xor_si256(c, d)));
        __m256i temp = d;
        d = c;
        c = b;
        b = _mm256_add_epi32(b, cyclic_left_rotate(a, f, kv[i], msg_block, rv[i]));
        a = temp;
    }

    for(; i<32; i++) {

        __m256i f = _mm256_xor_si256(c, _mm256_and_si256(d, _mm256_xor_si256(b, c)));

        __m256i temp = d;
        d = c;
        c = b;
        b = _mm256_add_epi32(b, cyclic_left_rotate(a, f, kv[i], msg_block, rv[i]));
        a = temp;
    }

    for(; i<48; i++) {

        __m256i tmp = _mm256_xor_si256(c,d);
        __m256i f = _mm256_xor_si256(b, tmp);

        __m256i temp = d;
        d = c;
        c = b;
        b = _mm256_add_epi32(b, cyclic_left_rotate(a, f, kv[i], msg_block, rv[i]));
        a = temp;
    }

    for(; i<64; i++) {

        __m256i f = _mm256_xor_si256(c, _mm256_or_si256(b, _mm256_xor_si256(d, _mm256_set1_epi32(0xFFFFFFFF))));

        __m256i temp = d;
        d = c;
        c = b;
        b = _mm256_add_epi32(b, cyclic_left_rotate(a, f, kv[i], msg_block, rv[i]));
        a = temp;

    }
//    uint32_t res_a[8];
//    uint32_t res_b[8];
//    uint32_t res_c[8];
//    uint32_t res_d[8];


        _mm256_storeu_si256((__m256i*)res_ptr->res_a, a);
        _mm256_storeu_si256((__m256i*)res_ptr->res_b, b);
        _mm256_storeu_si256((__m256i*)res_ptr->res_c, c);
        _mm256_storeu_si256((__m256i*)res_ptr->res_d, d);
//    _mm256_storeu_si256((__m256i *) res_a, a);
//    _mm256_storeu_si256((__m256i *) res_b, b);
//    _mm256_storeu_si256((__m256i *) res_c, c);
//    _mm256_storeu_si256((__m256i *) res_d, d);

   //should be more optimized, i.e. mm256_storeu to the pointer, passed to the function
//    QVector <void*> res;
//    for (int i = 0; i < 8; i++){
//        void * r;
//        memcpy((char*)r, &res_a, sizeof(unsigned int));
//        memcpy((char*)r + sizeof(unsigned int), &res_b, sizeof(unsigned int));
//        memcpy((char*)r + 2 * sizeof(unsigned int), &res_c, sizeof(unsigned int));
//        memcpy((char*)r + 3 * sizeof(unsigned int), &res_d, sizeof(unsigned int));
//        res.append(r);
//    }
//    return res;

}
