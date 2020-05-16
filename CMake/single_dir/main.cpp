#include <iostream>
#include "foo.hpp"
int main()
{
	printf("single Makefile for single_dir\nthis is  main()");
	A a;
	a.foo();
	return 0;
}