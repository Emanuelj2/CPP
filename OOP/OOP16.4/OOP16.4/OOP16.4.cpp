#include <iostream>
#include <vector>

//we can incrperate the tempalte parameter declaration
template<typename T>
void passByRef(const std::vector<T>& nums)//we typically pass std::vector by (const) reference to avoid such copies
{
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << "\n";
	}
}


//Write a function that takes two parameters: a std::vector and an index.
// If the index is out of bounds, print an error.
// If the index is in bounds, print the value of the element.

template<typename T>
void twoParams(const std::vector<T>& vect, int index)
{
	//get the size of the vector
	int n = vect.size();

	if ( index >= 0 && index <= n - 1)
	{
		std::cout << vect[index] << std::endl;
	}
	else
	{
		std::cout << "index is out of bounds, print an error\n";
	}

}

template<typename T>
void print(const std::vector<T> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << "\n";
}

template<typename T>
void printCapLen(const std::vector<T>& vect)
{
	std::cout << "Capacity: " << vect.capacity() << " Length: " << vect.size() << std::endl;
}

int main()
{
	std::cout << "integers\n";
	std::vector nums { 1, 2, 3, 4, 5 }; //CTAD will work to deduce an vector’s element type from initializers when it is defined
	passByRef(nums);

	std::cout << "doubles\n";
	std::vector doubles { 1.1, 1.2, 1.3, 1.4, 1.5 };
	passByRef(doubles);

	std::cout << "charachters\n";
	std::vector chars { 'a', 'b', 'c', 'd', 'e' };
	passByRef(chars);

	std::cout << "\ntwo params function\n";
	std::vector v1{ 0, 1, 2, 3, 4 };
	twoParams(v1, 2);
	twoParams(v1, 5);

	std::vector v2{ 1.1, 2.2, 3.3 };
	twoParams(v2, 0);
	twoParams(v2, -1);

	//a vector can be resized
	std::vector n1{ 0, 1, 2 };
	print(n1);

	n1.resize(5);
	print(n1);

	std::vector n2{ 0, 1, 2, 3, 4, 5 };
	print(n2);
	n2.resize(3);
	print(n2);
	
	//capacity vs length of a vector
	std::cout << std::endl;
	std::vector n3{ 1, 2, 3, 4 };
	printCapLen(n3);
	print(n3);
	n3.resize(6);
	printCapLen(n3);
	print(n3);
	
	return 0;
}