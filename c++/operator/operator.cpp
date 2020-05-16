/**
class.func()  ==> classOperator符号
Instance[ｎ] 等效于　Instance.access(n);
obj3 = obj1 + obj2 等效于 obj3 = obj1.add(pbj2);
*/

#include <iostream>
using namespace std;

#ifndef SIZE
#define SIZE 10
#endif

class Box {
private:
int length;      // 长度
int breadth;     // 宽度
int height;      // 高度
int array[SIZE];
public:

	Box(int a, int b , int c ) : length(a), breadth(b), height(c) {
		for (int i = 0; i < SIZE; i++) {
			array[i] = i*i;
		}
	}
	Box() = default;
	~Box() = default;
	Box(const Box& another) {
        cout << this << "--copy constructor from--" << & another << endl;
    }
    void operator=(const Box& other) {
    	length = other.length;
		breadth = other.breadth;
		height = other.height;
        cout << this << "--assignment operator overloading from--" << &other << endl;
    }

  //    void operator=(const Box other) {
  //   	length = other.length;
		// breadth = other.breadth;
		// height = other.height;
  //       cout << this << "--assignment operator overloading2 from--" << &other << endl;
  //   }
public:

	int getVolume(void) {
         return length * breadth * height;
    }

	const Box operator+(const Box& b) {
		 Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
	}

	Box operator()(int a, int b) {
		Box box;
		box.length = a +100;
		box.breadth =  b + 200;
		box.height = 300;
		return box;
	}

	void operator()(int a, int b,int c) {
		length = a +100;
		breadth =  b + 200;
		height =  c + 300;
	}

	int operator[](const int n) {
		if ( n < 0 || n > SIZE - 1) {
			cout <<"Error[]" << endl;
			return -1;
		}else {
			return array[n];
		}
	}

		  // opj << cout;
	void operator<<(ostream& output) {
		output <<"void operator<<(ostream& output) : \n";
		output << " length = " << length;
		output << " breadth = " << breadth;
		((output << " height = ") << height) << endl;
	}

	// output = (output << box)
    friend std::ostream& operator<<(ostream& output, const Box& box) {
		output <<"friend std::ostream& operator<<(ostream& output, const Box& box) :\n ";
		output << " length = " << box.length;
		output << " breadth = " << box.breadth;
		output << " height = " << box.height << endl;
		return output;
	}

    friend std::istream& operator>>(istream& input,  Box& box) {
		input >> box.length >> box.breadth >> box.height;
		return input;
	}

	

	void printfValue() {
		cout << "length = " << length;
		cout << " breadth = " << breadth;
		cout << " height = " << height << endl;
	}
};

int main () {
	 Box box1(10, 20, 30);
     Box box2(1, 2, 3); 
     Box Box3 = box1 + box2;
     Box box4,box5,box6;
     box4 = box1(222, 666);
     box5(11,22,33);

     box1.printfValue();
     box2.printfValue();
     Box3.printfValue();
     box4.printfValue();
     box5.printfValue();
     cout << "box1.getVolume: " << box1.getVolume()  << endl;
     cout << "box2.getVolume: " << box2.getVolume()  << endl;
     cout << "Box3.getVolume: " << Box3.getVolume()  << endl;
     cout << "box4.getVolume: " << box4.getVolume()  << endl;
     cout << "box1[]: " << box1[3]  << endl;
     cin >> box6;
     cout << "box6" << box6 << endl;

     cout << "<<box1: "; 
     box1<<cout;

     cout << "<<box2: " << endl;
     cout << box2;

     //一旦使用　cout <<　调用 cout的<<函数，　不会解析为类自定义的重载符<<  
     //cout << box2 << cout;
	 return 0;
}