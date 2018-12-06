/*
Name: Suganya Maheswarn
Student number: 048-298-137
email: smaheswaran4@myseneca.ca
date: Nov 16 2018

*/



#include<iostream>
#include<utility>
#include<vector>
#include<fstream>
#include<string>
#include"LineManager.h"
#include"Utilities.h"
#include"Task.h"
using namespace std;

LineManager::LineManager(const std::string& filename, std::vector<Task*>& tasks, std::vector<CustomerOrder>& Order)
{
	for (size_t i = 0; i < tasks.size(); i++)
	{
		AssemblyLine.push_back(move(tasks[i]));
	}

	for (size_t i = 0; i < Order.size(); i++)
	{
		ToBeFilled.push_front(move(Order[i]));
		m_cntCustomerOrder++; 
	}


	
	std::fstream file(filename);
	Utilities d;
	std::string temp;
	std::string token;

	while (getline(file, temp))
	{
		size_t pos = 0;
		bool flag = true;

		token = d.extractToken(temp, pos, flag);
		for (size_t i = 0; i < tasks.size(); i++)
		{
			if (tasks[i]->getName() == token)
			{
				if (pos != 0 )
				{
					token = d.extractToken(temp, pos, flag);

					for (size_t j = 0; j < tasks.size(); j++)
					{
						if (tasks[j]->getName() == token)
						{
							tasks[i]->setNextTask(*AssemblyLine[j]);
							j = tasks.size();
						}




					}
					i = tasks.size();
				}

			}
		}

	}



}
bool LineManager::run(std::ostream& os)
{

	if (ToBeFilled.size() != 0)
	{
		*AssemblyLine.at(4) += std::move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine.at(i)->runProcess(os);
	}
	for (size_t i = 0; i < AssemblyLine.size(); i++) {

		if (AssemblyLine[i]->moveTask()) {
			CustomerOrder order;

			if (AssemblyLine[i]->getCompleted(order))
				Completed.push_back(std::move(order));
		}
	}

	if (ToBeFilled.empty() && Completed.size() == m_cntCustomerOrder) return true;
	return false;


}
void LineManager::displayCompleted(std::ostream& other) const
{
	for (size_t i = 0; i < Completed.size(); i++)
	{
		if (Completed[i].getOrderFillState()) Completed[i].display(other);
	}

}
void LineManager::validateTasks() const
{
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->validate(std::cout);
	}
}
