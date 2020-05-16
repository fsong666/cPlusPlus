#include </home/sf/Documents/include/rechnung.hpp>
//#include <rechnung.hpp>
#include <iostream>

using namespace std;

bool add( const int& a, const int& b, int& out ){
	if( a != 0 && b != 0 ){
		out = a + b;
		return true;
	}else{
		return false;
	}
}