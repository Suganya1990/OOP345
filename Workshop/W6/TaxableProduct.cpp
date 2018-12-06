//Suganya Maheswaran
//048-298-137
//smaheswaran4@myseneca.ca
//Nov 2 2018

#include<iostream>
#include<string>
#include<iomanip>
#include"TaxableProduct.h"
#include"Product.h"

namespace w6 {
	const double TaxableProduct::m_taxRate[] = { 1.13, 1.08 };
	TaxableProduct::TaxableProduct(std::string num, double cost, char status):Product(num, cost)
	{ 
		if (status == 'H')
		{
			cost = cost * m_taxRate[0];

		}
		else 
		{
			cost = cost * m_taxRate[1];
		}
		m_Status = status; 

		
	}

	double TaxableProduct::getPrice() const
	{
		if (m_Status == 'H')
		{
			return Product::getPrice()* m_taxRate[0];
		}
		else 
		{
			return Product::getPrice()*  m_taxRate[1];
		}
	}
	void TaxableProduct::display(std::ostream& os) const
	{
		os << std::fixed << std::setw(16) << getPNum();
		if (m_Status == 'H')
			os<< std::setw(16) << getPrice()/1.13 <<" HST"<< std::endl;
		else if (m_Status == 'P')
			os << std::setw(16) << getPrice()/1.08 <<" PST"<< std::endl;

	}

}