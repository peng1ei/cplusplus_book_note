#include <iostream>
#include "hello.h"

using namespace std;

int main(int argc, char *argv[]) {
	CPoint pt1(7.2), pt2(5.3), pt3;
	pt3 = pt1 + pt2;

	cout << "pt3.x = " << pt3.x() << endl; 

	return 0;
}
