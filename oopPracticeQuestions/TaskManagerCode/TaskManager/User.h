#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Task.h"

class User
{
private:
	static int s_nextId; //used to generate unique IDs for users
	int m_id{};
	std::string m_name{};
	std::vector<Task> m_task{};
public:

	User(std::string_view name, std::vector<Task> task);

	//getters
	int getId() const;
	std::string_view getName() const;
	const std::vector<Task>& getTasks() const; //print out the tasks of the user

	//setters
	void setName(std::string_view name);
	void workOnTask(int taskId);

	void assignTask(Task task);

};

#endif
