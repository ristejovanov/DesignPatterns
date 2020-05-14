#pragma once
#include <iostream>
#include <ostream>

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
	virtual void call() = 0;
	virtual void undo() = 0;
};


class BankAccountCommand :Command
{
	public:
		enum Action
		{
			deposite,
			withdrow
		};
	
		BankAccountCommand(BankAcount& account, BankAccountCommand::Action action, int amount)
			:m_bankAcount(account)
			,m_action(action)
			,m_amount(amount)
			,m_succeeded(true)
		{

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
				m_succeeded =  m_bankAcount.withDrow(m_amount);
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
private:
		BankAcount& m_bankAcount;
		Action			m_action;
		int					m_amount;
		bool				m_succeeded;
};



void testFunction()
{
	BankAcount myAccount;

	BankAccountCommand deposite200(myAccount, BankAccountCommand::Action::deposite, 200);
	BankAccountCommand deposite100(myAccount, BankAccountCommand::Action::deposite, 100);

	BankAccountCommand withdrow100(myAccount, BankAccountCommand::Action::withdrow, 100);
	BankAccountCommand withdrow200(myAccount, BankAccountCommand::Action::withdrow, 200);

	deposite100.call();
	deposite200.call();

	withdrow200.call();
	withdrow100.call();
}
