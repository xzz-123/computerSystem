/*
 * ��ϰ�� 2.68
 *
 * д����������ԭ�͵ĺ����Ĵ���
 *
 * Make with least signficant n bits set to 1
 * Example: n = 6 --> 0x3f, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 *
 *         int lower_bits(int x, int n);
 *
 * ����Ӧ����ѭλ�������������Ҫע�� n = w �����
 */
#include <stdio.h>
int lower_bits(int x, int n)
{
	int r = 0;
	int s = n - 1;

	/* 1. ����һ����� n λΪ 1 ���� */
	r = (1 << s) - 1 + (1 << s);

	/* 2. ���������ԭ�������ֽ�����������Ϊ������� */
	return x & r;
}

//int main() {
//	int i=lower_bits(0x78abcdef, 8);
//	printf("%.2x", i);
//}