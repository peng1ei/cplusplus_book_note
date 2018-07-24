#include <iostream>
using namespace std;

class X {
	public:
	unsigned short n;
};

class Y : public virtual X {
};

class Z : public virtual X {
};

class A : public Y, public Z {
};

class B : public Z {
};

class C : public X {
	public:
	int m;
};

class D : public X {
};

class E : public C, public D {
};



int main(int argc, char *argv[]) {
	cout << "sizeof X = " << sizeof(X) << endl;
	cout << "sizeof Y = " << sizeof(Y) << endl;
	cout << "sizeof Z = " << sizeof(Z) << endl;
	cout << "sizeof A = " << sizeof(A) << endl;
	cout << "sizeof B = " << sizeof(B) << endl;
	cout << "sizeof C = " << sizeof(C) << endl;
	cout << "sizeof D = " << sizeof(D) << endl;
	cout << "sizeof E = " << sizeof(E) << endl;

	X a, b;
	if (&a == &b)
		cerr << "yipes" << endl;

	cout << "===================" << endl;
	C c;
	cout << &c.n << " " << &c.m << endl;

	return 0;
}
