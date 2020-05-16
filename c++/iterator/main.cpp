#include <iostream>
#include <vector>
// #ifnedf 只防止头文件，在同一个源文件内，被多次包含，
//但是　不同的源文件可以包含相同的头文件,该文件里声明可以被多次包含

/**
 * 
 * C++ 规定，内联函数可以在程序中定义多次，只要内联函数在一个 .cpp 文件中只出现一次，
 * 并且在所有的 .cpp 文件中，这个内联函数的定义是一样的，就能通过编译。
 * 
 * 头文件中可以写类（class）的定义。因为在程序中创建一个类的对象时，编译器只有在这个类的定义完全可见的情况下，
 * 才能知道这个类的对象应该如何布局，所以，关于类的定义的要求，跟内联函数是基本一样的。
 */
using namespace std;
int main(){

	std::vector<int> v = {1,2,3};
	auto it = v.begin();
	v.emplace( it, 23 );
	for(auto& it : v){
	cout << it << " ";
	}
	cout<< endl;
	
	return 0;
}
