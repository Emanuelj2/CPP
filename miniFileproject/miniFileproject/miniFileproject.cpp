#include <iostream>
#include "AppInfo.h"
#include "FileOperations.h"

int main()
{
    AppInfo ai;
    FileOperations fo{};
    int choice{};

    while (true)
    {
        ai.displayOptions();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string name{};
            std::cout << "Enter file name: ";
            std::cin >> name;
            fo.createFile(name);
            fo.setFileName(name);
            break;
        }
        case 2:
            if (fo.getFileName().empty())
            {
                std::cout << "No file selected. Create a file first.\n";
                break;
            }
            std::cout << fo.readFile() << "\n";
            break;
        case 3:
            if (fo.getFileName().empty())
            {
                std::cout << "No file selected. Create a file first.\n";
                break;
            }
            else
            {
                std::string content{};
                std::cout << "Enter content: ";
                std::cin.ignore();
                std::getline(std::cin, content);
                fo.writeFile(content);
                break;
            }
        case 4:
            std::cout << "Exiting.\n";
            return 0;
        default:
            std::cout << "Invalid option.\n";
        }
    }
}