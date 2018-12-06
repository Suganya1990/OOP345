// Name: Suganya Maheswaran 
// Seneca Student ID: 048-298-137
// Seneca email: smaheswaran4@myseneca.ca	
// Date of completion: Sept 09 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include<iostream>
#include"process.h"

using namespace std;
	void process(char* string, ostream& os)
	{
		w1::CString a(string);
		static int count = 0; 
		os << count << ": ";
		a.display(os);
		os << endl;
		count++;
	
	}
