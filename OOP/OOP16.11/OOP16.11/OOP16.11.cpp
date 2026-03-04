//objective:
//Write a program that pushes and pops values, and outputs the following sequence :
//(Stack: empty)
//Push 1 (Stack : 1)
//Push 2 (Stack : 1 2)
//Push 3 (Stack : 1 2 3)
//Pop(Stack : 1 2)
//Push 4 (Stack: 1 2 4)
//Pop(Stack: 1 2)
//Pop(Stack: 1)
//Pop(Stack: empty)

#include <iostream>
#include <vector>

class Stack
{
private:
    std::vector<int> m_stk{};

    void printState() const
    {
        std::cout << "(Stack: ";

        if (m_stk.empty())
        {
            std::cout << "empty";
        }
        else
        {
            for (int value : m_stk)
            {
                std::cout << value << " ";
            }
        }

        std::cout << ")";
    }

public:

    void push(int num)
    {
        m_stk.push_back(num);

        std::cout << "Push " << num << " ";
        printState();
        std::cout << "\n";
    }

    void pop()
    {
        if (m_stk.empty())
        {
            std::cout << "Pop    ";
            printState();
            std::cout << "\n";
            return;
        }

        m_stk.pop_back();

        std::cout << "Pop    ";
        printState();
        std::cout << "\n";
    }
};


int main()
{
    Stack s;

    std::cout << "(Stack: empty)\n";

    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4);
    s.pop();
    s.pop();
    s.pop();
}

