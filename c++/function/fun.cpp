#include <iostream>
using namespace std;
/**
const对象只能调用　const成员函数，因为this 是　const class* this类型的指针 
*/
/*
2 用const 修饰函数的返回值
如果给以“指针传递”方式的函数返回值加const 修饰，
那么函数返回值（即指针）的内容不能被修改，该返回值只能被赋给加const 修饰的同类型指针。

例如函数：
const char * GetString(void);
如下语句将出现编译错误：
char *str = GetString();
正确的用法是
const char *str = GetString();
*/

/**
如果函数返回值采用“值传递方式”，由于函数会把返回值复制到外部临时的存储单元中，加const 修饰没有任何价值。
例如不要把函数int GetInt(void) 写成const int GetInt(void)。
同理不要把函数A GetA(void) 写成const A GetA(void)，其中A 为用户自定义的数据类型。
*/
class A {
public:
    A() {
        cout << this << "--this is a constructor" << endl;
    }
    ~A() {
        cout << this << "--this is a destructor" << endl;
    }
    A(const A & another) {
        cout << this << "--copy constructor from--" << & another << endl;
    }
    A & operator=(const A & other) {
        cout << this << "--assignment operator overloading from--" << &other << endl;
    }

    const int m_val = 0;
    int getValue() const{
        return m_val;
     }
};

A func1(A a) {
    return a;
}

A& func2(A a) {
    return a;
}

A func3(A& a) {
    return a;
}

const A& func4(A& a) {
    return a;
}
//const
const int func5(A& a) {
    const int cc = a.getValue();
    const int ccc = a.m_val;
    const int t = 7;
    const int c = t;//a.getValue();
    return cc;
}

const int& func6(A& a){
    const int t = 7;
    return t;
}

const int add(const int a,const int b){
    return a + b;
}

int main() {
    A x;
    A t;
    cout << "-----------------\n" << endl;
    t = func1(x);
    cout << "-----------------\n" << endl;
    t = func2(x);
    cout << "-----------------\n" << endl;
    t = func3(x);
    cout << "-----------------\n" << endl;
    t = func4(x);
    cout << "-----------------\n" << endl;
    if(func5(x) == 1){
        cout << "-----func5(x)------------\n" <<endl;
    }
    int a = func6(x);
    //const c = add(10,3);
    //c = 10;
    cout << "-----------------\n" <<endl;
    return 0;
}