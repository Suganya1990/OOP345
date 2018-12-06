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

template<typename T, size_t N >
class List {
private:

	T arr[N];
	size_t count; 

public:

	List()
	{
		count = 0;
	}


	size_t size() const
	{
		return count;
	}
	const T& operator[](int index) const
	{
		return arr[index];
	}
	void operator+=(const T& ent)
	{
		if (count < N)
		{
			arr[count] = ent;


		}
		
			count++;
	}


};

