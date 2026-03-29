#include <iostream>
#include <array>


//alias for two-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;


//making it a generic
template<typename T, std::size_t Row, std::size_t Col>
void printArray(const std::array<std::array<T, Col>, Row>& arr)
{
	for (auto& arow : arr) //get each row form array
	{
		for (auto& element : arow) //get each element of the row
			std::cout << element << ' ';

		std::cout << '\n';
	}
}

int main()
{
	int multidimensionalArray[3][4] =
	{
		{1, 2, 3, 4},
		{6, 7, 8, 9},
		{11, 12,13, 14}
	};

	//or

	std::array<std::array<int, 4>, 3> arr {{
		{1, 2, 3,4},
		{5, 6, 7,8},
		{9, 10, 11, 12}}};
	printArray(arr);

	std::array<std::array<char, 4>, 3> charArr{{
		{'a', 'b', 'c', 'd'},
		{'e', 'f', 'g', 'h'},
		{'i', 'j', 'j', 'l'}}};
	printArray(charArr);

	//using the premade 2d array
	Array2d<int, 3, 4> arr2{ {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 }} };
	printArray(arr2);

	//std::cout << "Row length " << arr2.size() << '\n';
	//std::cout << "Col length " << arr2[0].size() << '\n';

	return 0;
}

//NOTES:
/*
notice that the when using the std::array lib, the way that
we make a two dimensional array is the reverse of the normal
way of initializing the array for example in the first methid
of initializing the array it is in [row][col] where as in the 
second method it is in reverse [col][row].
*/