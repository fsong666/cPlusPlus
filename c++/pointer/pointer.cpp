#include <iostream>

using namespace std;

void func(int*& p) {
	*p = 10;
}

int main(int argc, char const *argv[])
{
	int n = 10;
	//int* a = &n;
	int* a = NULL;
	func(a);
	cout << "*a= " << *a << endl;
	return 0;
}