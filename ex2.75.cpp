/*
 * ��ͥ��ҵ 2.75
 *
 * ����������Ҫ���� x��y �������� 2w λ��ʾ�����У�x �� y �����޷�������������
 * ������������ unsigned �� w λ�Ļ����ϡ��˻��ĵ� w λ�ܹ��ñ��ʽ x��y ���㣬
 * ���ԣ�����ֻ��Ҫһ����������ԭ�͵ĺ�����
 *
 * unsigned unsigned_high_prod(unsigned x, unsigned y);
 *
 * ������������޷��ű��� x��y �ĸ� w λ��
 * ����ʹ��һ����������ԭ�͵Ŀ⺯����
 *
 * int signed_high_prod(int x, int y);
 *
 * �������� x �� y ���ò�����ʽ������£�x��y �ĸ� w λ����д�������������̣�
 * ��ʵ�����޷�����Ϊ�����ĺ�������֤��Ľ�����ȷ�ԡ�
 *
 * ��ʾ��������ʽ��2-18�����Ƶ��У��з��ų˻� x��y ���޷��ų˻� x'��y' ֮��Ĺ�
 * ϵ��
 */
 /*
	 ���������Ҫһ��һ���Ľ����Ƶ�
	 T2Uw(x)Ϊ����ת�޷�������
	 
	 if x < 0  => x + 2^w
	 if x > 0  => x
	 ����д��
	 T2Uw(X)= X + X(w-1)2^w

	 ���ʽ�Ӹ��ϱߵ��Ǹ�����һ����x��w-1λ�����������λ�������λ��ֵ��1����ô���൱��
	 x<0����������������һ�����

	 ���Ǽ���x'��ʾx���޷���ֵ
	 X' = X + X(w-1)2^w

	 ���Ǽ���y`��ʾx���޷���ֵ
	 Y' = Y + Y(w-1)2^w

	 ��ôX'* Y' = (X + X(w-1)2^w) * (Y + Y(w-1)2^w)
	 ���Ҫ���������ʽչ������鷳�����ǿ��Խ�һ������
	 ��a = X(w-1)2^w, b= Y(w-1)2^w
	 �� X' * Y' = X*Y + X*b + Y*a + a*b

	 ���Ǽٶ�������һ�����������Ĺ�����ȡ���޷����������λuh(),����ϱߵ�ʽ�ӱ���Ϊ��
	 uh(X' * Y') = uh(X*Y + X*b + Y*a + a*b)
				 = uh(X*Y) + uh(X*b) + uh(Y*a) + uh(a*b)

	 ��ôX * b Ҳ����X*b= X*Y(w-1)2^w �������λ��ֵ����X*Y(w-1)2^w / 2^w => X*Y(w-1)
	 ��ôY * a Ҳ����Y*a= Y*X(w-1)2^w �������λ��ֵ����Y*X(w-1)2^w / 2^w => Y*X(w-1)
	 ��ôa * b Ҳ����a*b= X(w-1)2^w * Y(w-1)2^w �� / 2^w => 0

	 ===> uh(X` * Y`) = uh(X*Y) + X*Y(w-1) + Y*X(w-1)

	 �ϱ�����ĺ���˼����� �޷���X`�Ĳ����ʾ��X + X(w-1)2^w ���λ��/ 2^w ����
 */

 /*
  * unsigned-high-prod.c
  */
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int signed_high_prod(int x, int y) {
	int64_t mul = (int64_t)x * y;
	return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
	/* TODO calculations */
	int sig_x = x >> 31;
	int sig_y = y >> 31;
	int signed_prod = signed_high_prod(x, y);
	return signed_prod + x * sig_y + y * sig_x;
}

/* a theorically correct version to test unsigned_high_prod func */
unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
	uint64_t mul = (uint64_t)x * y;
	return mul >> 32;
}

//int main(int argc, char* argv[]) {
//	unsigned x = 0xffffffff;
//	unsigned y = 0xFFFFFFFF;
//
//	assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
//	return 0;
//}