#include <iostream>


int main()
{

	int arr[5] = {}; // this is an array of 0's
	int n = sizeof(arr) / sizeof(arr[0]);

	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';

	int arr2[5] = { 1, 2, 3 }; // array 1, 2, 3, 0, 0
	for (int num : arr2)
	{
		std::cout << num << ' ';
	}
	std::cout << '\n' << "multidimentional array" << '\n';

	int marr[2][3] = {}; //[row][col]
	int row = sizeof(marr) / sizeof(marr[0]);
	int col = sizeof(marr[0]) / sizeof(marr[0][0]);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << marr[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	int marr2[3][4]{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 } 
	};

	for (auto& outer : marr2)
	{
		for (auto& inner : outer)
		{
			std::cout << inner << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	return 0;
}