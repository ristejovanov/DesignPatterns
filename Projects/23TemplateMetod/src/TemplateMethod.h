#pragma once
#include <iostream>


class Game
{
	public:
		Game(int numberOfPlayers)
		:m_numberOfPlayers(numberOfPlayers)
		{}

		void run()
		{
			start();
			while (!have_winer())
			{
				teke_turn();
			}
			std::cout << "The winer is " << get_winer() << std::endl;
		}

		virtual void start() = 0;
		virtual bool have_winer() = 0;
		virtual void teke_turn() = 0;
		virtual void end() = 0;
		virtual int	 get_winer() = 0;

	protected:
		int m_numberOfPlayers;
		int m_currentPlayer{0};
		bool m_haveWiner{false};
};


class Chess
	:public Game
{
	public:

		Chess()
			:Game(2)
		{}

		virtual ~Chess() {}
	
		void start()
		{
		}

		bool have_winer() 
		{
		}

		void teke_turn()
		{
			std::cout << "Turn " << m_turn << " taken by player" << m_currentPlayer << "\n";
			++m_turn;
			m_currentPlayer = (m_currentPlayer + 1) % m_numberOfPlayers;
		}

		void end()
		{

		}

		int	 get_winer()
		{
			return m_currentPlayer;
		}

	private:
		int m_turn{ 0 };
		int m_max_turns{ 10 };

};