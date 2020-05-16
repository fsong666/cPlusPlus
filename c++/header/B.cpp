#include "B.hpp"


bool sub( const int& a, const int& b, int& out ){
    print_out(a,b);
	if( a != 0 && b != 0 ){
		out = a - b;
		//test_linie(a,b);
	
		return true;
	}else{
		return false;
	}
	
}

BB::BB( int x, int y ): aa(x),bb(y){
	// mem222222222222222222222222222();
}
// BB::BB( int& x, int& y ): aa(x),bb(y){

// }

// void BB::test_classB(int a, int b){
// 	int c = a * b + aa + bb;
// }

 int BB::mem(){ //_ZN2BB3memEv
	
	    int j = 10;
}

inline int BB::mem222222222222222222222222222(){ //_ZN2BB30mem222222222222222222222222222Ev
	//该源文件对应的.i中有该定义
    //但是在C.s C.o种没有该内联函数的实现
    //只有在被调用时才会被编译汇编.
	    int j = 10;
}
