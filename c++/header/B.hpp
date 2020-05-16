#ifndef B_H
#define B_H
#include "C.hpp"
bool sub( const int& a, const int&  b, int&  out );

class BB //ZN2BB
{
public:
     int aa = 2;
     int bb = 10;
public:
    BB() = default;

    BB(int x, int y); //call _ZN2BBC1Eii　汇编代码的构造函数
    BB( int& x): aa(x){
        //内联构造函数
    }
    ~BB() = default;

    //call _ZN2BB11test_classBEii
    void test_classB(int a, int b){
        int c = a * b + aa + bb;
    }

   int mem();

   int mem222222222222222222222222222();
};

#endif