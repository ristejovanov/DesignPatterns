#pragma once

#include <string>
#include <ostream>
#include <iostream>


class Creature
{
	public:
		Creature(std::string name, int attack, int defence)
			:_name(name)
			,_attack(attack)
			,_defence(defence)
		{};
		~Creature() {};

		void setAttackValue(int attack) { _attack = attack; }
		void setDefenceValue(int defence) { _defence = _defence; }

		int getAtackValue() { return _attack; }
		int getDefenceValue() { return _defence; }

		friend std::ostream& operator<<(std::ostream& os, Creature& ob)
		{
			os << "Creature name is " << ob._name
				<< " attack value is " << ob._attack
				<< " defence value is " << ob._defence
				<< std::endl;
			return os;
		}

	private:
		std::string _name;
		int					_attack;
		int					_defence;
};


class CreatureModifire
{
	public:
		CreatureModifire(Creature& creature) :_creature(creature){};
		~CreatureModifire() {};

		void addModifire(CreatureModifire* modifire)
		{
			if (_next != nullptr)
				_next->addModifire(modifire);
			else
				_next = modifire;
		}

		virtual void handle()
		{
			if (_next)
				_next->handle();
		}

	protected:
		CreatureModifire* _next{nullptr};
		Creature&					_creature;
};

class DoubleAttackModifire : public CreatureModifire
{
	public:
		DoubleAttackModifire(Creature& creature)
			:CreatureModifire(creature)
		{

		}

		void handle() override
		{
			_creature.setAttackValue(_creature.getAtackValue() * 2);
			CreatureModifire::handle();
		}
};

class IncreaseDefenceModifire :public CreatureModifire
{
	public:
		IncreaseDefenceModifire(Creature& creature)
			:CreatureModifire(creature)
		{

		}
		
		void handle() override
		{
			if (_creature.getAtackValue() <= 2)
				_creature.setDefenceValue(_creature.getDefenceValue() + 1);
			CreatureModifire::handle();
		}
};


void TestFunctionForPointerChain()
{
	Creature creature("Riste", 10, 10);
	CreatureModifire root(creature);

	DoubleAttackModifire attack(creature);
	DoubleAttackModifire attack2(creature);
	IncreaseDefenceModifire defence(creature);

	root.addModifire(&attack);
	root.addModifire(&attack2);
	root.addModifire(&defence);

	root.handle();

	std::cout << creature;
}









