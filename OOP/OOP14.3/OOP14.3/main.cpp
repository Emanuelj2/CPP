#include <iostream>
#include <string>
#include <string_view>

class Date
{
public:
	int day{};
	int month{};
	int year{};

	void print()
	{
		std::cout << "day: " << day << ", month: " << month << ", year: " << year << "\n";
	}
};

void non_mem_print(const Date& date)
{
	std::cout << "day: " << date.day << ", month: " << date.month << ", year: " << date.year << "\n";
}


class Person
{
public:
	std::string name{};
	int age{};

	void Kisses(const Person& person)
	{
		std::cout << name << " Kisses " << person.name << std::endl;
	}
};

class Date2
{
public:
	int day{};
	int month{};
	int year{};


	void print2()
	{
		std::cout << "day: " << day << ", month: " << month << ", year: " << year << "\n";
	}

	void print2(std::string_view prefix)
	{
		std::cout  << prefix << "day: " << day << ", month: " << month << ", year: " << year << "\n";
	}

};


//priatice Provide the definition for IntPair and the print() member function here

struct IntPair
{
	int num1{};
	int num2{};

	void print()
	{
		std::cout << "Pair(" << num1 << ", " << num2 << ")\n";
	}

	bool isEqual(IntPair a)
	{
		return (num1 == a.num1) && (num2 == a.num2);
	}
};

int main()
{
	
	Date today{ 13, 2, 2026 };
	today.day = 14; //change the day to 14
	today.print(); //member print

	non_mem_print(today); //non member print
	

	Person joe{ "Joe", 20 };
	Person jane{ "Jane", 20 };
	joe.Kisses(jane);

	Date2 today2{ 23, 2, 2026 };
	today2.print2();
	today2.print2("This is todays date -> ");


	IntPair p1{ 1, 2 };
	IntPair p2{ 3, 4 };

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	

	

}