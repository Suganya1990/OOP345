/*
Name: Suganya Maheswarn
Student number: 048-298-137
email: smaheswaran4@myseneca.ca
date: Nov 16 2018

*/


#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <functional>
#include <vector>
#include <deque>
#include <fstream>
#include "Task.h"
#include "CustomerOrder.h"

class LineManager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;

public:
	LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);

	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;
};

#endif /* LineManager_h */
