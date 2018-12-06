//Suganya Maheswaran
//048-298-137
//smaheswaran4@myseneca.ca
//Nov 2 2018

#include<iostream>
#include<iomanip>
#include<string>
#include"Product.h"
namespace w6 {

	Product::Product(std::string productNum, double cost)
	{
		m_productNum = productNum; 
		m_cost = cost; 
	}
	double Product::getPrice() const
	{
		return m_cost;
	}
	std::string Product::getPNum() const
	{
		return m_productNum;
	}

	void Product::display(std::ostream& os) const
	{
		
		os <<std::fixed<<std::setw(16)<< m_productNum << std::setw(16) << m_cost << std::endl;
	}
	

}