/*
 * ��ϰ�� 2.67
 *
 * ����һ�����񣬱�дһ������ int_size_is_32()������һ�� int �� 32 λ�Ļ�����
 * ����ʱ���ó������ 1���������������� 0��������ʹ�� sizeof �������������
 * ��ʼʱ�ĳ��ԣ�
 *
 * // The following code does not run properly on some machines
 * int bad_int_size_is_32() {
 *     // Set most significant bit (msb) of 32-bit machine
 *     int set_msb = 1 << 31;
 *     // Shift past msb of 32-bit word
 *     int beyond_msb = 1 << 32;
 *
 *     // set_msb is nonzero when word size >= 32
 *     // beyond_msb is zero when word size <= 32
 *     return set_msb && !beyond_msb;
 * }
 *
 * ���� SUN SPARC ������ 32 λ�����ϱ��벢����ʱ��������̷��ص�ȴ�� 0�������
 * ��������Ϣ��������һ�������ָʾ��
 *
 * warning: left shift count >= width of type
 *
 * A. ���ǵĴ������ĸ�����û������ C ���Ա�׼��
 * B. �޸Ĵ��룬ʹ������ int ����Ϊ 32 λ���κλ����϶�����ȷ���С�
 * C. �޸Ĵ��룬ʹ������ int ����Ϊ 16 λ���κλ����϶�����ȷ���С�
 */
#include <iostream>

/*
 * A. �� C99 ��׼�� 6.5.7 ���У���������������
 *
 * If the value of the right operand is negative or is greater than or equal to
 * the width of the promoted left operand, the behavior is undefined.
 *
 * ��Ϊ�� int �� 32 λ�Ļ����ϣ�1<<32 ���� int ��λ��ȣ�������Ϊ�ǡ�δ���塱�ġ�
 */

 /*
  * B. ����Ĵ����� int ����Ϊ 32 λ���κλ����϶�����ȷ����
  */
int int_size_is_at_least_32(void)
{
	int set_msb = 1 << 31;
	int beyond_mab = set_msb << 1;

	return set_msb && !beyond_mab;
}

/*
 * C. ����Ĵ����� int ����λ 16 λ���κλ����϶�����ȷ����
 */
int int_size_is_at_least_16(void)
{
	int set_msb = 1 << 15<<15<<1;
	int beyond_mab = set_msb << 1;

	return set_msb && !beyond_mab;
}
