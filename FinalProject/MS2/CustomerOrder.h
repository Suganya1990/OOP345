/*
Name: Suganya Maheswarn
Student number: 048-298-137
email: smaheswaran4@myseneca.ca
date: Nov 16 2018

*/



#ifndef CUSTOMERORDER_H_
#define CUSTOMERORDER_H_
#include<iostream>
#include"Item.h"

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder
{
private:
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField; 

public:
	CustomerOrder();                                  
	CustomerOrder(std::string& record);
	CustomerOrder(CustomerOrder& other);
	CustomerOrder& operator=(CustomerOrder& other) = delete;
	CustomerOrder (CustomerOrder&& rhs);
	CustomerOrder& operator=(CustomerOrder&&);
	~CustomerOrder();
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream&) const;




};


#endif