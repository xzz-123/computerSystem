/*
 * 家庭作业 2.78
 *
 * 写出函数 mul5div8 的代码，对于整数参数 x，计算 5*x/8，但是要遵循位级整数编
 * 码规则。你的代码计算 5*x 也会产生溢出。
*/
#include <stdio.h>
#include <limits.h>
#include <assert.h>



int mul5div8(int x) {
	int mul3 = (x << 2) + x;
	int bias = (mul3 >> 31) & ((1 << 3) - 1);
	return (bias + mul3) >> 3;
}


//int main() {
//	int t = 0x7fffffff;
//	assert(mul5div8(t) == (t * 5 / 8));
//	return 0;
//}