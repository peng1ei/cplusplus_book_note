#include <iostream>

int main(int argc, char *argv[]) {
	int *num = new int(3);
	int *numm = NULL;
	delete num;
	std::cout << "6";
	delete num;

	return 0;
}
