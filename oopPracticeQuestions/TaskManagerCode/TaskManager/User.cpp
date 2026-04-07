#include "User.h"
#include <iostream>
#include <chrono>
#include <thread>

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
	for (auto it = m_task.begin(); it != m_task.end(); ++it)
	{
		if (it->getId() == taskId)
		{
			std::cout << "Working on task: " << it->getName() << "..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "Finished task " << it->getName() << std::endl;
			m_task.erase(it);  // remove the task
			return;
		}
	}
	std::cout << "Task with ID " << taskId << " not found." << std::endl;
}


//TODO: 
void User::assignTask(Task task)
{
	m_task.push_back(task);
}