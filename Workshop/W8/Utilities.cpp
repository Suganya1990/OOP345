
/*

Name: Suganya Maheswaran
Student ID: 048298137
email: smaheswaran4@myseneca.ca	
Date: Nov 15 2018


*/


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); ++i)
		{
			for (size_t j = 0; j < price.size(); ++j)
				if (desc[i].code == price[j].code)
				{
					Product * temp = new Product(desc[i].desc, price[j].price);
					temp->validate();
					priceList += temp;
					
					delete temp;
				}
			
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); ++i)

		{
			for (size_t j = 0; j < price.size(); ++j)
			{
				if (desc[i].code == price[j].code)
				{
					std::unique_ptr<Product> P = std::unique_ptr<Product>(new Product(desc[i].desc, price[j].price));
					P->validate();
					priceList += std::move(P);
				}
			}
		}

		return priceList;
	}
}