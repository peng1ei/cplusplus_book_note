#include <iostream>
using namespace std;

class CA {
public:
	CA() { }//_data = 5; };
	CA(int val) {}
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

int main(int argc, char *argv[]) {
	CA objaa;
	CA objca;
	cout << "objca.getdata() = " << objca.getdata() << endl;

CB objcb;
cout << "objcb.getdata() = " << objcb.getdata() << endl;
cout << "objcb.objca.getdata() = " << objcb.getca().getdata() << endl;


	return 0;
}
