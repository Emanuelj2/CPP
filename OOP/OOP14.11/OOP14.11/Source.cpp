#include <iostream>

class Function {
private:
	int m_x{};
	int m_y{};
public:

	//constructor with default values
	Function(int x = 0, int y = 0) : m_x { x }, m_y { y }
	{
		std::cout << "Function(" << m_x << ", " << m_y << ") constructed\n";
	}

};

//overloaded constructors
class Foo
{
private:
	int m_x{};
	int m_y{};
public:
	Foo() = default; //i am explicitly making this a default constructor

	Foo(int x, int y) : m_x{ x }, m_y{ y }
	{
		std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
	}
};

//below is some side code dont refer to this
class A
{
public:

	//virtual
	void show()
	{
		std::cout << "A\n";
	}
};

class B : public A
{
public:
	void show()
	{
		std::cout << "B\n";
	}
};

int main()
{
	Function f1;
	Function f2{ 1, 5 };

	Foo foo1;
	Foo foo2{ 6, 7 };

	A* obj = new B;
	obj->show();

	return 0;
}