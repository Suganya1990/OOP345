/*
Name: Suganya Maheswarn
Student number: 048-298-137
email: smaheswaran4@myseneca.ca
date: Nov 16 2018

*/


#ifndef UTILITIES_H_
#define UTILITIES_H_
#include<iostream>

class Utilities {
private:
	size_t m_widthField = 1;
	static  char m_delimiter;
public:

	void setFieldWidth(size_t);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char d);
	const char getDelimiter() const;
};


#endif // !1
