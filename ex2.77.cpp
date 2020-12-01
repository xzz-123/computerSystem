/*
 * 家庭作业 2.77
 *
 * 写出具有如下原型的函数的代码：
 *
 * // Divide by power of two.  Assume 0 <= k < w-1
 * int divide_power2(int x, int k);
 *
 * 该函数要用正确的舍入计算 x/2^k，并且应该遵循位级整数编码规则。
 */
int divide_power2(int x, int k) {
	
	int bias = (x >> 31) & ((1 << k ) - 1);
	return (bias + x) >> k;
}

//int main() {
//	int x = divide_power2(-16, 2);
//	return 0;
//}
/*公式在书上，这题的关键是怎么不用测试或条件得到偏置
受练习题2.42的启发，
若x<0，那么x>>31得到全1， 再& ((1 << k ) - 1) 得到偏置，
若x>0，那么x>>31得到全0， 再& ((1 << k ) - 1) 为0，
*/