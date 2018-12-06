/*
Name: Suganya Maheswarn
Student number: 048-298-137
email: smaheswaran4@myseneca.ca
date: Nov 16 2018

*/



#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include"Task.h"
#include"Utilities.h"

Task::Task(const std::string& record) :Item(record)
{
	m_pNextTask = nullptr;
}


void Task::runProcess(std::ostream& os)
{

	if (m_orders.size() > 0)
	{
		if (this->m_orders.back().getOrderFillState() == false)
		{
			m_orders.back().fillItem(std::ref(*this), os);
		}

	}
}
bool Task::moveTask()
{
	if (m_orders.size() == 0)
	{
		return false;

	}

	
	
		if (m_orders.back().getItemFillState(this->getName()) == true)
		{

			if (m_pNextTask != nullptr)
			{
				(*m_pNextTask) += std::move(m_orders.back());
				m_orders.pop_back();
				
			}

		}
		return true;

}
void Task::setNextTask(Task& nextTask)
{
	if (m_pNextTask != nullptr)
		delete m_pNextTask;
	m_pNextTask = &nextTask;
}
bool Task::getCompleted(CustomerOrder& other)
{

	if (m_orders.size() == 0)
		return false;
	else
	{
		if (m_orders.back().getOrderFillState())
		{
			other = std::move(m_orders.back());

			m_orders.pop_back();
			return true;

		}
		else
			return false;

	}
}
void Task::validate(std::ostream& os)
{
	os << this->getName() << " --> ";
	if (m_pNextTask)
	{
		os << m_pNextTask->getName();
		os << std::endl;
	}
	else
	{
		os << "END OF LINE";
		os << std::endl;
	}




}
Task& Task::operator+=(CustomerOrder&& CustOrder)
{
	m_orders.push_front(std::move(CustOrder));
	return *this;
}
