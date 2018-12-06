/*
Name: Suganya Maheswarn
Student number: 048-298-137
email: smaheswaran4@myseneca.ca
date: Nov 16 2018

*/



#include<iostream>
#include<string>
#include"Utilities.h"
using namespace std;
char Utilities::m_delimiter = '\0';

void Utilities::setFieldWidth(size_t size = 1)
{

	m_widthField = size;

}
size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string extracted;
	std::string err = "Error";
	
	size_t index = 1;
	size_t n = next_pos;

	index = str.find(m_delimiter, next_pos);
	extracted = str.substr(next_pos, index - n);
	
	if (extracted == "")
	{
		throw err;
		more = false;
	}

	if (m_widthField < extracted.length() && next_pos == 0)
	{
		m_widthField = extracted.length();
	}
	next_pos = index + 1;
	more = true;
	
	return extracted;
}


const char Utilities::getDelimiter() const
{
	return m_delimiter;

}
void Utilities::setDelimiter(const char d)
{
	m_delimiter = d;
}


