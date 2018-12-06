// Name: Suganya Maheswaran 
// Seneca Student ID: 048-298-137
// Seneca email: smaheswaran4@myseneca.ca	
// Date of completion: Sept 09 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W1_CSTRING_H_
#define W1_CSTRING_H_
#include <iostream> 
#include <cstring>


namespace w1 {

	class CString
	{
	private:
		const int max;
		char* m_string;


	public:
		CString(char* string);
		~CString(); 
		void display(std::ostream& os) const; 

	 };


	std::ostream& operator<<(std::ostream& os, const CString& s);
}


#endif // CString_H_