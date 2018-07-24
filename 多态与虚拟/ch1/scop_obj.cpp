#include <iostream>
#include <string.h>

using namespace std;

class CDemo {
public:
	CDemo(const char *str);
	~CDemo();

private:
	char name[20];
};

CDemo::CDemo(const char *str) {
	strncpy(name, str, 20);
	cout << "Constructor called for " << name << endl;
}

CDemo::~CDemo() {
	cout << "Destructor called for " << name << endl;
}

void func() {
	CDemo localObjInFunc("localObjInFunc");
	static CDemo staticObj("staticObj");
	CDemo *pHeadObjInFunc = new CDemo("headObjInFunc");

	cout << "Inside func" << endl;
}

CDemo globalObj("globalObj");

int main(int argc, char *argv[]) {
	CDemo localObjInMain("localObjInMain");
	CDemo *pHeadObjInMain = new CDemo("heapObjInMain");

	cout << "In main, before calling func\n";
	func();
	cout << "In main, after calling func\n";



	return 0;
}
