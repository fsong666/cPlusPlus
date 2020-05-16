#include <iostream>

#define MIN(A,B) (A < B ? A : B)
#ifndef FAN 
#define FAN 26
#endif

#define MKSTR(x) #x

#if FAN > 20
#define CONTACT(X , Y) X ## Y
#endif

// \ 表示　换行
#if defined(FAN) && \
	defined(MKSTR)
#	define SONG 2000
#endif

#ifndef DISPLAY
#	define DISPLAY
#endif

using namespace std;
int main(){
	int i, j;
	i = 100;
	j = 10;
	int ij = 2020;

	cout <<"较小的值为：" << MIN(i, j) << endl;
	cout <<"FAN：" << FAN << endl;

 	#if FAN
    cerr <<"Variable x = " << 99 << endl;
	#endif

    cout <<"MKSTR(x): " << MKSTR(Hello c++) << endl;

    cout <<"CONTACT(X , Y): " << CONTACT(i,j) << endl;


    cout << "#if define(FAN) : " << SONG << endl;
    
    #if !defined(DISPLAY)
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    #endif
	
	return 0;
}