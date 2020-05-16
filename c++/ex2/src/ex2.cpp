#include <iostream>
#include </home/sf/Documents/include/rechnung.hpp>
//#include <rechnung.hpp> // export CPLUS_INCLUDE_PATH = path of header
//#include "rech"
using namespace std;
// 只有链接后的可执行文件才能运行，
/**
* g++ -c 输出的目标文件是不能运行的，即使只有一个带ｍａｉｎ的源文件.
* g++ ex2.cpp -o ex2.o 输出的是一个叫ex2.o的可执行文件，不是.o目标文件
* 1.预处理，把include里的文件内容，拷贝到　包含的源文件里，所以　这个文件叫啥，什么.h .hh结尾不重要，重要的是 可访问到，
* ２．编译　把include里内容和源文件翻译成汇编代码
* 3.汇编：　汇编转二进制代码，生成 .o 的目标文件
* 4.链接：　要把所有的目标文件　组成一个完整的二进制代码

为什么ex2.o 不可执行？
因为ex2.o只把头文件的类的声明或者类定义翻译，以及自己的代码翻译成二进制码，
但是没有把头文件中指向的具体函数体实现的二进制代码（库）包含进来，所以代码不完整。

link后
静态库中的二进制代码被拷贝加载过来组成完整的二进制码，可执行。

可执行文件：
二进制代码
完整

除了link的编译，都只是对源文件进行翻译。
翻译：
可确定查找
无语法错误

src2.cpp src2.h
src2.cpp 已经编译成二进制码的目标文件，sr2.h给外部掉用者提供一个声明表借口（指针）让其他源文件包含并调用. 分离式编译
src2.o包含头文件声明部分的二进制码,
正因为各目标文件中包含其他所需文件的文件路径（指针），所以link时可访问到其他目标文件。

link通过个目标文件里函数声明（相互链接的接口）链接成一一个完整的二进制码.


声明
类名　是　各目标文件链接的接口

所有包含头文件的目标文件link成一个完整的二进制码.

库：
多个目标文件打包成一起并插入名字查找表
*/
int main(int argc, char const *argv[]){	
	int a = 11, b = 20, out;

	cout << "include path changed as path" << endl;
	if ( add(a, b, out) )
		cout << out << endl;
	return 0;
}