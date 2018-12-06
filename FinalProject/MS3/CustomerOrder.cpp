/*
Name: Suganya Maheswarn
Student number: 048-298-137
email: smaheswaran4@myseneca.ca
date: Nov 16 2018

*/


#include<iostream>
#include<string>
#include<iomanip>
#include"CustomerOrder.h"
#include"Utilities.h"
#include "Item.h"

using namespace std;
size_t CustomerOrder::m_widthField = 0;
CustomerOrder::CustomerOrder()
{
	m_name = "";
	m_product = "";
	m_cntItem = 0; 
	m_lstItem = nullptr ; 
	
}
CustomerOrder::CustomerOrder(std::string& record)
{

	
	size_t pos = 0; 
	bool flag = true; 
	m_cntItem = 0; 
	


	Utilities d;
	m_name = d.extractToken(record, pos, flag);
	m_product = d.extractToken(record, pos, flag);
	size_t temppos = pos;
	do {
		
		std::string temp = d.extractToken(record, pos, flag);
		m_cntItem++;  
	
	} while (pos != 0);
	pos = temppos;
	m_lstItem = new ItemInfo*[m_cntItem];

	for (size_t i = 0; i < m_cntItem; ++i) {
			std::string temp = d.extractToken(record, pos, flag);
		m_lstItem[i] = new ItemInfo(temp);
	}


	if (d.getFieldWidth() > this->m_widthField)
	{
		this->m_widthField = d.getFieldWidth();
	}
}
CustomerOrder::CustomerOrder(CustomerOrder& other)
{
	std::string error = " Copy Constructor";
		throw error;
}

CustomerOrder::CustomerOrder(CustomerOrder&& rhs) noexcept
{
	this->m_cntItem = 0;
	this->m_lstItem = nullptr;
	*this = std::move(rhs);
}

CustomerOrder& CustomerOrder::operator = (CustomerOrder&&rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < m_cntItem; ++i) { // must delete each row first
			delete m_lstItem[i];
		}
		delete[] m_lstItem;

		m_lstItem = rhs.m_lstItem;
		m_cntItem = rhs.m_cntItem;
		m_product = rhs.m_product;
		m_name = rhs.m_name;

		rhs.m_lstItem = nullptr;// = CustomerOrder();
		rhs.m_cntItem = 0;
	}
	return *this;
}

CustomerOrder::~CustomerOrder()
{

	for (size_t i = 0; i < m_cntItem; ++i)
	{
		delete m_lstItem[i];
	}

	delete[] m_lstItem;

}


bool CustomerOrder::getOrderFillState() const
{ 
	for (size_t i = 0; i < m_cntItem; ++i)
	{
		if (m_lstItem[i]->m_fillState == false)
			return false;
	}
	return true;
}

bool CustomerOrder::getItemFillState(std::string name) const

{
	for (size_t i = 0; i < m_cntItem; ++i)
	{
		if (m_lstItem[i]->m_itemName == name)
		{
			return m_lstItem[i]->m_fillState;
		}

	}
	return true;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os)

{
	for (size_t i = 0; i < m_cntItem; ++i)
	{
		
		if (m_lstItem[i]->m_itemName == item.getName())
		{
			if (item.getQuantity() != 0)
			{
				item.updateQuantity();
				 
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				m_lstItem[i]->m_fillState = true;
				os << "Filled " << this->m_name << ", " << this->m_product << "[" << this->m_lstItem[i]->m_itemName << "]" << std::endl;
			}
			else {
				os << "Unable to fill " << this->m_name << ",  " <<
					this->m_product << "[" << this->m_lstItem[i]->m_itemName << "]" << std::endl;

			}
		}
	}

}


void CustomerOrder::display(std::ostream & os) const
{
	
	os << this->m_name << " - ";
	os << this->m_product << std::endl;
	
	for (size_t i = 0; i < this->m_cntItem; i++)
		
	{
		os << "[" << std::setw(6) << std::setfill('0') <<std::right<< m_lstItem[i]->m_serialNumber << "] ";  std::cout << std::left;
		os<<setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - " << (m_lstItem[i]->m_fillState ? "FILLED\n" : "MISSING\n");
	}


}
