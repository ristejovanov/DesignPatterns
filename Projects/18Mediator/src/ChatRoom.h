#pragma once
#include <string>
#include <vector>
#include "Person.h"

class ChatRoom
{
	public:
		ChatRoom();
		~ChatRoom();

		void join(Person* person);
		void brotcast(const std::string& fromWho, const std::string& msg);
		void pm(const std::string& fromWho, const std::string& toWho,const std::string& msg);
		
	private:
		std::vector<Person*> _people;
};

