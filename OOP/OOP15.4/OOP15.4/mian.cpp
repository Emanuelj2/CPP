#include <iostream>
#include <string>
#include <vector>

//simple destructor practice
//class Simple
//{
//private:
//	int m_id{};
//public:
//
//	//constructor
//	Simple(int id)
//		: m_id{ id }
//	{
//		std::cout << "Constructing Simple " << m_id << '\n';
//	}
//	//destructor
//	~Simple()
//	{
//		std::cout << "Destructing Simple " << m_id << '\n';
//	}
//
//	int getId() const
//	{
//		return m_id;
//	}
//
//};

class SessionLogger
{
private:
	std::string m_filename{};
	std::vector<std::string> m_buffer{};
	bool m_saved{ false };

public:
	SessionLogger(std::string_view filename)
		:m_filename{ filename }
	{
		std::cout << "Session started\n";
	}

	SessionLogger(const SessionLogger&) = delete;

	SessionLogger& operator=(const SessionLogger&) = delete;

	void log(std::string_view message)
	{
		m_buffer.push_back(std::string(message));
	}

	void save()
	{
		if (m_saved)
			return;
		std::cout << "Saving logs to " << m_filename << "\n";

		for (const auto& msg : m_buffer)
		{
			std::cout << "Writing: " << msg << "\n";
		}

		m_buffer.clear();
		m_saved = true;
	}
	~SessionLogger()
	{
		try
		{
			if (!m_saved && !m_buffer.empty())
			{
				std::cout << "Destructor auto-saving session...\n";
				save();
			}
		}
		catch (...)
		{
			std::cerr << "Failed to save session logs\n";
		}
	}


};

int main()
{
	//// Allocate a Simple
	//Simple simple1{ 1 };
	//{
	//	Simple simple2{ 2 };
	//} // simple2 dies here

	SessionLogger logger("session.txt");

	logger.log("User logged in");
	logger.log("User clicked button");
	logger.log("User logged out");

	// No explicit save()

	return 0;

	return 0;
}