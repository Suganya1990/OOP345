//Name: Suganya Maheswaran
////Student number: 048298137
////email:Smaheswaran4@myseneca.ca
////date: October 12 2018
#ifndef W4_Message_H_
#define W4_Message_H
#include<iostream>
#include<fstream>
#include<string>
namespace w4 {

	class Message {
	private:
		std::string m_UserName;
		std::string m_RespondantName;
		std::string m_MSG;

	public:

		Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
		bool findAt(std::string str, char c);
		void getUserName(const std::string);
		void getRespondant(const std::string);
		void getMSG(const std::string);
	};



}

#endif // !W4_Message_H_
