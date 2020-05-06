// Flyweight design pattern
// design paternd for space optimization

//avoid redundancy when storing data
//example when you have database of names and sur names in a game avoid duplicats 
//store list od names and pointers to them


//defenition about this design pattern
// Flyweight - A space optimization technique that lets us use less memory by -
// storing externally the data associated with similar objects


// here we are going to build multi - user masive game


// the example need to be with strings but acording to my perspectiv
// there is no point for storing such data if for every claas you have 2 more Kay
// variables for making this concept to work anly point is if you have biger objects


//--------------STL Includes---------------
#include <iostream>
#include <cstdint>
#include <ostream>

//-------------Bosst Includes--------------
#include "boost/bimap.hpp"


#include "boostFlyweight.h"

typedef uint32_t Kay;

template<typename T>
class User
{
	public:
		User(T firstName, T lastName)
			:_firstName(addName(firstName))
			,_lastName(addName(lastName))
		{

		}

		T getFirstName()
		{
			return _names.left.find(_firstName)->second;
		}

		T getLastName()
		{
			return _names.left.find(_lastName)->second;
		}

		template<typename T>
		friend std::ostream& operator<<(std::ostream& os, User<T>& obj)
		{
			os << "My first name is " << obj._firstName 
				<< " and my last name is " << obj._lastName 
				<< std::endl;

			return os;
		}



	private:
		Kay addName(T obj)
		{
			auto item = _names.right.find(obj);
			if (item != _names.right.end())
			{
				Kay id = ++_seed;
				_names.insert({ id, obj });
				return id;
			}
			return item->second;
		}

		Kay _firstName;
		Kay	_lastName;
		static boost::bimap<Kay, T> _names;
		static Kay _seed;
};

template<typename T>
Kay User<T>::_seed = 0;

template<typename T>
boost::bimap<Kay, T> User<T>::_names{};


int main()
{
	//user 1 tests -----------------------------

	User<std::string> user1("Riste", "Jovanov");	
	User<std::string> user2("Mile", "Jovanov");
	User<std::string> user3("Ace", "Jovanov");

	//

	//user2 tests ---------------------------
	User2 first{ "Riste","Jovanov" };
	User2 second{ "Mile","Jovanov" };

	std::cout << std::boolalpha;

	std::cout << (&first._firstName.get()== &second._firstName.get()) << std::endl;
	std::cout << (&first._lastName.get() == &second._lastName.get()) << std::endl;

	return 0;
}