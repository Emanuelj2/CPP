#include <iostream>
#include <string>

//class Chaining
//{
//private:
//	std::string m_name{""};
//	int m_age{};
//
//public:
//	Chaining() = default;
//
//	Chaining(std::string_view name, int age)
//		: m_name { name }, m_age { age }
//	{}
//
//	Chaining& setName(std::string name)
//	{
//		m_name = name;
//		return *this;
//	}
//
//	Chaining& setAge(int age)
//	{
//		m_age = age;
//		return *this;
//	}
//
//	void print()const
//	{
//		std::cout << m_name << " " << m_age << "\n";
//	}
//};

class Calc 
{
private:
	int m_value{};
public:
	Calc& add(int value)
	{
		m_value = value;
		return *this;
	}
	Calc& sub(int value)
	{
		m_value -= value;
		return *this;
	}
	Calc& mult(int value)
	{
		m_value *= value;
		return *this;
	}

	int getValue() const
	{
		return m_value;
	}

	void reset()
	{
		*this = {};
	}
};

int main()
{
	//Chaining c;
	//c.setName("Emanuel").setAge(22).print();
	//Chaining c2{ "Emanuel", 23 };
	//c2.print();

	Calc calc{};
	calc.add(5).sub(3).mult(4);
	std::cout << calc.getValue() << '\n'; // prints 8
	calc.reset();
	std::cout << calc.getValue() << '\n'; // prints 0

	return 0;
}



