#include <iostream>
#include "C.hpp"

using namespace std;
//template < typename T > 
void print_out(const int& a, const int& b){
    //test_linie(1,3);
    cout<< "a: "<< a << " b: "<< b << endl;
}

inline void test_linie2222(int a)
{
    //该源文件对应的.i中有该定义
    //但是在C.s C.o种没有该内联函数的实现
    //只有在被调用时才会被编译汇编.
    int c = a * a;
}
