/*
 * д������ʵ�����º�����
 *
 * Return 1 when any even bit of x equals 1; 0 otherwise.  Assume w=32
 *
 *         int any_even_one(unsigned x);
 *
 * ����Ӧ����ѭλ������������򣬲�������Լ����������� int �� w=32 λ��
 */
//���ż��λ����1����(x & 0xaaaaaaaa)ֵΪһ���������������Σ������1��
//���ż��λ��û��1����(x & 0xaaaaaaaa)ֵΪ0��������ʹ�ã����㣬���0��
int any_even_one(unsigned x)
{
	return !!(x & 0x55555555) ;
}

