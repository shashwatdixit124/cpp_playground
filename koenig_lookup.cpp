/*
 *  Shashwat Dixit <shashwatdixit124@gmail.com>
 *  Reference : https://www.youtube.com/watch?v=TxgPZXe8XTo
 */

// Koenig Lookup works with NameSpaces and Not with Classes

#include <iostream>

//-----------------------------------------------------------

/*
namespace A 
{
	struct X{};
	void print(X) { std::cout << "calling A::print \n" ; }
}

void test()
{
	A::X x;
	print(x);
}
*/

//-----------------------------------------------------------

/*
namespace A
{
	struct X{};
	void print(X) { std::cout << "calling A::print \n" ; }
}
namespace B
{
	struct X{};
	void print(A::X) { std::cout << "calling B::print \n" ; }
}

void test()
{
	A::X x;
	print(x);
}
*/

//-----------------------------------------------------------
/*

class A
{
public:
	struct X{};
	void print(A::X) { std::cout << "calling A::print \n" ; }
};

void test()
{
	A::X x;
	print(x);
}
*/

//-----------------------------------------------------------


namespace A
{
	struct X{};
	void print(X) { std::cout << "calling A::print \n" ; } 
}

class B
{
public:
	void print(A::X) { std::cout << "calling B::print \n" ; }
	void btest() 
	{
		A::X x;
		using A::print;
		print(x);
	}
};

void test()
{
	B b;
	b.btest();
}


//-----------------------------------------------------------

int main(int argc, char* argv[])
{
	test();
}

