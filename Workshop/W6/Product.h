//Suganya Maheswaran
//048-298-137
//smaheswaran4@myseneca.ca
//Nov 2 2018
#ifndef W6_PRODUCT_H_
#define W6_PRODUCT_H_
#include<iostream>
#include"iProduct.h"
namespace w6 {
	class Product : public iProduct
	{	
		
		std::string m_productNum;
		double m_cost;
	public:
		Product(std::string productNum, double cost);
		double getPrice() const;
		std::string getPNum() const;
		void display(std::ostream& os) const;
		

	};
}
#endif //PRODUCT_H_