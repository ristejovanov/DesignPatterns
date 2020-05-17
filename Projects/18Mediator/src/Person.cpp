#include "Person.h"
#include "ChatRoom.h"
#include <iostream>



Person::Person(std::string name, ChatRoom& room)
	:_name(name)
	,_room(room)
{
}

Person::~Person()
{
}

void Person::say(const std::string say)
{
	_room.brotcast(_name, say);
}

void Person::pm(const std::string who, const std::string pm)
{
	_room.pm(_name, who, pm);
}

void Person::recive(std::string froWho, std::string message)
{
	std::cout << "Get message from " << froWho << " : " << message << std::endl;
}

std::string Person::getName() const
{
	return _name;
}
