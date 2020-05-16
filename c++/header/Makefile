out: A.cpp B.cpp C.cpp main.cpp A.hpp B.hpp C.hpp
	g++ -E -std=c++11 A.cpp -o A.i
	g++ -E -std=c++11 B.cpp -o B.i
	g++ -E -std=c++11 C.cpp -o C.i
	g++ -E -std=c++11 main.cpp -o main.i
	g++ -S -std=c++11 A.cpp -o A.s
	g++ -S -std=c++11 B.cpp -o B.s
	g++ -S -std=c++11 C.cpp -o C.s
	g++ -S -std=c++11 main.cpp -o main.s
	g++ -std=c++11 A.cpp B.cpp C.cpp main.cpp -o out

