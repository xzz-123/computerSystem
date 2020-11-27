/*
 * ��ϰ�� 2.66
 *
 * Generate mask indicating leftmost 1 in x.  Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6000 -> 0x4000.
 * If x = 0, then return 0.
 *
 *         int leftmost_one(unsigned x);
 *
 * ����Ӧ����ѭλ������������򣬲�������Լ����������� int �� w=32 λ��
 * ��Ĵ������ֻ�ܰ��� 15 ���������㡢λ������߼����㡣
 *
 * ��ʾ���Ƚ� x ת�������� [0...011...1] ��λ������
 */
int leftmost_one(unsigned x)
{
	x |= x >> 16;
	x |= x >> 8;
	x |= x >> 4;
	x |= x >> 2;
	x |= x >> 1;

	/* ���ϵĴ��뽫��� x ת�������� [0...01...1] ����ʽ */
	return x ^= (x >> 1);
}

