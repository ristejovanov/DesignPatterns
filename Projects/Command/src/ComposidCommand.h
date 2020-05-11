#pragma once

#include <iostream>
#include <ostream>
#include <vector>
#include <initializer_list>


class BankAcount
{
public:
	BankAcount() {};
	~BankAcount() {};

	void deposit(int amount)
	{
		m_balance += amount;
		std::cout << "deposited " << amount
			<< " balance now is " << m_balance << std::endl;
	}

	bool withDrow(int amount)
	{
		if (m_balance - amount >= m_overDraftLimit)
		{
			m_balance -= amount;
			std::cout << "withdrow " << amount
				<< " balance now is " << m_balance << std::endl;
			return true;
		}
		return false;
	}

	friend std::ostream& operator<<(std::ostream& os, BankAcount& obj)
	{
		return os << "Current account balance is " << obj.m_balance << std::endl;
	}


private:

	int m_balance{ 0 };
	int m_overDraftLimit{ -500 };
};


struct Command
{
	bool				m_succeeded;
	virtual void call() = 0;
	virtual void undo() = 0;
};


class BankAccountCommand : Command
{
public:
	enum Action
	{
		deposite,
		withdrow
	};

	BankAccountCommand(BankAcount& account, BankAccountCommand::Action action, int amount)
		:m_bankAcount(account)
		, m_action(action)
		, m_amount(amount)
	{
		m_succeeded = false;
	}

	void call()override
	{
		switch (m_action)
		{
		case BankAccountCommand::deposite:
			m_bankAcount.deposit(m_amount);
			m_succeeded = true;
			break;
		case BankAccountCommand::withdrow:
			m_succeeded = m_bankAcount.withDrow(m_amount);
			break;
		}
	}

	void undo() override
	{
		if (!m_succeeded)
			return;

		switch (m_action)
		{
		case BankAccountCommand::deposite:
			m_bankAcount.withDrow(m_amount);
			break;
		case BankAccountCommand::withdrow:
			m_bankAcount.deposit(m_amount);
			break;
		}
	}

	bool getSucceeded() { return m_succeeded; }
	void setSucceeded(bool succeded) { m_succeeded = succeded; }

private:
	BankAcount& m_bankAcount;
	Action			m_action;
	int					m_amount;
};


class CompositeBankAcountCommand
	: public std::vector<BankAccountCommand>
	, public Command
{
	public:
		CompositeBankAcountCommand(const std::initializer_list<BankAccountCommand> &list)
			:std::vector<BankAccountCommand>(list)
		{

		}

		void call() override
		{
			for (auto &it : *this)
			{
				it.call();
			}
		}

		void undo() override
		{
			for (auto  it = rbegin() ; it!=rend() ; it++)
			{
				it->undo();
			}
		}

	private:
};

class DependentBankAcountCommands :public CompositeBankAcountCommand
{
	public:
		DependentBankAcountCommands(const std::initializer_list<BankAccountCommand> &list)
			:CompositeBankAcountCommand(list)
		{

		}

		void call() override
		{
			bool ok = true;
			for (auto& it : *this)
			{
				if (ok)
				{
					it.call();
					ok = it.getSucceeded();
				}
				else
				{
					it.setSucceeded(false);
				}
			}

		}
};



class MoneyTransferCommand
	:public CompositeBankAcountCommand
{
public:
	MoneyTransferCommand(BankAcount& from, BankAcount& to, int amount)
		:CompositeBankAcountCommand({

				BankAccountCommand{from,BankAccountCommand::Action::withdrow,amount},
				BankAccountCommand{to, BankAccountCommand::Action::deposite,amount}
			})
	{

	};
	~MoneyTransferCommand() {};
};





void testFun()
{
	BankAcount ba1, ba2;
	ba1.deposit(500);

	std::cout << ba1 << ba2 << std::endl;


	MoneyTransferCommand transfer(ba1, ba2, 100);
	transfer.call();

	std::cout << ba1 << ba2 << std::endl;

	transfer.undo();

	std::cout << ba1 << ba2 << std::endl;

}