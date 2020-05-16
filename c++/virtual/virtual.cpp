#include <iostream>

/***
 *编译器无法进行多选择，若有就报错
 * 
 * 类指针，类引用是指向继承体系的多版本的内存!!!! 一对多
 * 
 * 多选择：
 * 类指针指向的内存不同！！！！
 * 内存中的同名函数有不同版本，即调用虚函数
 * 
 * Virtual:　　　合法化编译时的多选择，由运行时确定
 * 1.引入多选择,告诉编译器此函数有多个选择版本
 * ２.调用时，合法，不报错
 * ３.编译器无法选择，就不选择，交给运行时实际对象的虚表确定
 * 
 * 
 * 1.派生类虚表中只有一个override重新定义的基类函数，　与原来基类虚表里的基类函数不同。
 * 2.只出现在父类的声明里
 * 3.基类指针或引用作为函数形参时的动态绑定。
 * 4.派生类中完全与父类虚函数相同的函数，隐式为虚函数
 * 
 *
 * 虚普通函数：　override 改写父类的非私有函数
 * 
 * 普通析构函数：  Base* p = new Child; delete p,只会析构基类!!!
 *              Base* p = &Child, 离开作用域时,会自动析构基类和子类
 * 虚析构函数：只作用在new动态分配派生类时　Base* p = new Child; delete p,不仅会析构基类 还会析构子类
 * 
 * 
 * 
 * 静态类型：变量直接声明的类型
 * 动态类型：内存中对象的类型，内存大小，指针ｓｔｅｐ大小
 * 静态类型==动态类型　　Base* bp = new Base();
 * 静态类型!= 动态类型　 Base* bp = new Drived();
 * 
 * 实例成员函数名字查找　bp->mem():
 * 实例内存只由成员对象构成，不由成员函数构成
 * 成员函数的搜索是在.text代码段的类的定义中搜索！！！ 而不是在实例的内存(stack)中找
 * 每个类包括派生类的地址前段有个自己版本的８byte虚函数表，如果该类有虚函数
 * 
 * 不管类指针的静态类型是否等于动态类型，通过指针调用成员函数,都是在类的定义段中找。
 * 
 * 如果一个类中存在虚函数，编译器会做以下三件事
 * 为该类分配一个虚函数表，它存有该类中虚函数的地址，虚表中的虚函数地址不是连续存的而是链式的
 * 在该类中安插一个虚指针，指向该类的虚表，实例化时，将该类的虚表指针赋值给实例首地址。
 * 将每一个虚函数的入口地址存放在虚函数表中相应的slot 
 * 
 * 1.搜索静态类型对应的类定义中,如果没找到，搜索其直接父类，直到基类，若还没找到，报错
 * 2.如果是非虚函数：静态调用, 非虚函数地址在继承体系是唯一确定的。
 * 3.如果是虚函数：告诉编译器，根据运行时的动态类型确定，虚函数版本
 * 
*/
using namespace std;

class Base
{
public:
	Base(int ii, int jj) :i(ii), j(jj)
    { 
        cout << "调用基类的一般构造函数" << endl;
    }//基类的一般构造函数
	Base() :i(0), j(5203132)
    { 
        cout << "调用基类的默认构造函数" << endl; 
    }//基类的默认构造函数
	~Base() 
    { 
        cout << "调用基类的析构函数" << endl;
    }
	//virtual ~Base() { cout << "调用基类的析构函数" << endl; }
	virtual void show_members() 
    //void show_members()
    {
        cout << "Base:: show_members()" << endl;
         cout << i << "\t" << j<< endl;
    }

public:
	int i;
private:
	int j;
};

class D1 : public Base
{
public:
    D1(int d):Base(d,d), k(d)
    {
        cout << "调用派生类D1的构造函数" << endl;
    }
    D1():k(11)
    {
        cout << "调用派生类D1的默认构造函数" << endl;
    }
    ~D1()
    {
        cout << "调用派生类D1的析构函数" << endl;
    }
    void show_members() //非虚函数时　有两个不同的show=　D1::show_members 和　Ｂase::show_members
   
    //void show_members() override 
    //虚函数时，内存空间中只有一个重新定义的show 且是存在基类部分
    {
        
        cout << "D1:: show_members()" << endl;
        cout << k << endl;
    }
    //void show_members() //非虚函数时　有两个不同的show=　D1::show_members 和　Ｂasw::show_members
    void show_members2() //虚函数时，内存空间中只有一个重新定义的show 且是存在基类部分
    {
        
        cout << "D1:: show_members2()" << endl;
        cout << k << endl;
    }
private:
    int k;
};

class C
{
private:
    /* data */
public:
    C(/* args */);
    ~C();
};

C::C(/* args */)
{
    cout<<"constctor c1" << endl;
}

C::~C()
{
    cout << "调用C1的析构函数" << endl;
}


//形参指针指向的内存未知，
void test( Base& b ){
    cout<< "\n-----test( Base& b ): "<< endl;
    b.show_members();//编译器查到是虚函数，有多版本，类指针指向不确定内存，不进行也无法选择调用，
    //合法翻译，只翻译该函数名字，具体函数里代码内容由具体输入的调用决定。
    C cc;
    //D1 d ;
    
    cout<< "-----end test: "<< endl;
}

int main()
{
    D1 d1(12);
    //调用基类的函数
    //成员函数不在实例的内存空间里，调用函数是在.text段的类的函数定义中搜索，如果没有，搜索直接父类，还没有，直到搜索基类
    //是在.txt段的类定义中搜索，所以通过继承单链表可搜索到Base::shoe_members()
    d1.Base::show_members();//;;作用域运算最高，先算作用域再成员访问。
    d1.show_members();
    test( d1 );//D1自动隐式转为Ｂａｓｅ&类型

    //基类指针指向派生类的可能改写的基类部分
    //是子类实例指针向父类转换，缩小指针寻址范围
    //编译时不会真正分配内存,　new 和　构造函数里的内存分配是在运行时分配的！！！！
    cout << "\nBase* base = &d1" << endl;
    Base& base = d1;
    base.show_members();   // 类似于　base->D1::show_members();
    base.Base::show_members(); //Base指针　既可以指向Ｄ1::override的基类部分 也可以指向　独立的Base::
                                // 动态绑定：　由指向的对象内存确定,　是 独立的Base::　or　Ｄ1::override的基类部分
   // base->show_members2(); //Error:base has no show_members2()
    test( base );

    // Base b2;
    // test(b2);

    C abc(); // 定义了一个返回类性为Ｃ的函数
    //C cc; //默认构造函数是不加括号
    cout<< "-----end-------- "<< endl;
    return 0;
}
