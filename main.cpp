#include <iostream>
#include <limits>

using namespace std;
// 判断无符号加法O不ok, 有溢出就返回false
bool uadd_ok(unsigned int x, unsigned int y) {
	unsigned sum = x + y;
	return sum >= x;
}
//判断有符号加法O不ok,有溢出就返回false
bool tadd_ok(int x, int y) {
	int sum = x + y;
	bool neg_over = x < 0 && y < 0 && sum >= 0;
	bool pos_over = x >= 0 && y >= 0 && sum < 0;
	return !neg_over && !pos_over;
}
//返回整数x除以16的商
int div16(int x) {
	//Compute bias to be either 0(x>=0)or 15(x<0)
	int bias = (x >> 31) & 0xF;
	return (x + bias) >> 4;
}
/* $begin show-bytes */
#include <stdio.h>
/* $end show-bytes */
#include <stdlib.h>
#include <string.h>
/* $begin show-bytes */

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	size_t i;
	for (i = 0; i < len; i++)
		printf(" %.2x", start[i]);    //line:data:show_bytes_printf
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer)&x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_float(float x) {
	show_bytes((byte_pointer)&x, sizeof(float)); //line:data:show_bytes_amp2
}

void show_pointer(void *x) {
	show_bytes((byte_pointer)&x, sizeof(void *)); //line:data:show_bytes_amp3
}
void show_short(short int x) {
	show_bytes((byte_pointer)&x, sizeof(short int)); //line:data:show_bytes_amp2
}
void show_long(long int x) {
	show_bytes((byte_pointer)&x, sizeof(long int)); //line:data:show_bytes_amp2
}
void show_double(double x) {
	show_bytes((byte_pointer)&x, sizeof(double)); //line:data:show_bytes_amp2
}
/* $end show-bytes */


/* $begin test-show-bytes */
void test_show_bytes(int val) {
	int ival = val;
	float fval = (float)ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}
/* $end test-show-bytes */

void simple_show_a() {
	/* $begin simple-show-a */
	int val = 0x87654321;
	byte_pointer valp = (byte_pointer)&val;
	show_bytes(valp, 1); /* A. */
	show_bytes(valp, 2); /* B. */
	show_bytes(valp, 3); /* C. */
	/* $end simple-show-a */
}

void simple_show_b() {
	/* $begin simple-show-b */
	int val = 0x12345678;
	byte_pointer valp = (byte_pointer)&val;
	show_bytes(valp, 1); /* A. */
	show_bytes(valp, 2); /* B. */
	show_bytes(valp, 3); /* C. */
	/* $end simple-show-b */
}

void float_eg() {
	int x = 3490593;
	float f = (float)x;
	printf("For x = %d\n", x);
	show_int(x);
	show_float(f);

	x = 3510593;
	f = (float)x;
	printf("For x = %d\n", x);
	show_int(x);
	show_float(f);

}

void string_ueg() {
	/* $begin show-ustring */
	const char *s = "ABCDEF";
	show_bytes((byte_pointer)s, strlen(s));
	/* $end show-ustring */
}

void string_leg() {
	/* $begin show-lstring */
	const char *s = "abcdef";
	show_bytes((byte_pointer)s, strlen(s));
	/* $end show-lstring */
}

void show_twocomp()
{
	/* $begin show-twocomp */
	short x = 12345;
	short mx = -x;

	show_bytes((byte_pointer)&x, sizeof(short));
	show_bytes((byte_pointer)&mx, sizeof(short));
	/* $end show-twocomp */
}

bool is_little_endian() {
	short x = 1;
	byte_pointer p = (byte_pointer)&x;
	if (*p==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned put_byte(unsigned x, unsigned char b, int i) {
	byte_pointer p = (byte_pointer)&x;
	if (is_little_endian())
	{
		p[i] = b;
	}
	else
	{
		p[3 - i] = b;
	}
	return x;
}
//int main(int argc, char *argv[])
//{
//	int val = 12345;
//
//	if (argc > 1) {
//		if (argc > 1) {
//			val = strtol(argv[1], NULL, 0);
//		}
//		printf("calling test_show_bytes\n");
//		test_show_bytes(val);
//	}
//	else {
//		printf("calling show_twocomp\n");
//		show_twocomp();
//		printf("Calling simple_show_a\n");
//		simple_show_a();
//		printf("Calling simple_show_b\n");
//		simple_show_b();
//		printf("Calling float_eg\n");
//		float_eg();
//		printf("Calling string_ueg\n");
//		string_ueg();
//		printf("Calling string_leg\n");
//		string_leg();
//		short s = 100;
//		show_short(s);
//		long l = 1000;
//		show_long(l);
//		double d = 100.0;
//		show_double(d);
//	}
//	bool b = is_little_endian();
//	int x = 0x89ABCDEF, y = 0x76543210;
//	printf(" %.2x", (x & 0xFF) | (y & 0xFFFFFF00));
//	unsigned u=put_byte(0x12345678, 0xab, 2);
//	show_int(u);
//	any_even_one()
//	return 0;
//}

