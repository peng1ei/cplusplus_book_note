#include <iostream>
using namespace std;

class shareobj {};

class derivedobj : public shareobj {

	private:
		char num;
};

int main(int argc, char *argv[]) {
	cout << "drivedobj size = " << sizeof(derivedobj) << endl;

	return 0;
}
