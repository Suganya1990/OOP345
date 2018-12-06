/*
Name: Suganya Maheswarn
Student number: 048-298-137
email: smaheswaran4@myseneca.ca
date: Nov 16 2018

*/

#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
#include<string>
class Item {
private:
	std::string m_name; 
	std::string m_description; 
	size_t m_serialNumber; 
	size_t m_quantity;
	static size_t m_widthField;

public:
	Item(const std::string record);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	void updateQuantity();
	const unsigned int getQuantity();
	void display(std::ostream& os, bool full) const;



};


#endif // !ITEM_H_
