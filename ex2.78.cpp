/*
 * ��ͥ��ҵ 2.78
 *
 * д������ mul5div8 �Ĵ��룬������������ x������ 5*x/8������Ҫ��ѭλ��������
 * �������Ĵ������ 5*x Ҳ����������
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