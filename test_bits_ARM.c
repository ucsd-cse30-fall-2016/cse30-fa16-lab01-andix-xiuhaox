/* Testing Code */

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "bits_ARM.h"

/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */

int test_bitAnd_ARM(int x, int y)
{
   return x&y;
}

int test_getByte_ARM(int x, int n)
{
   unsigned char byte;
    switch(n) {
    case 0:
      byte = x;
      break;
    case 1:
      byte = x >> 8;
      break;
    case 2:
      byte = x >> 16;
      break;
    default:
      byte = x >> 24;
      break;
    }
    return (int) (unsigned) byte;
}

int test_logicalShift_ARM(int x, int n) {
   unsigned u = (unsigned) x;
  unsigned shifted = u >> n;
  return (int) shifted;
}


int test_bitCount_ARM(int x) {
   int result = 0;
  int i;
  for (i = 0; i < 32; i++)
    result += (x >> i) & 0x1;
  return result;
}

int test_fitsBits_ARM(int x, int n)
{
   int TMin_n = -(1 << (n-1));
  int TMax_n = (1 << (n-1)) - 1;
  return x >= TMin_n && x <= TMax_n;
}

int test_negate_ARM(int x) {
   return -x;
}

int test_isLessOrEqual_ARM(int x, int y)
{
    int mask, result;
  /* find the leftmost bit */
  result = 31;
  mask = 1 << result;
  while (!(x & mask)) {
    result--;
    mask = 1 << result;
  }
  return result;
}


int main(int argc, char *argv[]){

//Test Cases for bitAnd_ARM

assert(bitAnd_ARM(7,8)==test_bitAnd_ARM(7,8)); 
assert(bitAnd_ARM(1,3)==test_bitAnd_ARM(1,3));
assert(bitAnd_ARM(9,8)==test_bitAnd_ARM(9,8));
assert(bitAnd_ARM(0,6)==test_bitAnd_ARM(0,6));
assert(bitAnd_ARM(255,254)==test_bitAnd_ARM(255,254));
printf("Passed Test Cases for bitAnd_ARM\n");
/* To do: Run other test cases here */
   
//Test Cases for getByte_ARM 

assert(getByte_ARM(0x12345678,1)==test_getByte_ARM(0x12345678,1)); 
assert(getByte_ARM(0x12345678,0)==test_getByte_ARM(0x12345678,0));
assert(getByte_ARM(1000000,2)==test_getByte_ARM(1000000,2));
assert(getByte_ARM(1000000,3)==test_getByte_ARM(1000000,3));
printf("Passed Test Cases for getByte_ARM\n");
  
//Test Cases for logicalShift_ARM 

assert(logicalShift_ARM(0x87654321,4)==test_logicalShift_ARM(0x87654321,4)); 
assert(logicalShift_ARM(0x87654321,8)==test_logicalShift_ARM(0x87654321,8));
assert(logicalShift_ARM(0x3213143,4)==test_logicalShift_ARM(0x3213143,4));
assert(logicalShift_ARM(0x3213143,16)==test_logicalShift_ARM(0x3213143,16));
printf("Passed Test Cases for logicalShift_ARM\n");
  
//Test Cases for bitCount_ARM 

assert(bitCount_ARM(5)==test_bitCount_ARM(5)); 
assert(bitCount_ARM(11)==test_bitCount_ARM(11));
assert(bitCount_ARM(21)==test_bitCount_ARM(21));
assert(bitCount_ARM(7)==test_bitCount_ARM(7));
printf("Passed Test Cases for bitCount_ARM\n");
   
//Test Cases for fitsBits_ARM 

assert(fitsBits_ARM(5,3)==test_fitsBits_ARM(5,3)); 
assert(fitsBits_ARM(-4,3)==test_fitsBits_ARM(-4,3));
assert(fitsBits_ARM(7,2)==test_fitsBits_ARM(7,2));
assert(fitsBits_ARM(11,4)==test_fitsBits_ARM(11,4));
printf("Passed Test Cases for fitsBits_ARM\n");
   
//Test Cases for negate_ARM 

assert(negate_ARM(15)==test_negate_ARM(15)); 
assert(negate_ARM(3)==test_negate_ARM(3));
assert(negate_ARM(7)==test_negate_ARM(7));
printf("Passed Test Cases for negate_ARM\n");
   
//Test Cases for isLessOrEqual_ARM 

assert(isLessOrEqual_ARM(15,20)==test_isLessOrEqual_ARM(15,20)); 
assert(isLessOrEqual_ARM(-33,2)==test_isLessOrEqual_ARM(-33,2));
assert(isLessOrEqual_ARM(7,1)==test_isLessOrEqual_ARM(7,1));
assert(isLessOrEqual_ARM(2,-10)==test_isLessOrEqual_ARM(2,-10));
printf("Passed Test Cases for isLessOrEqual_ARM\n");

return 0;

}
