/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the gradescope autograder and your own tester to check your functions for correctness.
  4. Use the dlc program to check if your functions meet the constraints on the
     maximum number of ops and permissible operators.
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the gradescope autograder to check for logical correctness 
 */


#endif
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
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return (~(~x | ~y));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return (0xFF & (x >> (n << 3)));
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  return (x >> n) ^ (((x & (1 << 31)) >> n) << 1);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
        int sum = 0;
        int help = 1;

        sum = sum + (x & help);
        sum = sum + (x >> 1 & help);
        sum = sum + (x >> 2 & help);
        sum = sum + (x >> 3 & help);
        sum = sum + (x >> 4 & help);
        sum = sum + (x >> 5 & help);
        sum = sum + (x >> 6 & help);
        sum = sum + (x >> 7 & help);
        sum = sum + (x >> 8 & help);
        sum = sum + (x >> 9 & help);
        sum = sum + (x >> 10 & help);
        sum = sum + (x >> 11 & help);
        sum = sum + (x >> 12 & help);
        sum = sum + (x >> 13 & help);
        sum = sum + (x >> 14 & help);
        sum = sum + (x >> 15 & help);
        sum = sum + (x >> 16 & help);
        sum = sum + (x >> 17 & help);
        sum = sum + (x >> 18 & help);
        sum = sum + (x >> 19 & help);
        sum = sum + (x >> 20 & help);
        sum = sum + (x >> 21 & help);
        sum = sum + (x >> 22 & help);
        sum = sum + (x >> 23 & help);
        sum = sum + (x >> 24 & help);
        sum = sum + (x >> 25 & help);
        sum = sum + (x >> 26 & help);
        sum = sum + (x >> 27 & help);
        sum = sum + (x >> 28 & help);
        sum = sum + (x >> 29 & help);
        sum = sum + (x >> 30 & help);
        sum = sum + (x >> 31 & help);
        return(sum);
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
 int negation = ~x + 1;
 return((((x >> 31) & 0x01) | ((negation >> 31) & 0x01)) ^ 0x01);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (0x80 << 24);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int mask = x >> 31;
  return !(((~x & mask) + (x & ~mask)) >> (n + ~0));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    // Something is needed to account for x >> n if positive and x >> n + 1 if negative

	// Subtract 1 from 2^n
	// This accounts for the need to + 1
	int mask = (1 << n) + ~0;

	// Use & operator on mask and sign bit of x 
	int equalizer = (x >> 31) & mask;

	// Adds 1 if x was originally negative
	// Adds 0 if x was originally positive
	return (x + equalizer) >> n;
}
/* 
 * negate - return -x 
 * You may handle results that fall out of signed int range in any way that you
 * like
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return !((x >> 31) | !x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int x_sign=(x>>31) & 0x01;				//declaration
 int y_sign=(y>>31) & 0x01;				//declaration
 int checksign = x_sign ^ y_sign;		//check same sign(0) or differ sign(1)
 int check1 = checksign & x_sign;		//when differ sign, x_sign is 1, alway x is less
 int check0 = !checksign & (((x + ~y)>> 31 ) & 0x01);		//when same sign and x is less or equal, x-y-1's sign bit is 1
 return (check0 | check1);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  return 2;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 unsigned exp = uf >> 23 & 0xFF;
 unsigned frac = uf << 9;
 //return argument if it's NaN value
 if((exp == 0xFF) & (frac != 0)) {
  return uf;
 }
 return uf ^ 0x80000000;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int tx = x;
	unsigned result = 0; //= x & (1<<31);
	//b will be the sign bit with 31 times left shifted.
	int b = x&0x80000000;
	int cc = 0x7f;
	int qtx;
	int lastbit;
	int mask;
	int f,f1,f2,g,h,i,rr,q,lbx;
	if(x==0) return 0; //special case 1 : x is 0.
	if(x == 0x80000000) { //special case 2 : x is tmin. we can't negate this value.
		return 0xcf000000;
	}
	result = result | b; // mark sign bit.
	if(b) {
		tx = -x; // let's consider only positive value.
	}
	qtx = tx;
	while(qtx/=2) { // get E value.
		cc=cc+1;
	}
	//cc will be Exp value.
	lastbit = cc-0x7f; //last bit is E value.
	mask = (1<<lastbit) - 1;
	//get other bit under 'lastbit'.
	q = (mask & tx);
	lbx = 23-lastbit;
	if(lastbit<=23) {
		//less than 24 bits remain, then, M is just q<<lbx.
		result = result + (q<<lbx);
	} else {
		f = -lbx;
		f1 = f-1;
		f2 = 1<<f1;
		g = q & (f2-1);
		h = q & (1<<(f));
		i = q & (f2);
		rr = q >> (f);
		//rounding.
		//g : check under (lastbit-25) bit. if g is non-zero, there is a bit under the (lastbit-25) bit.
		//h : check (lastbit-23) bit. if h is non-zero, even-rounding is possible.
		//i : check (lastbit-24) bit. it's essential for round-up.
		rr = rr + (i && (g || h));	
		result = result | rr;
	}
	//add Exp bits.
	result = result + (cc<<23);
	return result;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
 unsigned exp = uf >> 23 & 0xFF;
 unsigned frac = uf << 9;
 unsigned sign = uf >> 31 << 31;
 unsigned expOne = 1 << 23; //1 more in exp
 //return argument if it's NaN value
 if((exp == 0xFF) & (frac != 0)) {
  return uf;
 }
 if(exp == 0) {
  return (uf << 1 + sign);
 }
 else {
  exp = exp + expOne;
 }
 return sign|exp|frac;
}

