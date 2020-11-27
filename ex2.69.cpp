/*
 * ��ϰ�� 2.69
 *
 * Do rotating right shift.  Assume 0 <= n < w
 * Example when x = 0x12345678 and w=32:
 *     n=4 -> 0x81234567, n=20 -> 0x45678123
 *
 * ����Ӧ����ѭλ�������������Ҫע�� n = 0 �������
 */
#include <stdio.h>

unsigned rotate_right(unsigned x, int n) {
	int w = sizeof(int) << 3;
	return (x << (w - n - 1) << 1) + (x >> n);
	/*����֮���Բ�ֱ��x<<w-n����Ϊ����n=0��x<<w��δ�����*/
}

//int main() {
//	int x = 0x12345678;
//	printf("%.2x",rotate_right(x,4) );
//}