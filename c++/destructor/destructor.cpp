#include <iostream>

using namespace std;

class Base
{
public:
	Base(int ii, int jj) :i(ii), j(jj) { cout << "调用基类的一般构造函数" << endl; }//基类的一般构造函数
	Base() :i(0), j(5203132) { cout << "调用基类的默认构造函数" << endl; }//基类的默认构造函数
	~Base() { cout << "调用基类的析构函数" << endl; }
	//virtual ~Base() { cout << "调用基类的析构函数" << endl; }
	void show_base() { cout << i << "\t" << j<<"\t"; }
public:
	int i;
private:
	int j;
};
 
class D1 :public Base
{
public:
	D1() :k(0) { cout << "调用派生类D1的默认构造函数" << endl; }//派生类的默认构造函数
	D1(int ii, int jj, int kk) :Base(ii, jj), k(kk) { }//派生类的一般构造函数
	D1(int kk) : k(kk) {}//派生类的一般构造函数,隐式调用基类的默认构造函数
	~D1() { cout << "调用派生类D1的析构函数" << endl; }
 
	int k;
	void show_d() { show_base(); cout << k << endl; }
};

class D2 :public D1
{
public:
	D2() :k(0) { 
	cout << "调用派生类D2的默认构造函数" << endl; }//派生类的默认构造函数
	D2(int ii, int jj, int kk):D1(ii, jj, kk),k(kk) { }//派生类的一般构造函数
	D2(int kk) : k(kk) {}//派生类的一般构造函数,隐式调用基类的默认构造函数
	
	~D2() { cout << "调用派生类D2的析构函数" << endl; }
 
	int k;
	void show_d() { show_base(); cout << k << endl; }
};
 
//主函数
int main()
{
	/*******************************************************************/
	//  派生类的析构函数
	/*******************************************************************/
	cout << "D2 *pD2 = new D2:" << endl;
	D2 *pD2 = new D2;
 
	cout << "\ndelete pD2:" << endl;
	delete pD2;

	/*******************************************************************/
	//  指向派生类的基类指针。派生类当基类使用
	/*******************************************************************/
	cout << "\nBase *pBase2 = new D2:" << endl;
	Base *pBase = new D2;
 
	cout << "\ndelete pBase:" << endl;
	delete pBase;

	/*******************************************************************/
	//  虚析构
	/*******************************************************************/
	cout << "\nvirtual destructor:" << endl;
	cout << "Base *pBase2 = new D2:" << endl;
	Base *pBase2 = new D2;
 
	cout << "\ndelete pBase2:" << endl;
	delete pBase2;
 
	cout << "\nend main()" << endl;
	return 0;
}