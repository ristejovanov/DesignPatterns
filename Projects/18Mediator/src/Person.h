#pragma once
#include <string>

class ChatRoom;


class Person
{
	public:
		Person(std::string name,ChatRoom &room);
		~Person();

		void say(const std::string say);
		void pm(const std::string who, const std::string pm);
		void recive(std::string froWho, std::string message);

		std::string getName() const;

	private:
		std::string _name;
		ChatRoom&		_room;
};

