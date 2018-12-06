// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <string>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}
	try {
		Grades grades(argv[1]);
		auto letter = ([](double g) {

			Letter str;
			if (g >= 90)
				str = Letter::A_PLUS;
			else if (g >= 80 && g < 90)
				str = Letter::A;
			else if (g >= 75 && g < 80)
				str = Letter::B_PLUS;
			else if (g >= 70 && g < 75)
				str = Letter::B;
			else if (g >= 65 && g < 70)
				str = Letter::C_PLUS;
			else if (g >= 60 && g < 65)
				str = Letter::C;
			else if (g >= 55 && g < 60)
				str = Letter::D_PLUS;
			else if (g >= 50 && g < 55)
				str = Letter::D;
			else if (g < 49)
				str = Letter::F;
			return flip(str);

		});
		grades.displayGrades(std::cout, letter);

	}
	catch(std::string errStrs)
	{
		std::cout << " There was an error : " << errStrs << std::endl;

		'A'
	}


	return 0;
}