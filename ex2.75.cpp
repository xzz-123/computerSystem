/*
 * 家庭作业 2.75
 *
 * 假设我们想要计算 x·y 的完整的 2w 位表示，其中，x 和 y 都是无符号数，并且运
 * 行在数据类型 unsigned 是 w 位的机器上。乘积的低 w 位能够用表达式 x·y 计算，
 * 所以，我们只需要一个具有下列原型的函数：
 *
 * unsigned unsigned_high_prod(unsigned x, unsigned y);
 *
 * 这个函数计算无符号变量 x·y 的高 w 位。
 * 我们使用一个具有下面原型的库函数：
 *
 * int signed_high_prod(int x, int y);
 *
 * 它计算在 x 和 y 采用补码形式的情况下，x·y 的高 w 位。编写代码调用这个过程，
 * 以实现用无符号数为参数的函数。验证你的解答的正确性。
 *
 * 提示：看看等式（2-18）的推导中，有符号乘积 x·y 和无符号乘积 x'·y' 之间的关
 * 系。
 */
 /*
	 这个问题需要一步一步的进行推导
	 T2Uw(x)为补码转无符号数：
	 
	 if x < 0  => x + 2^w
	 if x > 0  => x
	 可以写成
	 T2Uw(X)= X + X(w-1)2^w

	 这个式子跟上边的那个作用一样，x的w-1位就是他的最高位，如果该位的值是1，那么就相当于
	 x<0的情况，否则就是另一种情况

	 我们假设x'表示x的无符号值
	 X' = X + X(w-1)2^w

	 我们假设y`表示x的无符号值
	 Y' = Y + Y(w-1)2^w

	 那么X'* Y' = (X + X(w-1)2^w) * (Y + Y(w-1)2^w)
	 如果要把这个计算式展开会很麻烦，我们可以进一步抽象
	 设a = X(w-1)2^w, b= Y(w-1)2^w
	 则： X' * Y' = X*Y + X*b + Y*a + a*b

	 我们假定有这样一个函数，他的功能是取出无符号数的最高位uh(),因此上边的式子变形为：
	 uh(X' * Y') = uh(X*Y + X*b + Y*a + a*b)
				 = uh(X*Y) + uh(X*b) + uh(Y*a) + uh(a*b)

	 那么X * b 也就是X*b= X*Y(w-1)2^w 他的最高位的值就是X*Y(w-1)2^w / 2^w => X*Y(w-1)
	 那么Y * a 也就是Y*a= Y*X(w-1)2^w 他的最高位的值就是Y*X(w-1)2^w / 2^w => Y*X(w-1)
	 那么a * b 也就是a*b= X(w-1)2^w * Y(w-1)2^w 他 / 2^w => 0

	 ===> uh(X` * Y`) = uh(X*Y) + X*Y(w-1) + Y*X(w-1)

	 上边推理的核心思想就是 无符号X`的补码表示：X + X(w-1)2^w 求高位的/ 2^w 操作
 */

 /*
  * unsigned-high-prod.c
  */
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int signed_high_prod(int x, int y) {
	int64_t mul = (int64_t)x * y;
	return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
	/* TODO calculations */
	int sig_x = x >> 31;
	int sig_y = y >> 31;
	int signed_prod = signed_high_prod(x, y);
	return signed_prod + x * sig_y + y * sig_x;
}

/* a theorically correct version to test unsigned_high_prod func */
unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
	uint64_t mul = (uint64_t)x * y;
	return mul >> 32;
}

//int main(int argc, char* argv[]) {
//	unsigned x = 0xffffffff;
//	unsigned y = 0xFFFFFFFF;
//
//	assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
//	return 0;
//}