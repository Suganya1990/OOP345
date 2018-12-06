//Suganya Maheswaran
//048-298-137
//smaheswaran4@myseneca.ca
//Nov 2 2018
#include <iostream>
#include <string>
#include "ProdUtil.h"
#include "Product.h"
#include "TaxableProduct.h"

namespace w6
{
std::ostream &operator<<(std::ostream &os, const iProduct &other)
{
	other.display(os);
	return os;
}

iProduct *readProduct(std::ifstream &in)
{

	size_t len = 0;
	std::string temp, tempString, tempNum;
	double tempCost;
	char status[1];
	iProduct *iProductTemp = nullptr;
	//reads line and breaks it down into price, cost, and tax status
	if (!in.eof())
	{
		std::getline(in, temp);
		if (temp != "")
		{
			len = temp.length();
			tempNum = temp.substr(0, 5);
			tempCost = stod(temp.substr(5, 6));

			//creates a Taxable Product or Product

			if (len == 13)
			{
				status[0] = temp[12];
			}
			else
				status[0] = ' ';

			if (status[0] == ' ')
			{
				iProductTemp = new Product(tempNum, tempCost);
			}
			else if (status[0] == 'H' || status[0] == 'P')
			{
				iProductTemp = new TaxableProduct(tempNum, tempCost, status[0]);
			}
			else
			{
				throw "Unrecognizable Tax Code!";
			}
		}
		else
		{
			throw "no such record! Reached the end of the file!";
		}
		return iProductTemp;
	}

	return iProductTemp;
}

} // namespace w6