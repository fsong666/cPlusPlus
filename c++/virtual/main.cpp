#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


using namespace std;
class MyClass
{
private:
    int a;
public:
    MyClass( int a): a(a){

    }
    ~MyClass() = default;

     int add(int a, int b){
    int aa = 1,bb= 4;
    a = bb -aa;
    int sum = a + b;
    return sum;
    }

    virtual int sub(int a, int b){
        int aa = 1,bb= 4;
        a = bb -aa;
        int sum = a - b;
        return sum;
    }
 
};






int main(){
int a = 1, b =3;       // 栈区
MyClass myclass(a);
int out = myclass.add(a,b);
cout<< sizeof(myclass) << endl;
return 0;
}