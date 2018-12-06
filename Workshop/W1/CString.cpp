// Name: Suganya Maheswaran 
// Seneca Student ID: 048-298-137
// Seneca email: smaheswaran4@myseneca.ca	
// Date of completion: Sept 09 2018
//


#include <iostream>
#include <cstring>
#include "CString.h"

using namespace std;

//static value 
int stored = 3; 

namespace w1 {


	CString::CString(char* string):max(stored)
	{
		if (string == nullptr || string[0] == '\0')
		{
			m_string = new char[1];
			m_string[0] = '\0';
		}
		else {
			int size = strlen(string);
			if (size > max)
			{
				m_string = new char[max+1];
				strncpy(m_string, string, max);
				m_string[max] = '\0';
			}
			else
			{
				m_string = new char[size + 1];
				strncpy(m_string, string, size);
				m_string[size] = '\0';
			}
		}
	}

	CString::~CString()
	{
		delete[] m_string;
	}

	void CString::display(ostream& os) const
	{
		os << m_string;
	}

	ostream& operator<<(std::ostream& os, const CString& s)
	{
		s.display(os);
		return os;
	}

}