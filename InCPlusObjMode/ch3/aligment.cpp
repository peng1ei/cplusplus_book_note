// Data Aligment 
// Data stored in memory must be "aliged" according to 
// the length of the data.
//
// 	Byte Data
// 		can go at any address
// 	Halfword Data
// 		must be "halfword aligned"
// 		addresses must be even numbers(偶数)
// 		Halfword addresses end in an even number:
// 			0, 2, 4, 6, 8, a, c, e, ...
// 	Word Data
// 		must be "word aligned"
// 		addresses must be divisible by 4(被4整除)
// 		Word addresses end in a number divisible by 4:
// 			0, 4, 8, 12, ...
// 	Doubleword Data
// 		must be "doubleword aligned"
// 		addresses must be divisible by 8(被8整除)
// 		Doubleword addresses end in a number divisible by 8:
// 			0, 8, 16, ...
//
// ----------------------------------------------------------
// 字节对齐主要针对 struct/class。
// GCC 中默认的字节对齐是 4 字节，可通过 #pragma pack(2) 修改
// 默认的字节对齐数。
// #pragma pack() 恢复默认的对齐字节数。 
// ----------------------------------------------------------
//
// 对齐准则：
// 1）数据类型自身的对齐值：char--1字节，short--2字节, int/float
// 		--4字节，double/long long --8字节。
// 2）struct/class 的自身对齐值：其成员中自身对齐值 最大 的那个值。
// 3）指定对齐值：#pragma pack(value) 时指定对齐值 value。
// 4）数据成员、struct/class 的有效对齐值：自身对齐值和指定对齐值中
// 		较小者，即 有效对齐值 = min {自身对齐值， 当前指定的 pack 值}。
//
// 其中，有效对齐值N是最终用来决定数据存放地址方式的值。有效对齐N表示“对齐在N上”，
// 即该数据的 “存放起始地址 %N = 0”。而数据结构中的数据变量都是按定义的先后顺序存放。
// 第一个数据变量的起始地址就是数据结构的起始地址。结构体的成员变量要对齐存放，
// 结构体本身也要根据自身的有效对齐值圆整(即结构体成员变量占用总长度为结构体有效
// 对齐值的整数倍)。
//
// 成员对齐有一个重要的条件：每个成员分别按自己的方式对齐。
// 每个成员按其类型的对齐参数（通常是这个类型的大小）和指定对齐参数中较小的一个对齐，
// 并且结构的长度必须为所用过的所有对齐参数的整数倍（即最起码要满足最大的那个对齐参数
// 的整数倍），不够就补空字节。
//
// 结构体字节对齐的细节和具体编译器实现相关，但一般而言满足三个准则:
// 1) 结构体变量的首地址能够被其最宽基本类型成员的大小所整除；
// 2) 结构体每个成员相对结构体首地址的偏移量(offset)都是成员大小的整数倍，如有需要编
// 	  译器会在成员之间加上填充字节(internal adding)；
// 3) 结构体的总大小为结构体最宽基本类型成员大小的整数倍，如有需要编译器会在最末一个
//    成员之后加上填充字节{trailing padding}。
// 
// 注意：如果结构体中含有结构体，则内嵌的结构体的大小按照一个整体来分析，即可先单独分析
// 		 内嵌结构体的大小（包括对齐大小的字节），然后该内嵌结构体的对齐字节数就是该内嵌
// 		 结构体中所有成员使用的对齐参数中最大的那一个（取指定对齐大小的最小那个?)，所以
// 		 内嵌的结构体在外层的结构体中的对齐参数就是那个值。
//
// 参考链接：https://www.cnblogs.com/clover-toeic/p/3853132.html
///////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

//#pragma pack(1)
class A {
	char x; 
	short y;
	int z;
};

class B {
//	char x; 
//	int z;
	double y;
	char x;
};

typedef struct {
	char c1;
	short s;
	char c2;
	int i;
}T_FOO;

struct s1 {
	char a;
	int b;
};

struct s2 {
	char c;
	s1 d;
	long e;
};


int main(int argc, char *argv[]) {
	cout << "size = " << sizeof(A) << endl;
	cout << "size = " << sizeof(B) << endl;
	
//	T_FOO a;
//	printf("c1->%d, s->%d, c2->%d, i->%d\n",
//			(unsigned int)(void *)&a.c1 - (unsigned int)(void *)&a,
//			(unsigned int)(void *)&a.s - (unsigned int)(void *)&a,
//			(unsigned int)(void *)&a.c2 - (unsigned int)(void *)&a,
//			(unsigned int)(void *)&a.i - (unsigned int)(void *)&a);

//	cout << sizeof(a) << endl;

	cout << "---------------" << endl;
	cout << "s1 = " << sizeof(s1) << endl;

	cout << "s2 = " << sizeof(s2) << endl;

	return 0;
}
