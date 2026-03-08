// TaskManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Task.h"

int main()
{
	Task t1{ "Task 1", "Description of Task 1", Task::Priority::High, 15, 10, 2024 };
	t1.displayTask();

    
}

