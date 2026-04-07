#include "FileOperations.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <filesystem>

FileOperations::FileOperations(std::string_view fileName) : m_fileName{ fileName } {}

std::string FileOperations::getFileName() const { return m_fileName; }
void FileOperations::setFileName(std::string_view fileName) { m_fileName = fileName; }

std::string FileOperations::getPath() const { return m_path; }
void FileOperations::setPath(std::string_view path) { m_path = path; }

std::string FileOperations::getFullPath(std::string_view fileName) const
{
    return m_path + std::string(fileName);
}

void FileOperations::createFile(std::string_view fileName)
{
    std::string fullPath = getFullPath(fileName);

    auto it = std::find(files.begin(), files.end(), fullPath);
    if (it != files.end())
    {
        std::cout << "File already exists.\n";
        return;
    }

    std::filesystem::create_directories(m_path);

    std::fstream file{ fullPath, std::ios::out };
    if (file.is_open())
    {
        files.push_back(fullPath);
        std::cout << "File created: " << fullPath << "\n";
    }
    else
    {
        std::cout << "Failed to create file.\n";
    }
}

std::string FileOperations::readFile() const
{
    std::string fullPath = getFullPath(m_fileName);
    std::ifstream file{ fullPath };
    if (!file.is_open())
    {
        std::cout << "Could not open file.\n";
        return {};
    }

    return std::string{ std::istreambuf_iterator<char>(file),
                        std::istreambuf_iterator<char>() };
}

void FileOperations::writeFile(std::string_view content)
{
    std::string fullPath = getFullPath(m_fileName);
    std::ofstream file{ fullPath, std::ios::app };
    if (!file.is_open())
    {
        std::cout << "Could not open file.\n";
        return;
    }
    file << content;
}