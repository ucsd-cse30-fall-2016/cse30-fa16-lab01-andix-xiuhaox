/* Testing Code */

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "bits.h"

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

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

int test_bitAnd(int x, int y)
{
  return x&y;
}
int test_getByte(int x, int n)
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
int test_logicalShift(int x, int n) {
  unsigned u = (unsigned) x;
  unsigned shifted = u >> n;
  return (int) shifted;
}
int test_bitCount(int x) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i++)
    result += (x >> i) & 0x1;
  return result;
}
int test_bang(int x)
{
  return !x;
}
int test_tmin(void) {
  return 0x80000000;
}
int test_fitsBits(int x, int n)
{
  int TMin_n = -(1 << (n-1));
  int TMax_n = (1 << (n-1)) - 1;
  return x >= TMin_n && x <= TMax_n;
}
int test_divpwr2(int x, int n)
{
    int p2n = 1<<n;
    return x/p2n;
}
int test_negate(int x) {
  return -x;
}
int test_isPositive(int x) {
  return x > 0;
}
int test_isLessOrEqual(int x, int y)
{
  return x <= y;
}
int test_ilog2(int x) {
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
unsigned test_float_neg(unsigned uf) {
    float f = u2f(uf);
    float nf = -f;
    if (isnan(f))
 return uf;
    else
 return f2u(nf);
}
unsigned test_float_i2f(int x) {
  float f = (float) x;
  return f2u(f);
}
unsigned test_float_twice(unsigned uf) {
  float f = u2f(uf);
  float tf = 2*f;
  if (isnan(f))
    return uf;
  else
    return f2u(tf);
}


int main(int argc, char *argv[]){

//Test Cases for bitAnd 

assert(bitAnd(7,8)==test_bitAnd(7,8)); 
assert(bitAnd(1,3)==test_bitAnd(1,3));
assert(bitAnd(9,8)==test_bitAnd(9,8));
assert(bitAnd(0,6)==test_bitAnd(0,6));
assert(bitAnd(255,254)==test_bitAnd(255,254));
printf("Passed Test Cases for bitAnd\n");
  
//Test Cases for getByte 

assert(getByte(0x12345678,1)==test_getByte(0x12345678,1)); 
assert(getByte(0x12345678,0)==test_getByte(0x12345678,0));
assert(getByte(1000000,2)==test_getByte(1000000,2));
assert(getByte(1000000,3)==test_getByte(1000000,3));
printf("Passed Test Cases for getByte\n");
  
//Test Cases for logicalShift 

assert(logicalShift(0x87654321,4)==test_logicalShift(0x87654321,4)); 
assert(logicalShift(0x87654321,8)==test_logicalShift(0x87654321,8));
assert(logicalShift(0x3213143,4)==test_logicalShift(0x3213143,4));
assert(logicalShift(0x3213143,16)==test_logicalShift(0x3213143,16));
printf("Passed Test Cases for logicalShift\n");
  
//Test Cases for bitCount 

assert(bitCount(5)==test_bitCount(5)); 
assert(bitCount(11)==test_bitCount(11));
assert(bitCount(21)==test_bitCount(21));
assert(bitCount(7)==test_bitCount(7));
printf("Passed Test Cases for bitCount\n");
  
//Test Cases for bang 

assert(bang(3)==test_bang(3)); 
assert(bang(0)==test_bang(0));
assert(bang(5)==test_bang(5));
assert(bang(11)==test_bang(11));
printf("Passed Test Cases for bang\n");
  
//Test Cases for tmin 

assert(tmin()==test_tmin()); 
printf("Passed Test Cases for tmin\n");
  
//Test Cases for fitsBits 

assert(fitsBits(5,3)==test_fitsBits(5,3)); 
assert(fitsBits(-4,3)==test_fitsBits(-4,3));
assert(fitsBits(7,2)==test_fitsBits(7,2));
assert(fitsBits(11,4)==test_fitsBits(11,4));
printf("Passed Test Cases for fitsBits\n");
  
//Test Cases for divpwr2 

assert(divpwr2(15,1)==test_divpwr2(15,1)); 
assert(divpwr2(-33,4)==test_divpwr2(-33,4));
assert(divpwr2(7,2)==test_divpwr2(7,2));
assert(divpwr2(11,2)==test_divpwr2(11,2));
printf("Passed Test Cases for divpwr2\n");
  
//Test Cases for negate 

assert(negate(15)==test_negate(15)); 
assert(negate(3)==test_negate(3));
assert(negate(7)==test_negate(7));
printf("Passed Test Cases for negate\n");
  
//Test Cases for isPositive 

assert(isPositive(15)==test_isPositive(15)); 
assert(isPositive(-33)==test_isPositive(-33));
assert(isPositive(7)==test_isPositive(7));
assert(isPositive(0)==test_isPositive(0));
printf("Passed Test Cases for isPositive\n");
  
//Test Cases for isLessOrEqual 

assert(isLessOrEqual(15,20)==test_isLessOrEqual(15,20)); 
assert(isLessOrEqual(-33,2)==test_isLessOrEqual(-33,2));
assert(isLessOrEqual(7,1)==test_isLessOrEqual(7,1));
assert(isLessOrEqual(2,-10)==test_isLessOrEqual(2,-10));
printf("Passed Test Cases for isLessOrEqual\n");
  
//Test Cases for ilog2 

assert(ilog2(16)==test_ilog2(16)); 
assert(ilog2(4)==test_ilog2(4));
assert(ilog2(7)==test_ilog2(7));
assert(ilog2(2)==test_ilog2(2));
printf("Passed Test Cases for ilog2\n");

//Test Cases for float_neg 

assert(float_neg(16)==test_float_neg(16)); 
assert(float_neg(4)==test_float_neg(4));
assert(float_neg(7)==test_float_neg(7));
assert(float_neg(2)==test_float_neg(2));
printf("Passed Test Cases for float_neg\n");
  
//Test Cases for float_i2f 

assert(float_i2f(16)==test_float_i2f(16)); 
assert(float_i2f(4)==test_float_i2f(4));
assert(float_i2f(7)==test_float_i2f(7));
assert(float_i2f(2)==test_float_i2f(2));
printf("Passed Test Cases for float_i2f\n");
  
//Test Cases for float_twice 

assert(float_twice(16)==test_float_twice(16)); 
assert(float_twice(4)==test_float_twice(4));
assert(float_twice(7)==test_float_twice(7));
assert(float_twice(2)==test_float_twice(2));
printf("Passed Test Cases for float_twice\n");
  


return 0;

}
