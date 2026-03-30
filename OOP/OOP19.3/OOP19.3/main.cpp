#include <iostream>
#include <cassert>
#include <cstddef>

class IntArray
{
private:
	int* m_array{};
	int m_length{};

public:
	//constructor
		IntArray( int length): m_length { length }
		{
			assert(length > 0);

			m_array = new int[static_cast<std::size_t>(length)] {};
			m_length = length;
		}

	//destructor
		~IntArray()
		{
			std::cout << "destroy" << std::endl;
			delete[] m_array;
		}

		void setValue(int index, int value)
		{
			m_array[index] = value;
		}

		int getValue(int index)
		{
			return m_array[index];
		}

		int getLength()
		{
			return m_length;
		}
};

class Simple
{
private:
	int m_id{};
public:
	Simple(int id) : m_id{ id }
	{
		std::cout << "Constructiong Simple" << m_id << '\n';
	}

	~Simple()
	{
		std::cout << "Destructing Simple" << m_id << '\n';
	}

	int getId() { return m_id; }
};




int main()
{
	IntArray ar(10); // allocate 10 integers
	for (int count{ 0 }; count < ar.getLength(); ++count)
		ar.setValue(count, count + 1);

	std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

	std::cout << std::endl;

	// Allocate a Simple on the stack
	Simple simple{ 1 };
	std::cout << simple.getId() << '\n';

	// Allocate a Simple dynamically
	Simple* pSimple{ new Simple{ 2 } };

	std::cout << pSimple->getId() << '\n';

	// We allocated pSimple dynamically, so we have to delete it.
	delete pSimple;

	return 0;

	return 0;
}