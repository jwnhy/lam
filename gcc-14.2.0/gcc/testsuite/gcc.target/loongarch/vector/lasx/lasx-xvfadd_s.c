/* { dg-options "-mlasx -w -fno-strict-aliasing" } */
#include "../simd_correctness_check.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_op0, __m256i_op1, __m256i_op2, __m256i_out, __m256i_result;
  __m256 __m256_op0, __m256_op1, __m256_op2, __m256_out, __m256_result;
  __m256d __m256d_op0, __m256d_op1, __m256d_op2, __m256d_out, __m256d_result;

  int int_op0, int_op1, int_op2, int_out, int_result, i = 1, fail;
  long int long_op0, long_op1, long_op2, lont_out, lont_result;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0xffffffff;
  *((int *)&__m256_op0[4]) = 0xffffffff;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0xffffffff;
  *((int *)&__m256_op0[0]) = 0xffffffff;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0xffffffff;
  *((int *)&__m256_result[4]) = 0xffffffff;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0xffffffff;
  *((int *)&__m256_result[0]) = 0xffffffff;
  __m256_out = __lasx_xvfadd_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0xffffffff;
  *((int *)&__m256_op1[6]) = 0x00000001;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000002;
  *((int *)&__m256_op1[3]) = 0xffffffff;
  *((int *)&__m256_op1[2]) = 0x00000001;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000002;
  *((int *)&__m256_result[7]) = 0xffffffff;
  *((int *)&__m256_result[6]) = 0x00000001;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000002;
  *((int *)&__m256_result[3]) = 0xffffffff;
  *((int *)&__m256_result[2]) = 0x00000001;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000002;
  __m256_out = __lasx_xvfadd_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfadd_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0xffffffff;
  *((int *)&__m256_op0[4]) = 0xffffffff;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0xffffffff;
  *((int *)&__m256_op0[0]) = 0xffffffff;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0xffffffff;
  *((int *)&__m256_op1[4]) = 0xffffffff;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0xffffffff;
  *((int *)&__m256_op1[0]) = 0xffffffff;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0xffffffff;
  *((int *)&__m256_result[4]) = 0xffffffff;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0xffffffff;
  *((int *)&__m256_result[0]) = 0xffffffff;
  __m256_out = __lasx_xvfadd_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x40b2bf4d;
  *((int *)&__m256_op0[6]) = 0x30313031;
  *((int *)&__m256_op0[5]) = 0x50005000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x40b2bf4d;
  *((int *)&__m256_op0[2]) = 0x30313031;
  *((int *)&__m256_op0[1]) = 0x50005000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x22be22be;
  *((int *)&__m256_op1[5]) = 0x7fff7fff;
  *((int *)&__m256_op1[4]) = 0xa2bea2be;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x22be22be;
  *((int *)&__m256_op1[1]) = 0x7fff7fff;
  *((int *)&__m256_op1[0]) = 0xa2bea2be;
  *((int *)&__m256_result[7]) = 0x40b2bf4d;
  *((int *)&__m256_result[6]) = 0x30313031;
  *((int *)&__m256_result[5]) = 0x7fff7fff;
  *((int *)&__m256_result[4]) = 0xa2bea2be;
  *((int *)&__m256_result[3]) = 0x40b2bf4d;
  *((int *)&__m256_result[2]) = 0x30313031;
  *((int *)&__m256_result[1]) = 0x7fff7fff;
  *((int *)&__m256_result[0]) = 0xa2bea2be;
  __m256_out = __lasx_xvfadd_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00ff0000;
  *((int *)&__m256_op1[4]) = 0xffffffff;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00ff0000;
  *((int *)&__m256_op1[0]) = 0xffffffff;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00ff0000;
  *((int *)&__m256_result[4]) = 0xffffffff;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00ff0000;
  *((int *)&__m256_result[0]) = 0xffffffff;
  __m256_out = __lasx_xvfadd_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x0000008c;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x0000008c;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x0000008c;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x0000008c;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000118;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000118;
  __m256_out = __lasx_xvfadd_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0xffffffff;
  *((int *)&__m256_op0[4]) = 0xffff8000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0xffffffff;
  *((int *)&__m256_op0[0]) = 0xffff8000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0xffffffff;
  *((int *)&__m256_result[4]) = 0xffff8000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0xffffffff;
  *((int *)&__m256_result[0]) = 0xffff8000;
  __m256_out = __lasx_xvfadd_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0xffff0101;
  *((int *)&__m256_op0[4]) = 0x00000001;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0xffff0101;
  *((int *)&__m256_op0[0]) = 0x00000001;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0xffff0101;
  *((int *)&__m256_result[4]) = 0x00000001;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0xffff0101;
  *((int *)&__m256_result[0]) = 0x00000001;
  __m256_out = __lasx_xvfadd_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0xffffffff;
  *((int *)&__m256_op0[6]) = 0xffffffff;
  *((int *)&__m256_op0[5]) = 0xffffffff;
  *((int *)&__m256_op0[4]) = 0xffffffff;
  *((int *)&__m256_op0[3]) = 0xffffffff;
  *((int *)&__m256_op0[2]) = 0xffffffff;
  *((int *)&__m256_op0[1]) = 0xffffffff;
  *((int *)&__m256_op0[0]) = 0xffffffff;
  *((int *)&__m256_op1[7]) = 0xffffffff;
  *((int *)&__m256_op1[6]) = 0xffffffff;
  *((int *)&__m256_op1[5]) = 0xffffffff;
  *((int *)&__m256_op1[4]) = 0xffffffff;
  *((int *)&__m256_op1[3]) = 0xffffffff;
  *((int *)&__m256_op1[2]) = 0xffffffff;
  *((int *)&__m256_op1[1]) = 0xffffffff;
  *((int *)&__m256_op1[0]) = 0xffffffff;
  *((int *)&__m256_result[7]) = 0xffffffff;
  *((int *)&__m256_result[6]) = 0xffffffff;
  *((int *)&__m256_result[5]) = 0xffffffff;
  *((int *)&__m256_result[4]) = 0xffffffff;
  *((int *)&__m256_result[3]) = 0xffffffff;
  *((int *)&__m256_result[2]) = 0xffffffff;
  *((int *)&__m256_result[1]) = 0xffffffff;
  *((int *)&__m256_result[0]) = 0xffffffff;
  __m256_out = __lasx_xvfmul_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfmul_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x10101011;
  *((int *)&__m256_op1[4]) = 0x10101011;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x11111112;
  *((int *)&__m256_op1[0]) = 0x11111112;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfmul_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00060000;
  *((int *)&__m256_op0[6]) = 0x00040000;
  *((int *)&__m256_op0[5]) = 0x00020000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00060000;
  *((int *)&__m256_op0[2]) = 0x00040000;
  *((int *)&__m256_op0[1]) = 0x00020000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00060000;
  *((int *)&__m256_op1[6]) = 0x00040000;
  *((int *)&__m256_op1[5]) = 0x00020000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00060000;
  *((int *)&__m256_op1[2]) = 0x00040000;
  *((int *)&__m256_op1[1]) = 0x00020000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfmul_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfmul_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0xffffffff;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0xffffffff;
  *((int *)&__m256_op1[4]) = 0xffffffff;
  *((int *)&__m256_op1[3]) = 0xffffffff;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0xffffffff;
  *((int *)&__m256_op1[0]) = 0xffffffff;
  *((int *)&__m256_result[7]) = 0xffffffff;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0xffffffff;
  *((int *)&__m256_result[4]) = 0xffffffff;
  *((int *)&__m256_result[3]) = 0xffffffff;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0xffffffff;
  *((int *)&__m256_result[0]) = 0xffffffff;
  __m256_out = __lasx_xvfmul_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x000000ff;
  *((int *)&__m256_op0[4]) = 0x000000ff;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x000000ff;
  *((int *)&__m256_op0[0]) = 0x000000ff;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000101;
  *((int *)&__m256_op1[4]) = 0x00000101;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000101;
  *((int *)&__m256_op1[0]) = 0x00000101;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfmul_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0xffff001f;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x007fe268;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0xffff001f;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x007fe268;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0xffff001f;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x007fe268;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0xffff001f;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x007fe268;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0xffff001f;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0xffff001f;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0xffffffff;
  *((int *)&__m256_op1[6]) = 0xffffffff;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0xffffffff;
  *((int *)&__m256_op1[2]) = 0xffffffff;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0xffffffff;
  *((int *)&__m256_result[6]) = 0xffffffff;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0xffffffff;
  *((int *)&__m256_result[2]) = 0xffffffff;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x7f800000;
  *((int *)&__m256_op1[6]) = 0x7f800000;
  *((int *)&__m256_op1[5]) = 0x7f800000;
  *((int *)&__m256_op1[4]) = 0x7f800000;
  *((int *)&__m256_op1[3]) = 0x7f800000;
  *((int *)&__m256_op1[2]) = 0x7f800000;
  *((int *)&__m256_op1[1]) = 0x7f800000;
  *((int *)&__m256_op1[0]) = 0x7f800000;
  *((int *)&__m256_result[7]) = 0xff800000;
  *((int *)&__m256_result[6]) = 0xff800000;
  *((int *)&__m256_result[5]) = 0xff800000;
  *((int *)&__m256_result[4]) = 0xff800000;
  *((int *)&__m256_result[3]) = 0xff800000;
  *((int *)&__m256_result[2]) = 0xff800000;
  *((int *)&__m256_result[1]) = 0xff800000;
  *((int *)&__m256_result[0]) = 0xff800000;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x02a54290;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x02a54290;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x02a54290;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x0154dc84;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x02a54290;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000089;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x82a54290;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x028aa700;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x82a54290;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x02a54287;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00004200;
  *((int *)&__m256_op0[6]) = 0x80000000;
  *((int *)&__m256_op0[5]) = 0x5fff5fff;
  *((int *)&__m256_op0[4]) = 0x607f0000;
  *((int *)&__m256_op0[3]) = 0x00004200;
  *((int *)&__m256_op0[2]) = 0x80000000;
  *((int *)&__m256_op0[1]) = 0x5fff5fff;
  *((int *)&__m256_op0[0]) = 0x607f0000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00004200;
  *((int *)&__m256_result[6]) = 0x80000000;
  *((int *)&__m256_result[5]) = 0x5fff5fff;
  *((int *)&__m256_result[4]) = 0x607f0000;
  *((int *)&__m256_result[3]) = 0x00004200;
  *((int *)&__m256_result[2]) = 0x80000000;
  *((int *)&__m256_result[1]) = 0x5fff5fff;
  *((int *)&__m256_result[0]) = 0x607f0000;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00000000;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000000;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00000000;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000000;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00800080;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000202;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00800080;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000202;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x00000000;
  *((int *)&__m256_result[6]) = 0x00800080;
  *((int *)&__m256_result[5]) = 0x00000000;
  *((int *)&__m256_result[4]) = 0x00000202;
  *((int *)&__m256_result[3]) = 0x00000000;
  *((int *)&__m256_result[2]) = 0x00800080;
  *((int *)&__m256_result[1]) = 0x00000000;
  *((int *)&__m256_result[0]) = 0x00000202;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0xfffefffe;
  *((int *)&__m256_op0[6]) = 0xfffefffe;
  *((int *)&__m256_op0[5]) = 0xfffefffe;
  *((int *)&__m256_op0[4]) = 0xfffefffe;
  *((int *)&__m256_op0[3]) = 0xfffefffe;
  *((int *)&__m256_op0[2]) = 0xfffefffe;
  *((int *)&__m256_op0[1]) = 0xfffefffe;
  *((int *)&__m256_op0[0]) = 0xfffefffe;
  *((int *)&__m256_op1[7]) = 0x000023a3;
  *((int *)&__m256_op1[6]) = 0x00003fff;
  *((int *)&__m256_op1[5]) = 0x000023a3;
  *((int *)&__m256_op1[4]) = 0x00003fef;
  *((int *)&__m256_op1[3]) = 0x000023a3;
  *((int *)&__m256_op1[2]) = 0x00003fff;
  *((int *)&__m256_op1[1]) = 0x000023a3;
  *((int *)&__m256_op1[0]) = 0x00003fef;
  *((int *)&__m256_result[7]) = 0xfffefffe;
  *((int *)&__m256_result[6]) = 0xfffefffe;
  *((int *)&__m256_result[5]) = 0xfffefffe;
  *((int *)&__m256_result[4]) = 0xfffefffe;
  *((int *)&__m256_result[3]) = 0xfffefffe;
  *((int *)&__m256_result[2]) = 0xfffefffe;
  *((int *)&__m256_result[1]) = 0xfffefffe;
  *((int *)&__m256_result[0]) = 0xfffefffe;
  __m256_out = __lasx_xvfsub_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0xffffffff;
  *((int *)&__m256_op0[6]) = 0xffffffff;
  *((int *)&__m256_op0[5]) = 0xffffffff;
  *((int *)&__m256_op0[4]) = 0xffffffff;
  *((int *)&__m256_op0[3]) = 0xffffffff;
  *((int *)&__m256_op0[2]) = 0xffffffff;
  *((int *)&__m256_op0[1]) = 0xffffffff;
  *((int *)&__m256_op0[0]) = 0xffffffff;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x002a542a;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x002a542a;
  *((int *)&__m256_result[7]) = 0xffffffff;
  *((int *)&__m256_result[6]) = 0xffffffff;
  *((int *)&__m256_result[5]) = 0xffffffff;
  *((int *)&__m256_result[4]) = 0xffffffff;
  *((int *)&__m256_result[3]) = 0xffffffff;
  *((int *)&__m256_result[2]) = 0xffffffff;
  *((int *)&__m256_result[1]) = 0xffffffff;
  *((int *)&__m256_result[0]) = 0xffffffff;
  __m256_out = __lasx_xvfdiv_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000001;
  *((int *)&__m256_op0[6]) = 0x00000001;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000001;
  *((int *)&__m256_op0[2]) = 0x00000001;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x7f800000;
  *((int *)&__m256_result[6]) = 0x7f800000;
  *((int *)&__m256_result[5]) = 0x7fc00000;
  *((int *)&__m256_result[4]) = 0x7fc00000;
  *((int *)&__m256_result[3]) = 0x7f800000;
  *((int *)&__m256_result[2]) = 0x7f800000;
  *((int *)&__m256_result[1]) = 0x7fc00000;
  *((int *)&__m256_result[0]) = 0x7fc00000;
  __m256_out = __lasx_xvfdiv_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00fe00fe;
  *((int *)&__m256_op0[6]) = 0x00fe00fe;
  *((int *)&__m256_op0[5]) = 0x00fe00fe;
  *((int *)&__m256_op0[4]) = 0x00fe00fe;
  *((int *)&__m256_op0[3]) = 0x00fe00fe;
  *((int *)&__m256_op0[2]) = 0x00fe00fe;
  *((int *)&__m256_op0[1]) = 0x00fe00fe;
  *((int *)&__m256_op0[0]) = 0x00fe00fe;
  *((int *)&__m256_op1[7]) = 0x00fe00fe;
  *((int *)&__m256_op1[6]) = 0x00fe00fe;
  *((int *)&__m256_op1[5]) = 0x00fe00fe;
  *((int *)&__m256_op1[4]) = 0x00fe00fe;
  *((int *)&__m256_op1[3]) = 0x00fe00fe;
  *((int *)&__m256_op1[2]) = 0x00fe00fe;
  *((int *)&__m256_op1[1]) = 0x00fe00fe;
  *((int *)&__m256_op1[0]) = 0x00fe00fe;
  *((int *)&__m256_result[7]) = 0x3f800000;
  *((int *)&__m256_result[6]) = 0x3f800000;
  *((int *)&__m256_result[5]) = 0x3f800000;
  *((int *)&__m256_result[4]) = 0x3f800000;
  *((int *)&__m256_result[3]) = 0x3f800000;
  *((int *)&__m256_result[2]) = 0x3f800000;
  *((int *)&__m256_result[1]) = 0x3f800000;
  *((int *)&__m256_result[0]) = 0x3f800000;
  __m256_out = __lasx_xvfdiv_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x00000000;
  *((int *)&__m256_op0[4]) = 0x00000000;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x00000000;
  *((int *)&__m256_op0[0]) = 0x00000000;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x00000000;
  *((int *)&__m256_op1[4]) = 0x00000000;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x00000000;
  *((int *)&__m256_op1[0]) = 0x00000000;
  *((int *)&__m256_result[7]) = 0x7fc00000;
  *((int *)&__m256_result[6]) = 0x7fc00000;
  *((int *)&__m256_result[5]) = 0x7fc00000;
  *((int *)&__m256_result[4]) = 0x7fc00000;
  *((int *)&__m256_result[3]) = 0x7fc00000;
  *((int *)&__m256_result[2]) = 0x7fc00000;
  *((int *)&__m256_result[1]) = 0x7fc00000;
  *((int *)&__m256_result[0]) = 0x7fc00000;
  __m256_out = __lasx_xvfdiv_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000000;
  *((int *)&__m256_op0[6]) = 0x00000000;
  *((int *)&__m256_op0[5]) = 0x803f6004;
  *((int *)&__m256_op0[4]) = 0x1f636003;
  *((int *)&__m256_op0[3]) = 0x00000000;
  *((int *)&__m256_op0[2]) = 0x00000000;
  *((int *)&__m256_op0[1]) = 0x803f6004;
  *((int *)&__m256_op0[0]) = 0x1f636003;
  *((int *)&__m256_op1[7]) = 0x00000000;
  *((int *)&__m256_op1[6]) = 0x00000000;
  *((int *)&__m256_op1[5]) = 0x007f0107;
  *((int *)&__m256_op1[4]) = 0x00c70106;
  *((int *)&__m256_op1[3]) = 0x00000000;
  *((int *)&__m256_op1[2]) = 0x00000000;
  *((int *)&__m256_op1[1]) = 0x007f0107;
  *((int *)&__m256_op1[0]) = 0x00c70106;
  *((int *)&__m256_result[7]) = 0x7fc00000;
  *((int *)&__m256_result[6]) = 0x7fc00000;
  *((int *)&__m256_result[5]) = 0xbeff7cfd;
  *((int *)&__m256_result[4]) = 0x5e123f94;
  *((int *)&__m256_result[3]) = 0x7fc00000;
  *((int *)&__m256_result[2]) = 0x7fc00000;
  *((int *)&__m256_result[1]) = 0xbeff7cfd;
  *((int *)&__m256_result[0]) = 0x5e123f94;
  __m256_out = __lasx_xvfdiv_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  *((int *)&__m256_op0[7]) = 0x00000008;
  *((int *)&__m256_op0[6]) = 0x60601934;
  *((int *)&__m256_op0[5]) = 0x00000008;
  *((int *)&__m256_op0[4]) = 0x00200028;
  *((int *)&__m256_op0[3]) = 0x00000008;
  *((int *)&__m256_op0[2]) = 0x60601934;
  *((int *)&__m256_op0[1]) = 0x00000008;
  *((int *)&__m256_op0[0]) = 0x00200028;
  *((int *)&__m256_op1[7]) = 0xffffffff;
  *((int *)&__m256_op1[6]) = 0xffffffff;
  *((int *)&__m256_op1[5]) = 0xffffffff;
  *((int *)&__m256_op1[4]) = 0xffffffff;
  *((int *)&__m256_op1[3]) = 0xffffffff;
  *((int *)&__m256_op1[2]) = 0xffffffff;
  *((int *)&__m256_op1[1]) = 0xffffffff;
  *((int *)&__m256_op1[0]) = 0xffffffff;
  *((int *)&__m256_result[7]) = 0xffffffff;
  *((int *)&__m256_result[6]) = 0xffffffff;
  *((int *)&__m256_result[5]) = 0xffffffff;
  *((int *)&__m256_result[4]) = 0xffffffff;
  *((int *)&__m256_result[3]) = 0xffffffff;
  *((int *)&__m256_result[2]) = 0xffffffff;
  *((int *)&__m256_result[1]) = 0xffffffff;
  *((int *)&__m256_result[0]) = 0xffffffff;
  __m256_out = __lasx_xvfdiv_s (__m256_op0, __m256_op1);
  ASSERTEQ_32 (__LINE__, __m256_result, __m256_out);

  return 0;
}