#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Result
{
	NOMATCH, MATCH,OTHER
};
Result rechnung (int a, int b) {
	if (a * b > 10) {
		return MATCH;
	}else if ( a -b > 0) {
		return NOMATCH;
	}else {
		return OTHER;
	}
}
int main(){
	if (rechnung(21,3)) {
		cout << "out: " << MATCH << endl;
	}else {
		cout << "out: " << rechnung(21,3)<< endl;
	}
	// std::vector<int> v;
	// v.push_back(0)
	//  .push_back(1)
	//  .push_back(2)
	//  .push_back(3);

	// for (int n : v) {
	// 	cout << n << endl;

	// }
	return 0;
}