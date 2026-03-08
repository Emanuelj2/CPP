#include "Task.h"
#include <iostream>


int Task::s_nextId{ 1 };

Task::Task
(
    std::string_view name,
    std::string_view description,
    Priority priority,
    int day,
    int month,
    int year
)
    : m_id{ s_nextId++ },
    m_name{ name },
    m_description{ description },
    m_priority{ priority },
    m_dueDate{ day, month, year }
{}

//getters
int Task::getId() const
{
	return m_id;
}
std::string_view Task::getName() const
{
	return m_name;
}
std::string Task::getDescription() const
{
	return m_description;
}
Task::Priority Task::getPriority() const
{
	return m_priority;
}
Task::Date Task::getDueDate() const
{
	return m_dueDate;
}

//setters
void Task::setName(std::string_view name)
{
	m_name = name;
}
void Task::setDescription(std::string_view description)
{
	m_description = description;
}
void Task::setPriority(Priority priority)
{
	m_priority = priority;
}
void Task::setDueDate(int day, int month, int year)
{
	m_dueDate = { day, month, year };
}

void Task::displayTask() const
{
	std::cout << "Task ID: " << m_id << "\n";
	std::cout << "Name: " << m_name << "\n";
	std::cout << "Description: " << m_description << "\n";
	std::cout << "Priority: ";
	switch (m_priority)
	{
	case Priority::Low:
		std::cout << "Low";
		break;
	case Priority::Medium:
		std::cout << "Medium";
		break;
	case Priority::High:
		std::cout << "High";
		break;
	default:
		std::cout << "Unknown";
		break;
	}
	std::cout << "\nDue Date: " << m_dueDate.day << "/" << m_dueDate.month << "/" << m_dueDate.year << "\n";

}