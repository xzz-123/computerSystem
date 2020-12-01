/*
 * 练习题 2.73
 *
 * Addition that saturates to TMin or TMax
 *
 * 同正常的补码溢出的方式不同，当正溢出时，saturating_add 返回 TMax，负溢出时，返
 * 回 TMin。这种运算常常用在执行数字信号处理的程序中。
 *
 * 你的函数应该遵循位级整数编码规则。
 */
#include <limits>
 int saturating_add(int x, int y)
{
	 int sum = x + y;
	 int sig_mask = INT_MIN;
	 //x>0,y>0,sum<0,正溢出
	 bool pos_over = !(x&sig_mask) && !(y&sig_mask) && (sum&sig_mask);
	 //x<0,y<0,sum>0,负溢出
	 bool neg_over = (x&sig_mask) && (y&sig_mask) && !(sum&sig_mask);
	 //这个地方我觉得很巧妙，如果pos_over那么sum等于INT_MAX,否则继续判断是否负溢出
	 //如果没溢出就sum不变。
	 (pos_over && (sum = INT_MAX) )|| (neg_over && (sum = INT_MIN));

	 return sum;
}