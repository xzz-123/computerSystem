/*
 * ��ϰ�� 2.71
 *
 * ��ոտ�ʼ��һ�ҹ�˾����������Ҫʵ��һ�����������һ�����ݽṹ��Ҫ�� 4 ����
 * �����ֽڷ�װ��һ�� 32 λ unsigned��һ�����е��ֽڴ� 0�������Ч�ֽڣ���ŵ�
 * 3�������Ч�ֽڣ����������������ǣ�Ϊһ��ʹ�ò���������������ƵĻ�����д
 * һ����������ԭ�͵ĺ�����
 *
 * Declaration of data type where 4 bytes are packed into an unsigned
 *
 *         typedef unsigned packed_t;
 *
 * Extract byte from word.  Return as signed integer
 *
 *         int xbyte(packed_t word, int bytenum);
 *
 * Ҳ����˵���������ȡ��ָ�����ֽڣ��ٰ���������չΪһ�� 32 λ int�����ǰ��
 * ����Ϊˮƽ�����߶�������ˣ���д������Ĵ��룺
 *
 * Failed attempt at xbyte
 * int xbyte(packed_t word, int bytenum)
 * {
 *      return (word >> (bytenum << 3)) & 0xFF;
 * }
 *
 * A. ��δ���������
 * B. ������������ȷʵ�֣�ֻ��ʹ��������λ��һ��������
 */

 /*
  * A. ��δ��벻�ܴ���ضϵ��ֽ��Ǹ�������������ضϵ��ֽ�Ϊ����ʱ�����ص�int�����ЧλӦ����1������δ�������λһֱ��0��
  */

  /*
   * B. Ҫʵ�������������Ҫ�������������ƵĻ����ϣ��޷���������չ�ģ����з�����
   *    �Ƿ�����չ��������ԡ�
   */

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
	int shift_left = (3 - bytenum) << 3;
	//�ȰѴ��ضϵ��ֽ����Ƶ����λ�������ұ�ȫ����0
	//Ȼ���ٽ����������ƣ�����һ�����ضϵ��ֽ��Ǹ�����߾Ͳ�1�������Ͳ�0������
	return (word << shift_left) >> 24;
}