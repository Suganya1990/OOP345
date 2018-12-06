#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"Item.h"
#include"Utilities.h"

size_t Item::m_widthField; 

Item::Item(const std::string record)
{
	
	size_t pos = 0;
	bool flag = false; 
	Utilities d;
	
	m_name = d.extractToken(record, pos, flag);
	
	m_serialNumber = stoi(d.extractToken(record, pos, flag));
	m_quantity = stoi(d.extractToken(record, pos, flag));
	m_description = d.extractToken(record, pos, flag);

	if (d.getFieldWidth() > this->m_widthField)
	{
		this->m_widthField = d.getFieldWidth();
	}

}
const std::string& Item::getName() const
{
	return m_name;
}
const unsigned int  Item::getSerialNumber()
{
	return m_serialNumber++;
}
void Item::updateQuantity()
{
	m_quantity -= 1;
}
const unsigned int Item::getQuantity()
{
	return m_quantity;
}
void Item::display(std::ostream& os, bool full) const
{
	if (full)
	{
		os << std::fixed << std::setw(m_widthField) << std::left << m_name << " ["
			<< std::setw(6) << std::setfill('0') << std::right << m_serialNumber << std::setfill(' ') << "] "
			<< "Quantity: " << std::setw(m_widthField) << std::left
			<< m_quantity << std::right << " Description: " << m_description<<
			std::endl << std::setfill(' ');
	}
	else {
		os << std::fixed << std::setw(m_widthField) << std::left << m_name << " ["
			<< std::setw(6) << std::setfill('0') << std::right << m_serialNumber << std::setfill(' ') << ']'
			<< std::endl;

	}
}
