#pragma once
#include <iostream>
#include <ostream>


class Momento
{
public:
	~Momento() {}

private:
	Momento(int deposit):m_deposit(deposit) {}

	int m_deposit;

	friend class BancAcount;
};

class BancAcount
{
	public:
		BancAcount(int deposit) 
			:m_deposit(deposit)
		{}
		~BancAcount() {}

		Momento deposit(int value)
		{
			m_deposit += value;
			return Momento(m_deposit);
		}

		void restorAccount(Momento & momento)
		{
			m_deposit = momento.m_deposit;
		}

		friend std::ostream& operator<<(std::ostream& os, BancAcount& obj)
		{
			return os << "Current deposit is " << obj.m_deposit << std::endl;
		}

	private:
		int m_deposit;
};


void testFunction()
{
	BancAcount risteJovanov(100);

	auto M1 = risteJovanov.deposit(20);
	auto M2 = risteJovanov.deposit(10);
	auto M3 = risteJovanov.deposit(1);

	std::cout << risteJovanov;

	risteJovanov.restorAccount(M1);
	std::cout << risteJovanov;

}
