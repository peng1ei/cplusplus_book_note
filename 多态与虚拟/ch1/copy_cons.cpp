#include <iostream>
using namespace std;

class CA {
public:
	CA() { _data = 5; };
	CA(int val) { _data = val; }
	CA(const CA &ca) {
		cout << "copy constructor" << endl;
		_data = 10;
	}

	int getdata() { return _data; }
protected:
	int _data;
};

class CB {
public:
	int getdata() { return _data; }
	CA &getca() { return objca; }

protected:
	int _data;
	CA objca;
};

// 函数参数是一个 object
void foo2(CA ca) {
	cout << "in foo2(), ca.getdata() = " << ca.getdata() << endl; 
}

CA foo3() {
	CA ca(3);
	cout << "in foo3(), ca.getdata() = " << ca.getdata() << endl;

	return ca; // 函数的返回值是个 object
}

int main(int argc, char *argv[]) {
	CA ca1, ca2(7);
	
	cout << "ca1.getdata() = " << ca1.getdata() << endl;	
	cout << "ca2.getdata() = " << ca2.getdata() << endl;	

	ca2 = ca1; // object assinment
	cout << "ca2.getdata() = " << ca2.getdata() << endl;	

	foo2(ca1); // 情况1：调用之前 ca1._data == 5
	ca2 = foo3(); // 情况2：

	cout << "ca2.getdata() = " << ca2.getdata() << endl;	

	return 0;
}
