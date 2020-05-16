#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
	vector<int> v = {123,22};

	for(auto& r : v){
		cout<< r;
	}
	cout<<endl;
	return 0;
}