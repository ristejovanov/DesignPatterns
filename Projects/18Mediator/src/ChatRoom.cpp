#include "ChatRoom.h"
#include <algorithm>


ChatRoom::ChatRoom()
{
}

ChatRoom::~ChatRoom()
{
}

void ChatRoom::join(Person* person)
{
	brotcast("Room", person->getName() + "joined the chat room");
	_people.push_back(person);
}

void ChatRoom::brotcast(const std::string& fromWho, const std::string& msg)
{
	for(auto person : _people)
	{
		if (person->getName() != fromWho)
			person->recive(fromWho, msg);
	}
}

void ChatRoom::pm(const std::string& fromWho, const std::string& toWho, const std::string& msg)
{
	auto person = std::find_if(_people.begin(), _people.end(), [&](Person* person)
		{
			return person->getName() == toWho;
		});

	if (person != _people.end())
	{
		(*person)->recive(fromWho, msg);
	}
}
