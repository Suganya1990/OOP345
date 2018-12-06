//Name: Suganya
////Student number: 048298137
////email: smaheswaran4@myseneca.ca
//Date: October 12 2018
#ifndef _SICT_LETTER_H
#define _SCIT_LETTER_H
#include<iostream>
#include<string.h>
namespace sict {
	
	enum class Letter { A_PLUS, A, B_PLUS, B, C_PLUS, C, D_PLUS, D, F };

	template<typename E>
	char* flip(const E& letter)
	{ 
		char  *str = nullptr;
		str = new char[3];

		switch (letter)
		{
		case Letter::A_PLUS:
			strcpy(str, "A+");
			str[2] = '\0';
			break;
		case Letter::A:
			strcpy(str, "A");
			str[2] = '\0';
			break;
		case Letter::B_PLUS:
			strcpy(str, "B+");
			str[2] = '\0';
			break;
		case Letter::B:
			strcpy(str, "B");
			str[2] = '\0';
			break;
		case Letter::C_PLUS:
			strcpy(str, "C+");
			str[2] = '\0';
			break;
		case Letter::C:
			strcpy(str, "C");
			str[2] = '\0';
			break;
		case Letter::D_PLUS:
			strcpy(str, "D+");
			str[2] = '\0';
			break;
		case Letter::D:
			strcpy(str, "D");
			str[2] = '\0';
			break;
		case Letter::F:
			strcpy(str, "F");
			str[2] = '\0';
			break;
		}
	//	char* str_ = str;
//		std::cout << str_ <<std::endl;
		return str;
	
	};

}


#endif // !_SICT_LETTER_H

/*

Design and code a scoped set of enumeration constants named Letter that identify the letter values for the grades in a course.

Include in your design, a template function that converts each enumeration constant into a C-style null-terminated string. 
The function receives an unmodifiable reference to one of the enumeration constants and returns the address of string that represents 
that constant.




*/
