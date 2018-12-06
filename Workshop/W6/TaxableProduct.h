//Suganya Maheswaran
//048-298-137
//smaheswaran4@myseneca.ca
//Nov 2 2018

#ifndef  W6_TAXABLEPRODUCT_H_
#define W6_TAXABLEPRODUCT_H_
#include<iostream>
#include<string>
#include"Product.h"
namespace w6 {
	class TaxableProduct : public w6::Product
	{
	private:
		char m_Status; 
		const static double m_taxRate[2];
		
	public:
		TaxableProduct(std::string num, double cost, char status);
		double getPrice() const;
		void display(std::ostream& os) const;

		
	};

}

#endif // ! TAXABLEPRODUCT_H_
