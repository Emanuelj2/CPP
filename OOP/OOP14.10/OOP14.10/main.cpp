#include <iostream>
#include <optional>

class Fraction
{
private:
	int m_demoninator{ 1 };
	int m_numerator{ 0 };

	Fraction(int denominator, int numerator) : m_demoninator{ denominator }, m_numerator{ numerator }
	{
	}

public:
	// Allow this function to access private members
	friend std::optional<Fraction> createFraction(int denominator, int numerator);
};

std::optional<Fraction> createFraction(int denominator, int numerator)
{
	if (denominator == 0)
	{
		return {};
	}

	return Fraction{ denominator, numerator };
}


int main()
{
	auto f1{ createFraction(1, 1) };
	if (f1)
	{
		std::cout << "Fraction created\n";
	}

	auto f2{ createFraction(0, 0) };
	if (!f2)
	{
		std::cout << "Bad fraction\n";
	}
	return 0;
}