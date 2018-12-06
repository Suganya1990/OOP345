/*
Name: Suganya Maheswarn
Student number: 048-298-137
email: smaheswaran4@myseneca.ca
date: Nov 16 2018

*/

#ifndef TASK_H
#define TASK_H

#include <functional>
#include <deque>
#include "CustomerOrder.h"

class Task : public Item {
	 std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;

public:
	Task(const std::string&);
	Task(Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&) = delete;
	Task& operator=(Task&&) = delete;

	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
};

#endif
