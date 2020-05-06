#pragma once
//--------STL Includes---------
#include <string>

//---------Boost Includes -------------
#include <boost/flyweight.hpp>
#include<boost/flyweight/key_value.hpp>


class	User2
{
public:
	User2(std::string first, std::string second)
		:_firstName(first)
		,_lastName(second)
	{

	}

	boost::flyweight<std::string> _firstName;
	boost::flyweight<std::string> _lastName;
};