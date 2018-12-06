//Name: Suganya
//Student number: 048298137
//email: smaheswaran4@myseneca.ca
//date: october 12 2018

#include<iostream>
#include<string>
#include<fstream>
#include"Grades.h"

using namespace std; 
namespace sict {

	Grades::Grades(const char* file)
	{
		try {
			count = 0;
			ifstream fs(file);
			if (fs.is_open())
			{
				std::string temp;
				while (getline(fs, temp)) { count++; }
				//std::cout << "totalLines: " << totalLines << std::endl;

				fs.clear();
				fs.seekg(0);

				m_record = new (std::nothrow) std::string[count];
				m_grade = new (std::nothrow) double[count];

				for (size_t i = 0; i < count; i++)
				{
					getline(fs, temp);
					//std::cout << everyRow;
					m_record[i] = temp.substr(0, temp.find(' '));
					m_grade[i] = std::stod(temp.substr(temp.find_last_of(' ') + 1));
				}

				fs.close();
			}

			else
			{
				throw string("File does not exist"); 
			}
		}
		catch (const char* msg)
		{
			std::cout << msg << std::endl;
		}
		
	}
	Grades::~Grades()
	{
		delete[] m_record;

		m_record = nullptr;
	}
 
}
