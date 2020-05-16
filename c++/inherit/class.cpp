/**
 * 每个实例的内存地址是不同的
 * 64为系统默认分配虚表　８byte
 * 64位系统,对象内存需　８字节对齐，是８的倍数
 * 
 * 基类若有虚函数，有虚表，　子类都有各自的虚表，若没有任何覆写，子类的虚表就基类虚表的一个副本。
 */


#include <iostream>
using namespace std;
class Basic{
    public:
        static int static_a;
        int a;
        float c ;

        static void fun1(){cout<<"Basic::fun1"<<endl;}
        void fun2(){cout<<"fun2"<<endl;}
        virtual void fun3(){cout<<"Basic::fun3"<<endl;}
        virtual void fun4(){cout<<"fun4"<<endl;}
};

class D1: public Basic
{
public:
    // int d;
        
    // void fun3() override{
    //     cout<<"D1::fun3"<<endl;}
};



int Basic::static_a = 1;

int main ()
{
    Basic basic;
    cout<<"size:"<<sizeof(basic)<<endl;

    cout<<"addr of basic:"<<&basic<<endl;
    cout<<"addr of basic.static_a:"<< &basic.static_a<<endl;
    cout<<"addr of of basict.a:"<< &basic.a<<endl;
    cout<<"addr of of basict.c:"<< &basic.c<<endl;
    D1 d1;
    cout<< "------D1--------" << endl;
    cout<<"size:"<<sizeof(d1)<<endl;
    cout<<"addr of d1:"<<   &d1<<endl;
    cout<<"addr of d1.static_a:"<< &d1.static_a<<endl;
    cout<<"addr of of d1.a:"<< &d1.a<<endl;
    cout<<"addr of of d1.c:"<< &d1.c<<endl;
    // cout<<"addr of of d1.d:"<< &d1.d<<endl;

    return 0;
}