#include <iostream>
#include "./include/rechnung.hpp"

using namespace std;

int main(int argc, char const *argv[])
{	
	int a = 122, b = 20, out;

	cout << "hello fan " << endl;
	if ( add(a, b, out) )
		cout << out << endl;
	return 0;
}