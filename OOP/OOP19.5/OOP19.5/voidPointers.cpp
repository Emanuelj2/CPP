#include <iostream>

struct Example
{
    int val = 5;
    int num = 10;
};

int main()
{
    int value{};
    int* ptr = &value;

    std::cout << "Address: " << ptr << std::endl;
    std::cout << "Value: " << *ptr << std::endl;

    // Create struct
    Example e_ptr{};

    // Store it in a void pointer
    void* v_ptr = &e_ptr;

    // Cast back to Example*
    Example* castedPtr = static_cast<Example*>(v_ptr);

    // Access struct members
    std::cout << "val: " << castedPtr->val << std::endl;
    std::cout << "num: " << castedPtr->num << std::endl;

    return 0;
}