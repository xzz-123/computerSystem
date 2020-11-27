
/*
 * ��ϰ�� 2.70
 *
 * д����������ԭ�͵ĺ����Ĵ��룺
 *
 * Return 1 when x can be represented as an n-bit, 2's complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 *
 *         int fits_bits(int x, int n);
 *
 * ����Ӧ����ѭλ�������������
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
  *  0b11111000��000��ʾ�Ļ���000!=0b11111000,0b11111100��100��ʾ��100==0b11111100
  */
#include <stdio.h>
int fits_bits(int x, int n)
{
	/* 1. ����λ w-1...n-1 ȫ 1��λ n-2...0 ȫ 0 ��λ���� */
	int s = ~((1 << (n - 1)) - 1);

	/* 2. �� x �ĵ� n-1 λ���㣬����λ���� */
	x &= s;

	/* 3. ��ʱ��w...n λ��ȫ 0 ����ȫ 1���ſ����� n λ�����ʾ����� */
	return !x || !(x ^ s);
}

int main() {
	int x = 0xfeffffff;
	int a = fits_bits(x,16);
}