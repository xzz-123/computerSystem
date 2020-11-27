
/*
 * 练习题 2.70
 *
 * 写出具有如下原型的函数的代码：
 *
 * Return 1 when x can be represented as an n-bit, 2's complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 *
 *         int fits_bits(int x, int n);
 *
 * 函数应该遵循位级整数编码规则。
 */

 /*
  * Assume w = 8, n = 3
   * if x > 0
   *   0b00000010 is ok, 0b00000110 is not
   *   n-1~w-1 must be 0
   * if x < 0
   *   0b11111100 is ok, 0b10111100 is not, and 0b11111000 is not yet
   *    n-1~w-1 must be 1
  *  0b00000110!=110
  *  0b11111000用000表示的话，000!=0b11111000,0b11111100用100表示，100==0b11111100
  */
#include <stdio.h>
int fits_bits(int x, int n)
{
	/* 1. 构造位 w-1...n-1 全 1，位 n-2...0 全 0 的位向量 */
	int s = ~((1 << (n - 1)) - 1);

	/* 2. 将 x 的低 n-1 位置零，其他位保留 */
	x &= s;

	/* 3. 此时，w...n 位是全 0 或者全 1，才可以用 n 位补码表示这个数 */
	return !x || !(x ^ s);
}

int main() {
	int x = 0xfeffffff;
	int a = fits_bits(x,16);
}