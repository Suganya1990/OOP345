#include <iostream>
#include<istream>
#include <string>
#include <fstream>
#include"Text.h"


namespace w2
{

	Text::Text()
	{

		PtrString = nullptr;
		count = 0;
	}


	Text::Text(const std::string fileName)
	{
		size_t lineCount = 0;
		bool isEmpty = fileName.empty();
		if (isEmpty)
		{
			Text();
		}
		else
		{
			std::ifstream fin; //creates object
			fin.open(fileName);
			std::string tempStr;
		while (!fin.eof());
			{
			getline(fin, tempStr);
				lineCount++;
			
			} 

			count = lineCount;
			fin.close();

		}

		PtrString = new std::string[count];
		std::ifstream fin; //creates object
		fin.open(fileName);
		std::string tempStr;
		for (size_t i = 0; i < count; i++)
		{
			getline(fin, tempStr);
			PtrString[i] = tempStr;
		}
	}


	Text::Text(Text & temp)
	{
		count = temp.count;
		
		if (temp.PtrString != nullptr)
		{
			PtrString = new std::string[count];
			for (size_t i = 0; i < count; i++)
			{
				PtrString[i] = temp.PtrString[i];

			}


		}
		else
		{
		this->PtrString=nullptr;
		}

	}



	Text::Text(Text&& fName)
	{
		*this = std::move(fName);
	}


	Text& Text::operator =(const Text& Lv)
	{
		if (this != &Lv)
		{
			count = Lv.count;

			delete[] PtrString;




			if (Lv.PtrString != nullptr)
			{
				for (size_t i = 0; i < count; i++)
				{
					PtrString[i] = Lv.PtrString[i];

				}
				
			}

			else
			{
				this->PtrString = nullptr;
			}

		}

	
		return *this;
	}


	 Text& Text::operator=(Text&& Rv)
	{
		 if (this != &Rv)
		 {
			 delete[] PtrString;
			 PtrString = Rv.PtrString;
			 count = Rv.count;
			 Rv.PtrString = nullptr;
			 Rv.count = 0;
		 }
		 return *this;

	}


	size_t Text:: size() const
	{
		return count;
	}

	Text::~Text()
	{
		delete[] PtrString;


	}

}