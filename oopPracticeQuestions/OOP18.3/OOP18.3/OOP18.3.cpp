// OOP18.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <string_view>
#include <algorithm>
#include <string>

int main()
{
    std::string str = "abccbacdh";


	size_t pos = str.find("cbac");
    if (pos != std::string::npos)
    {
        std::cout << "Found substring at index: " << pos << "\n";
    }
    else
    {
        std::cout << "Not found\n";
    }
    std::cout << std::endl;

	std::array<std::string_view, 3> arr = { "abfc", "badc", "cbacad" };

	//scan the array to see if any of the elements constain the substring "aca"
	auto it = std::find_if(arr.begin(), arr.end(), [](const auto& s) {
        return s.find("aca") != std::string_view::npos;
    });

    if (it == arr.end())
    {
        std::cout << "not foud";
    }
    else
    {
        std::cout << "found in string " << *it << " index " << (it - arr.begin()) + 1 << std::endl;
    }

    return 0;
}
