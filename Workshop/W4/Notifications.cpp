//Name: Suganya Maheswaran
////Student number: 048298137
////email:Smaheswaran4@myseneca.ca
////date: October 12 2018

#include <iostream>
#include "Notifications.h"
#include "Message.h"
using namespace std; 

namespace w4 {

	Notifications::Notifications() {
		m_msg = new Message[10];
		
		m_Count = 0;
	}
			
	
	Notifications::Notifications(const Notifications& other)
	{
		if (other.m_Count != 0)
			*this = other;
	}

	Notifications& Notifications::operator = (const Notifications& other)
	{
		if (this != &other)
		{
			
			if (other.m_Count != 0)
			{
				m_msg = new Message[10];
				m_Count = other.m_Count;
				for (int i = 0; i < other.m_Count; i++)
				{
					m_msg[i] = other.m_msg[i];
				}
			}
			else
			{
				m_msg = nullptr;
				*this = Notifications();
			}

			
		}
		return *this;
	}
	Notifications::Notifications(Notifications&& other)
	{
		*this = other;
		other.m_msg = nullptr;
		other.m_Count = 0;

	}

	Notifications& Notifications::operator = (Notifications&& other)
	{
		m_Count = other.m_Count;
		m_msg = other.m_msg;

		return *this;
	}
	Notifications::~Notifications()
	{
		delete[] m_msg;
	}

	void Notifications::operator+=( const Message& msg_)
	{
		if (m_Count < 10) {
			m_msg[m_Count] =msg_;
			++m_Count;
		}
	
	}

	void Notifications::display(std::ostream& os) const
	{
		for (int i = 0; i < m_Count; ++i) {
			m_msg[i].display(os);
			
		}
	}
}

