#include <iostream>
#include <iterator>
#include <utility>
#include <algorithm>

int main()
{
    int array[]{ 30, 50, 40, 10, 20 };
    constexpr int length{ static_cast<int>(std::size(array)) }; 
    //the constexpr mean that the length is going to be evaluated at compile time insted of run time
    //cast converts it to int so it matches the loop variable type. 
    //Note that size() is size_t by default


    //selection sort accending order
    std::cout << "accending order\n";
    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
    {
        int smallestIndex = { startIndex };

        for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
        {
            if (array[currentIndex] < array[smallestIndex])
            {
                smallestIndex = currentIndex;
            }
        }
        std::swap(array[startIndex], array[smallestIndex]);
    }
    
    for (int index{ 0 }; index < length; ++index)
    {
        std::cout << array[index] << ' ';
    }

    //////////////////////////////////////////////////////////////
    int array1[]{ 1, 4, 6, 2, 8, 3, 7, 5 };
    constexpr int length1 = static_cast<int>(std::size(array1));
    std::cout << "\ndecending order\n";
    for (int start{ 0 }; start < length1; ++start)
    {
        int largestIndex{ start };
        for (int currIdex{ start + 1 }; currIdex < length; ++currIdex)
        {
            if (array[currIdex] > array[largestIndex])
            {
                largestIndex = currIdex;
            }
        }
        std::swap(array[start], array[largestIndex]);
    }

    for (int index{ 0 }; index < length; ++index)
    {
        std::cout << array[index] << ' ';
    }
    
    //////////////////////////////////////////////////////////////
    std::cout << '\n' << "array with the sort algorithm\n";
    int array2[]{ 30, 50, 20, 10, 40 };

    std::sort(std::begin(array2), std::end(array2));
    for (int i{ 0 }; i < static_cast<int>(std::size(array2)); ++i)
    {
        std::cout  << array2[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}

