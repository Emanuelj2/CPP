#include <iostream>
#include <algorithm>
#include <string_view>
#include <array>

int main()
{
	std::array<std::array<std::string_view, 3>, 5> multidiensional_arr
	{ {
		{"hello1", "hello2", "hello3" },
		{ "hello4", "hello5", "hello6" },
		{ "hello7", "hello8", "hello9" },
		{ "hello10", "hello11", "hello12" },
		{ "hello13", "hello14", "hello15" }
	} };

	std::cout << "enter a string to look for";
	std::string word{};
	std::cin >> word;



	auto it = std::find_if(multidiensional_arr.begin(), multidiensional_arr.end(), 
		[&](const std::array<std::string_view, 3 >& row) 
		{
			return std::find(row.begin(), row.end(), word) != row.end(); 
		}
	);

	if (it != multidiensional_arr.end())
	{
		std::cout << "target found" << std::endl;
	}
	else
	{
		std::cout << "target not found" << std::endl;
	}


	//<------------------------------------------------------>//

	std::array arr{ 13, 90, 99, 5, 40, 80 };
	std::cout << "Enter a value to search for and replace with: ";

	int search{};
	int replace{};

	std::cin >> search >> replace;
	
	auto found = std::find(arr.begin(), arr.end(), search);
	
	if (found != arr.end())
	{
		std::cout << "found the target" << std::endl;
		// Override the found element.
		*found = replace;
	}
	else {
		std::cout << "not found" << std::endl;
	}

	//print the array
	for (const int& e : arr)
	{
		std::cout << e << ' ';
	}
	std::cout << std::endl;

	//<------------------------------------------------------>//

	std::array<int, 5> nums {1, 2, 20, 4, 5};
	
	std::sort(nums.begin(), nums.end(), std::greater{});
	
	for (int num : nums)
	{
		std::cout << num << ' ';
	}
	return 0;
}

/*
| Capture   | Meaning                        | How it works                       | Can modify original? | When to use                             |
| --------- | ------------------------------ | ---------------------------------- | -------------------- | --------------------------------------- |
| `[ ]`     | Capture nothing                | No outside variables allowed       | ❌ No                 | Pure functions, safest                  |
| `[=]`     | Capture all by value           | Makes **copies** of used variables | ❌ No (read-only)     | Safe, no side effects                   |
| `[&]`     | Capture all by reference       | Uses **original variables**        | ✅ Yes                | When you need to modify or avoid copies |
| `[x]`     | Capture `x` by value           | Copy only `x`                      | ❌ No                 | Precise + safe                          |
| `[&x]`    | Capture `x` by reference       | Use real `x`                       | ✅ Yes                | Modify specific variable                |
| `[=, &x]` | Mostly value, `x` by reference | Copy others, reference `x`         | `x` ✅ others ❌       | Fine-grained control                    |
| `[&, x]`  | Mostly reference, `x` by value | Reference others, copy `x`         | others ✅, `x` ❌      | Avoid modifying one variable            |
*/