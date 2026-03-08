#ifndef  TASK_H
#define  TASK_H

#include <string>
#include <string_view>

class Task
{
private:
	static int s_nextId; //used to generate unique IDs for tasks

	enum class Priority
	{
		Low ,
		Medium ,
		High ,
	};

	struct Date
	{
		int day{};
		int month{};
		int year{};
	};

	int m_id{};
	std::string m_name{};
	std::string m_description{};
	Priority m_priority{};
	Date m_dueDate{};

public:

	Task(
		std::string_view name,
		std::string_view description,
		Priority priority,
		int day,
		int month,
		int year);

	//getters
	int getId() const;
	std::string_view getName() const;
	std::string getDescription() const;
	Priority getPriority() const;
	Date getDueDate() const;

	//setters
	void setName(std::string_view name);
	void setDescription(std::string_view description);
	void setPriority(Priority priority);
	void setDueDate(int day, int month, int year);

	void displayTask() const;


};
#endif // ! TASK_H

