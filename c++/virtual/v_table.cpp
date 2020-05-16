#include <iostream>

/**
 * 一个类有一个函数表，该类的所有对象共享一个虚函数表
 * 子类的虚表和父类的虚表不一样，　不同的类有不同的虚表
*/
using namespace std;
class A {

    virtual void fun() {

    }
};

class B : public A
{
private:
    /* data */
public:
    void fun() override{
        printf("B:: fun() ");
    }

};



int main()
{
    A *a = new A();
    printf("%x\n", *(int*)(void*)a);
    for (int i = 0; i < 10;i++) {
        A *b = new B();
        if (*(int*)(void*)a == *(int*)(void*)b) {
            printf("一样的虚函数表地址\n");
        }
        else {
            printf("不一样的虚函数表地址\n");
            break;
        }
        delete b;
    }
    return 0;
}
