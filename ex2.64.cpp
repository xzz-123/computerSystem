/*
 * 写出代码实现如下函数：
 *
 * Return 1 when any even bit of x equals 1; 0 otherwise.  Assume w=32
 *
 *         int any_even_one(unsigned x);
 *
 * 函数应该遵循位级整数编码规则，不过你可以假设数据类型 int 有 w=32 位。
 */
//如果偶数位上有1，则(x & 0xaaaaaaaa)值为一个非零数，再两次！，变成1；
//如果偶数位上没有1，则(x & 0xaaaaaaaa)值为0，再两次使用！运算，变成0；
int any_even_one(unsigned x)
{
	return !!(x & 0x55555555) ;
}

