#include <memory.h>
/*
 *
 * ����һ������дһ�������������� val ���Ƶ������� buf �У�����ֻ�л�����
 * buf �У�����ֻ�е������������㹻���õĿռ�ʱ����ִ�и��ơ�
 *
 * ��д�Ĵ������£�
 *
 * // Copy integer into buffer if space is available
 * // WARNING: The following code is buggy
 * void copy_int(int val, void *buf, int maxbytes) {
 *     if (maxbytes-sizeof(val) >= 0)
 *         memcpy(buf, (void *)&val, sizeof(val));
 * }
 *
 * ��δ���ʹ���˿⺯�� memcpy����Ȼ����������������е���⣬��Ϊ����ֻ���븴
 * ��һ�� int������˵����һ�ָ��ƽϴ����ݽṹ�ĳ���������
 *
 * ����ϸ�ز�������δ�����֣����� maxbytes ��С��ʱ����Ҳ�ܰ�ֵ���Ƶ���
 * �����С�
 *
 * A. ����Ϊʲô�����е������������ǳɹ�����ʾ��sizeof �������������Ϊ size_t ��ֵ��
 * B. ��������д����������ԣ�ʹ֮������ȷ��

 A. size_t ���޷�������maxbytes-sizeof(val) >= 0 ������ʽ�Ὣmaxbytesת��Ϊunsigned��ִ�м���������maxbytes==-1ʱ��
 maxbytes��ת��Ϊ-1+2^32�η���������unsigned��������Ȼ�Ǹ�unsigned�����б�Ȼ��>=0��
 B.  */
 void copy_int(int val, void *buf, int maxbytes)
{
		if (maxbytes >= sizeof(int))
				memcpy(buf, (void *)&val, sizeof(val));
}
