//Name: Suganya
//Student number: 048298137
//email: smaheswaran4@myseneca.ca
//date: October 12 2018

#ifndef SICT_GRADES_H
#define SICT_GRADES_H
#include<iostream>
#include<iomanip>
#include<string>
namespace sict
{
	class Grades{
		std::string* m_record = nullptr; 
		double* m_grade = nullptr; 
		size_t count; 

	public:
		Grades(const char* fileName);
		~Grades();
		
		Grades(const Grades&) = delete; //constructors dont return values 
		Grades& operator = (const Grades&) = delete; 

		Grades( Grades&&) = delete; //
		Grades& operator = (const Grades&&) = delete; 
		template <typename Func >
		void displayGrades(std::ostream& os, Func F) const
		{
		
			for (size_t i = 0; i < count; ++i)
			{
			
				char* str = F(m_grade[i]);
				os << std::fixed;
				os << std::right << std::setw(10) << m_record[i];
				os << " " << std::setprecision(2) << m_grade[i] << " ";
			
				os << std::left << std::setfill(' ') << std::setw(4) << str << std::endl;
				
				delete str;
			}
			
			
		};
	}; 



}
#endif // !1
