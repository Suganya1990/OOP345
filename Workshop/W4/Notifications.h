//Name: Suganya Maheswaran
////Student number: 048298137
////email:Smaheswaran4@myseneca.ca
////date: October 12 2018
#ifndef _W4_Notifications_H
#define _W4_Notifications_H
#include<iostream>

namespace w4 {

	class Message;
	class Notifications
	{
	private:
		int m_Count;
		Message* m_msg;
	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator = (const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator = ( Notifications&&);
		~Notifications();
		void operator+=( const Message& msg);
		void display(std::ostream& os) const;

	};

}

#endif // !_W4_Notifications_H





