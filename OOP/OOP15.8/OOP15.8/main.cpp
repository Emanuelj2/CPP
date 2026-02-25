#include <iostream>

class Accumulator
{
private:
	static inline int m_value{ 0 };

public:
	void add(int value)
	{
		m_value += value;
	}

	friend void print(const Accumulator& accumulator);

	//Friend functions defined inside a class are non-member functions (this is very intresting)
	friend void print2(const Accumulator& accumulator)
	{
		std::cout << accumulator.m_value << "\n";
	}
};

void print(const Accumulator& accumulator) //we are referencing the class this allows it to be accessed and insted of making a copy we are directly making changes
{
	std::cout << accumulator.m_value << "\n";
}


//a function can be a friend to multiple classes
class Humidity; //forawrd decloration

class Temperature
{
private:
	int m_temp{};
public:
	Temperature(int temp)
		: m_temp { temp }
	{ }

	friend void printWeather(const Temperature& temp, const Humidity& humidity);
};

class Humidity
{
private:
	int m_humidity{};

public:

	Humidity(int humidity)
		: m_humidity { humidity }
	{ }

	friend void printWeather(const Temperature& temperature, const Humidity& humidity);

};

void printWeather(const Temperature& temperature, const Humidity& humidity)
{
	std::cout << "The temperature is " << temperature.m_temp <<
		" and the humidity is " << humidity.m_humidity << '\n';
}

int main()
{
	Accumulator acc{};
	acc.add(5); // add 5 to the accumulator
	print(acc); // call the print() non-member function

	Accumulator acc2{};
	acc2.add(20);
	print2(acc2); // call the print2() non-member function


	Humidity hum{ 10 };
	Temperature temp{ 12 };
	printWeather(temp, hum);

	return 0;
}