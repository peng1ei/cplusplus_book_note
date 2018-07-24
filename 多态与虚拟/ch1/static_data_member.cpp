#include <iostream>
using namespace std;

class SavingAccount {

private:
	char name[40];		// 存储姓名
	char addr[60];		// 存储地址
	double total;		// 存储金额
public:
	static void setRate(double val) { rate = val;}
	
private:
	static double rate;		// 利率（注意：这里只是声明，不是定义，还没有分配内存空间）
};

double SavingAccount::rate = 0.0075; // 定义并设初值

int main(int argc, char *argv[]) {
	SavingAccount myacc;
	//myacc.rate = 0.0072;	

//	myacc.setRate(0.0072);
	SavingAccount::setRate(0.0073);
	SavingAccount::rate = 0.0074;

	return 0;
}
