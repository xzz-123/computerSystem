/*
 * ��ϰ�� 2.73
 *
 * Addition that saturates to TMin or TMax
 *
 * ͬ�����Ĳ�������ķ�ʽ��ͬ���������ʱ��saturating_add ���� TMax�������ʱ����
 * �� TMin���������㳣������ִ�������źŴ���ĳ����С�
 *
 * ��ĺ���Ӧ����ѭλ�������������
 */
#include <limits>
 int saturating_add(int x, int y)
{
	 int sum = x + y;
	 int sig_mask = INT_MIN;
	 //x>0,y>0,sum<0,�����
	 bool pos_over = !(x&sig_mask) && !(y&sig_mask) && (sum&sig_mask);
	 //x<0,y<0,sum>0,�����
	 bool neg_over = (x&sig_mask) && (y&sig_mask) && !(sum&sig_mask);
	 //����ط��Ҿ��ú�������pos_over��ôsum����INT_MAX,��������ж��Ƿ����
	 //���û�����sum���䡣
	 (pos_over && (sum = INT_MAX) )|| (neg_over && (sum = INT_MIN));

	 return sum;
}