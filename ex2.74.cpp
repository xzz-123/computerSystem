/*
 * 练习题 2.74
 *
 * 写出具有如下原型的函数的代码：
 *
 * // Determine whether subtracting arguments will cause overflow
 * int tsub_ovf(int x, int y);
 *
 * 如果计算 x-y 导致溢出，这个函数就返回 1。
 *
 */
#include <limits>
int tsub_ovf(int x, int y) {
	int diff = x - y;
	
	bool pos_over = !(x&INT_MIN) && (y&INT_MIN) && (diff&INT_MIN);
	bool neg_over = (x&INT_MIN) && !(y&INT_MIN) && !(diff&INT_MIN);

	return pos_over || neg_over;
}

//int main() {
//	int x = INT_MIN;
//	int a = tsub_ovf(-1, x);
//	while (true)
//	{
//	}
//}
