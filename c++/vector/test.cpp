#include <vector>
#include <iostream>
using namespace std;
/**
函数原型：
void assign(const_iterator first,const_iterator last);
void assign(size_type n,const T& x = T());
功能：
将区间[first,last)的元素赋值到当前的vector容器中，或者赋n个值为x的元素到vector容器中，这个容器会清除掉vector容器中以前的内容。
*/

/**
.back();
返回最后一个元素的引用
*/
int main( )
{
	 vector<int> v1, v2, v3;
	 vector<int>::iterator iter;
	 v1.push_back(10);
	 v1.push_back(20);
	 v1.push_back(30);
	 v1.push_back(40);
	 v1.push_back(50);
	 v2.push_back(1);
	 v2.push_back(2);

	 cout << "v1 = " ;
	 for (iter = v1.begin(); iter != v1.end(); iter++)
	  cout << *iter << " ";
	 cout << endl;

	cout << "v2 = ";
	 for (iter = v2.begin(); iter != v2.end(); iter++)
	  cout << *iter << " ";
	 cout << endl;
	
	 v2.assign(v1.begin(), v1.end());
	 cout << "\nv2.assign(v1.begin(), v1.end()):\nv2 = ";
	 for (iter = v2.begin(); iter != v2.end(); iter++)
	  cout << *iter << " ";
	 cout << endl;
	
	 v3.assign(7, 3) ;
	 cout << "\nv3.assign(7, 3)\nv3 = ";
	 for (iter = v3.begin(); iter != v3.end(); iter++)
	  cout << *iter << " ";
	 cout << endl;
	
	cout << "\nv1.front(): "<< v1.front() << endl;

	cout << "\nv1.back(): "<< v1.back() << endl;

	cout << "\nv1.pop_back(): "<< endl;
    v1.pop_back();

	cout << "\nv1.push_back(): "<< endl;
	v1.push_back(100);

	cout << "\nv1.insert(v1.begin() + 3, 3): "<<endl;
	v1.insert(v1.begin() + 3, 3);

	cout << "\nv1.erase(v1.begin() + 1): "<< endl;
	v1.erase(v1.begin() + 1);

	 cout << "v1 = " ;
	 for (iter = v1.begin(); iter != v1.end(); iter++)
	  cout << *iter << " ";
	 cout << endl;

	cout << "size: " << (int) v1.size() << '\n';
  	cout << "capacity: " << (int) v1.capacity() << '\n';
	cout << "max_size: " <<  v1.max_size() << '\n';;
	 return 0;

	}