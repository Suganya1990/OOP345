#pragma once
#ifndef _W2_TEXT
#define _W2_TEXT

#include <iostream>
#include <string>
#include <memory>

namespace w2

{
	class Text
	{


	
		std::string* PtrString;
		size_t count;


	public:

		Text();
		Text(const std::string);
		Text(Text & temp);
		Text(Text&&);
		Text& operator =(const Text&);
		Text& operator=(Text&&);

		size_t size() const;
		~Text();



	};




}




#endif // 
