#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
 * 这个题目非常有意思，要保证不溢出，就要先做除法，也就是先除以8再乘以5
 * 在下边中用到了一个非常巧妙的地方，把一个整数进行拆分
 */

 /*
  * calculate 5/8x, no overflow, round to zero
  *
  * no overflow means divide 8 first, then multiple 5, diffrent from 2.78 here
  *
  * rounding to zero is a little complicated.
  * every int x, equals f(first 30 bit number) plus l(last 2 bit number)
  *
  *   f = x & ~0x3
  *   l = x & 0x3
  *   x = f + l
  *   fiveeights(x) = f/8*5 + l*5/8
  *
  * f doesn't care about round at all, we just care about rounding from l*5/8
  *
  *   lm5 = (l << 2) + l
  *
  * when x > 0, rounding to zero is easy
  *
  *   lm5d8 = lm5 >> 2
  *
  * when x < 0, rounding to zero acts like divide_power2 in 2.77
  *
  *   bias = 0x7    // (1 << 3) - 1
  *   lm5d8 = (lm5 + bias) >> 3
  */

int fiveeights(int x) {
	int is_neg = x & INT_MIN;

	int f = x & ~0x3;
	int l = x & 0x3;

	int fd8 = f >> 3;
	int fd8m5 = (fd8 << 2) + fd8;

	int lm5 = (l << 2) + l;
	int bias = (1 << 3) - 1;
	(is_neg && (lm5 += bias));
	int lm5d8 = lm5 >> 3;

	return fd8m5 + lm5d8;
}

