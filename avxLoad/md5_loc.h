#ifndef MD5_LOC_H
#define MD5_LOC_H
#include <immintrin.h>

/// For now we are assuming everything is in little endian byte-order
   /*
    * k denotes the integer part of the i-th element of the function:
    * k[i] = 4294967296 * abs(sin(i)), where i is in radians.
    */
   const uint32_t k[] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
                          0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
                          0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
                          0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
                          0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
                          0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
                          0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
                          0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
                          0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
                          0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
                          0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
                          0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
                          0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
                          0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
                          0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
                          0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };
   /*
    * Constants for the MD5 Transform routine as defined in RFC 1321
    */
   const uint32_t r[] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                          5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
                          4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                          6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };


   /*
    * Function to perform the cyclic left rotation of blocks of data
    */
   inline __m256i cyclic_left_rotate(__m256i a, __m256i f,  __m256i kv,  __m256i blockv, __m256i rv) {
       //return (data << shift_bits) | (data >> (32 - shift_bits));
       __m256i x = _mm256_add_epi32(a, _mm256_add_epi32(f, _mm256_add_epi32(kv, blockv)));
       __m128i qq =_mm_sub_epi32( _mm_set1_epi32(32), _mm256_castsi256_si128(rv));
       __m256i hh = _mm256_srl_epi32(x, (qq));
       __m256i ww = _mm256_sll_epi32(x, _mm256_castsi256_si128(rv));
       return _mm256_or_si256(ww, hh);
       //return _mm256_or_si256(_mm256_sll_epi32(x, _mm256_castsi256_si128(rv)), _mm256_srl_epi32(x, (_mm_sub_epi32( _mm_set1_epi32(32), _mm256_castsi256_si128(rv)))));
   }


//}
#endif // MD5_LOC_H
