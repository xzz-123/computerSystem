/*
 * ��ϰ�� 2.63
 *
 * ������� C �������벹������������ srl ���������ƣ���ֵ xsra ������������߼���
 * �ƣ�����������������������ƻ��߳��������� sra ���߼����ƣ���ֵ xsrl ��������
 * ����������ƣ�����������������������ƻ��߳���������ͨ������8*sizeof(int) ��ȷ
 * ���������� int �е�λ�� w��λ���� k ��ȡֵ��Χλ 0~w-1��
 */
static int w = sizeof(int) << 3;

int sra(int x, int k)
{
	/* Perform shift logically */
	int xsrl = (unsigned)x >> k;
	// (1 << (w - 1 - k)) & xsrl �õ�x�������Чλ

	int sign = ((1 << (w - 1 - k)) & xsrl) << 1;
	int t = ~((1 << (w - k)) - 1); /* t=[11...1100...00], w-1...w-k λȫ 1 */
	// 1 << (w - k)=[00...0100...00]
	/*
	 * sign = 0, sign ^ (1 << (w - k))=[00...0100...00], n = 0
	 * sign = [0...010...0], sign ^ (1 << (w - k))=0, n = t
	 */
	int n = t + (sign ^ (1 << (w - k)));

	return n + xsrl;
}

unsigned srl(unsigned x, int k)
{
	/* Perform shift arithmetically */
	unsigned xsra = (int)x >> k;
	return xsra & ((1 << (w - k)) - 1);
	// (1 << (w - k))=[00...0100...00];
	// (1 << (w - k))-1=[00...0011...11];
	//������ʹw-1...w-kλȫΪ0��w-k-1...0λȫΪ1
}