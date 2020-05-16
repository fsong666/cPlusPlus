#include "A.hpp"


bool add( const int& a, const int& b, int& out ){
    print_out(a, b);
	if( a != 0 && b != 0 ){
		out = a + b;
		//int& x =1, y =3;
		BB bb( a, b);
		bb.test_classB(a,b);

		bb.mem(); //因为当前文件中没有ｍem（）的定义，编译器当作非内联的普通函数声明调用，link时在Ｂ.o文件中找不到函数体，报错
		
		//bb.mem222222222222222222222222222();

		//test_linie(x,y); 不被调用，内联函数就不被翻译成汇编
		return true;
	}else{
		return false;
	}
}