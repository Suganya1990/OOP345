/**************************************
*Name: Suganya Maheswaran   		  *
*Student number: 048298137			  *
*Seneca Email:smaheswaran4@myseneca.ca*
*Date of Completion Sept 26 2018      *
*I confirm that the content of this   *
*file is created by me,with the       *
*exception of the parts provided to   *
*me by my professor.                  *
**************************************/
#include<iostream>

template<typename A, typename B>
class Pair
{
private:
	A m_str1; 
	B m_str2;
public:
	Pair()
	{
		m_str1 = A();
		m_str2 = B();
	
	}

	Pair(const A& str1, const B& str2)
	{
	
		m_str1 = str1;
		m_str2 = str2;
		
	}
	const A& getKey() const
	{
		
		return m_str1;
	}
	const B& getValue() const
	{
		
		return m_str2;
	}
};