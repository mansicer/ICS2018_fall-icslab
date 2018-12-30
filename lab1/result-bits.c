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
editing the collection OF functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines OF C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description OF how your implementation works */
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
    
  Some OF the problems restrict the set OF allowed operators even further.
  Each "Expr" may consist OF multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form OF casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations OF integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability OF shifts to compute powers OF 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability OF shifts to compute powers OF 2 */
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
  4. Use any form OF casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality OF your solutions.
  2. Each function has a maximum number OF operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation OF the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many OF these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number OF ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free SOFtware Foundation, Inc.
   This file is part OF the GNU C Library.

   The GNU C Library is free sOFtware; you can redistribute it and/or
   modify it under the terms OF the GNU Lesser General Public
   License as published by the Free SOFtware Foundation; either
   version 2.1 OF the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty OF
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy OF the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start OF every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name OF this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 9.0.0.  Version 9.0 OF the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, fourth edition, plus
   Amd. 1  and Amd. 2 and 273 characters from forthcoming  10646, fifth edition.
   (Amd. 2 was published 2016-05-01,
   see https://www.iso.org/obp/ui/#iso:std:iso-iec:10646:ed-4:v1:amd:2:v1:en) */
/* We do not support C11 <threads.h>.  */
/*
 * bitParity - returns 1 if x contains an odd number OF 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  int tmp;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x &= 0xf;
  tmp = (0x69 << 8) | (0x96);
  return (tmp >> x) & 1;
}
/* 将x分为两段异或不会改变奇偶性，最后构造0x6996判断奇偶性 */
/* 
 * float_half - Return bit-level equivalent OF expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation OF
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  unsigned tmp;
  unsigned frac = uf % (0x800000);
  unsigned exp = (uf >> 23) % (0x100);
  unsigned sign = uf >> 31;
  if (exp == 0xff)
    return uf;
  if (exp == 0)
  {
    tmp = frac >> 1;
    if (frac % 2 == 1 && tmp % 2 == 1)
      frac = tmp + 1;
    else
      frac = tmp;
  }
  else
  {
    frac = frac + (1 << 23);
    tmp = frac >> 1;
    exp--;
    if (exp == 0)
    {
      if (frac % 2 == 1 && tmp % 2 == 1)
        frac = tmp + 1;
      else
        frac = tmp;
    }
  else
      frac = frac & 0x7fffff;
  }
  return (sign << 31) + (exp << 23) + frac;
}
/* 如果是规格化数，将阶码-1，如果变成了非规格化数再重新处理；
如果是非规格化数，将尾数右移一位；
如果阶码为全1则直接返回 */
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
  int n = 0xaa;
  n |= n<<8;
  n |= n<<16;
  return n;
}
/* 构造数0xaaaaaaaa */
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  int n = 0x49;
  n |= (0x92 << 8);
  n |= (0x24 << 16);
  n |= (0x49 << 24);
  return n;
}
/* 构造数0x49249249 */
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  int res = ~(0 ^ (0xff << (n<<3)));
  res &= x;
  res |= (c << (n<<3));
  return res;
}
/* 将需要替代的字节置0，再将用来替代的数覆盖上去 */
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
/* 取反加一从而取得负值 */
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
  int tmp = ~0 << n;
  int temp = x & ~tmp;
  return temp + (((x & (~temp + 1)) >> 31) & tmp);
}
/* 取出后n位的数字，再根据符号正负进行处理 */
/* 
 * float_f2i - Return bit-level equivalent OF expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation OF a
 *   single-precision floating point value.
 *   Anything out OF range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  int exp = 0x7f800000 & uf;
  int frac = (0x007FFFFF & uf) + 0x00800000;
  unsigned flag = 0x80000000 & uf;
  int n = (exp >> 23) - 127;
  if (exp == 0)
    return 0;
  else if (n < 0 && n >= -126)
    return 0;
  else if (n <= 23)
    frac = frac >> (23 - n);
  else if (n >= 31)
    return 0x80000000;
  else
    frac = frac << (exp - 23);
  if (flag == 0)
    return frac;
  else
    return -frac;
}
/* 阶码过小时，直接返回0；
阶码过大时，直接返回0x80000000
其他情况根据阶码的大小转换尾数 */
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
  int tmp = x >> n;
  int temp;
  tmp = ~(~0 << (32 + ~n +1)) & tmp;
  temp = x << (32 + ~n + 1);
  return tmp | temp;
}
/* 先取出前(32 - n)位，再将低n位处理到高n位，最后将两部分整合 */
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
  int tmp = x >> 31;
  return !(((~x & tmp) + (x & ~tmp)) >> (n + ~0));
}
/* 根据符号位的不同，若x可用n位补码表示，
若x为正则n位以上都是0，若n为负则n位以上都是1 */
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
  int tmp = x + y;
	int OF = ((x ^ tmp) & (y ^ tmp)) >> 31;
	return (tmp >> (OF & 31)) + (OF << 31);
}
/* 通过OF判断是否溢出，若溢出则对结果进行处理 */
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return !((x + 1) ^ (~x)) & !!(~x ^ 0);
}
/* 如果x取反等于x+1，且x不等于-1，其即为最大正数 */