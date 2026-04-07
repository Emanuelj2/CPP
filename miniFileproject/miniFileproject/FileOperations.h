#pragma once

#include <string>
#include <string_view>
#include <vector>

class FileOperations
{
private:
	std::string m_fileName{};
	std::string m_path{ R"(C:\Users\emanu\OneDrive\Python\server_data\)" };
	std::vector<std::string> files{};
	std::string getFullPath(std::string_view fileName) const;

public:

	FileOperations() = default;
	explicit FileOperations(std::string_view fileName);

	std::string getFileName() const;
	void setFileName(std::string_view fileName);

	std::string getPath() const;
	void setPath(std::string_view path);

	void createFile(std::string_view fileName);
	void writeFile(std::string_view content);
	std::string readFile() const;
};
