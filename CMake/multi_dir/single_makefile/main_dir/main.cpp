#include <iostream>
#include "foo.hpp"
#include "config.h"
#ifdef USE_MYFUNC
	#include "func.hpp"
#endif
int main(int argc, char** argv)
{	
	if (argc < 3) {
		printf("intput: %s x y\n", argv[0]);
		return 1;
	}
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);

	//printf("single CMake for multi_dir\nthis is  main()");
	A a;
	a.foo();
#ifdef USE_MYFUNC
	B b;
	int ans = b.func(x, y);
	printf("%d * %d is %d\n", x, y, ans);
#else
	printf("%d * %d is %d\n", x, y,  x * y);
#endif
	return 0;
}