//Name: Suganya Maheswaran
////Student number: 048298137
////email:Smaheswaran4@myseneca.ca
////date: October 12 2018
#include<iostream>
#include<string.h>
#include<fstream>
#include<cstring>
#include"Message.h"
using namespace std;
namespace w4 {

	Message::Message() {};

	Message::Message(std::ifstream& in, char c)
	{
	
		std::string line;
		getline(in, line, c);
		getUserName(line);
		getRespondant(line);
		getMSG(line);

	}

	
	bool Message::empty() const {
		if (m_UserName == " ")
			return true;
		else if (m_RespondantName == "" && m_MSG == " ")
			return true;
		else if (m_MSG == " ")
			return true;
		else
			return false;
	}

	//function to get the username 
	void Message::getUserName(const std::string str)
	{
		size_t size = str.find(" ");
		if (str != " ")
		{
			m_UserName = str.substr(0, size);
//			cout << "User Name: " << m_UserName << endl;
		}
	}

	//function to get Respondant Name 
	void Message::getRespondant(const std::string str)
	{
		size_t spaceCount = 0;
		size_t index = 0;
	
		if (findAt(str, '@'))
		{
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (str[i] == ' ')
			{
				++spaceCount;
				if (spaceCount == 2)
				{
					index = i; //index is used to substr at index
					break;
				}
			}

		}
		//function to find the index of the second space
		
		
			m_RespondantName = str.substr(0, index); //to get index to be one character after the @ sign
			m_RespondantName = m_RespondantName.substr(m_RespondantName.find(' ')+2);
			//cout << "Respondant Name: " << m_RespondantName << endl;
		}
	}
	
	//function to get Message; 
	void Message::getMSG(const std::string str)
	{
		size_t spaceCount = 0;
		size_t index = 0;

		if (findAt(str, '@'))
		{
			for (size_t i = 0; i < str.size(); ++i)
			{
				if (str[i] == ' ')
				{
					++spaceCount;
					if (spaceCount == 2)
					{
						index = i;
						break;
					}
				}

			}

			m_MSG = str.substr(index+1);
		//	cout << "Message: " << m_MSG << endl;
		}
		else
		{
			for (size_t i = 0; i < str.size(); ++i)
			{
				if (str[i] == ' ')
				{
					++spaceCount;
					if (spaceCount == 1)
					{
						index = i+1;
						break;
					}
				}

			}
			if (str.compare(m_UserName) == 0)
			{
				m_UserName = "";
				m_MSG = "";
				m_RespondantName = "";
			}
			else
			m_MSG = str.substr(index);
		//	cout << "Message: " << m_MSG << endl;
		}

	}

	void Message::display(std::ostream& os) const {

	
		if (m_UserName != "")
		{
			cout << "Message" << endl;
			if (m_UserName != "")
			{
				os << " User  : " << this->m_UserName << endl;
				if (m_RespondantName != "")
				{
					os << " Reply : " << this->m_RespondantName << endl;
					os << " Tweet : " << this->m_MSG << endl;
				}
				else if (m_MSG != "")
					os << " Tweet : " << this->m_MSG << endl;
			}
			cout << endl;
		}
	}

	bool Message::findAt(std::string str, char c)

	{
		int  size = 0;
		size = str.find(c);
		if (size == -1)
		{
			return false;
		}
		else
			return true;

	}
}
