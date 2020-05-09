#pragma once
// ------- STL Includes--------- 
#include <string>
#include <ostream>
#include <iostream>
#include <boost/signals2.hpp>

using namespace boost::signals2;

struct Query
{
	std::string _creatureName;
	enum Argument {attack,defense} _argument;
	int _result;

	Query(std::string creatureName, Argument argument, int result)
		:_creatureName(creatureName)
		, _argument(argument)
		, _result(result)
	{

	}
};


class Game
{
	public:
		signal<void(Query&)> _queries;
};


class Creature
{
	public:
		Creature(Game& game, int attack, int defense, const std::string name)
			:_game(game)
			,_attack(attack)
			,_defense(defense)
			,_creatureName(name)
		{

		}

		std::string getCreatureName()
		{
			return _creatureName;
		}

		int get_attack() const
		{
			Query q{ _creatureName, Query::Argument::attack, _attack };
			_game._queries(q);
			return q._result;
		}

		friend std::ostream& operator<<(std::ostream& os, Creature& obj)
		{
			os << "attack: " << obj.get_attack() << " name: " << obj._creatureName;
			return os;
		}


	private:
		Game& _game;
		int _attack, _defense;
		std::string _creatureName;
};


class CreatureModifier
{
	public:
		CreatureModifier(Game& game, Creature& creature) 
			:_game(game)
			,_creature(creature)
		{}
		virtual ~CreatureModifier() = default;

	protected:
		Game& _game;
		Creature& _creature;
};

class DoubleAttackModifier :public CreatureModifier
{
	public:
		DoubleAttackModifier(Game& game, Creature& creature) 
			:CreatureModifier(game,creature)
		{
			_conn = game._queries.connect([&](Query& q)
			{
					if (q._creatureName == _creature.getCreatureName()
						&& q._argument == Query::Argument::attack)
					{
						q._result *= 2;
					}
			});
	
		}

		~DoubleAttackModifier() { _conn.disconnect(); }

	private:
		connection _conn;

};

void testBrokerChain()
{
	Game game;
	Creature goblin(game, 2, 2, "Strong goblin");
	std::cout << goblin << std::endl;
	{
		DoubleAttackModifier dam(game, goblin);
		std::cout << goblin << std::endl;
	}

	std::cout << goblin << std::endl;

}