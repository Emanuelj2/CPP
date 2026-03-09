#include "User.h"
#include <iostream>

int User::s_nextId{ 1 };

User::User(std::string_view name, std::vector<Task> task) : m_id{ s_nextId++ }, m_name{ name }, m_task{ task }
{}

//getters
int User::getId() const
{
	return m_id;
}

std::string_view User::getName() const
{
	return m_name;
}

const std::vector<Task>& User::getTasks() const
{
	return m_task;
}

//setters
void User::setName(std::string_view name)
{
	m_name = name;
}

void User::workOnTask(int taskId)
{
	for (const auto& task : m_task)
	{
		if (task.getId() == taskId)
		{
			std::cout << "Working on task: " << task.getName() << "..." << std::endl;
			return;
		}
	}
	std::cout << "Task with ID " << taskId << " not found." << std::endl;
}