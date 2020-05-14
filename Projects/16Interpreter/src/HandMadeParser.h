#pragma once
// we need to make parser for parsing (12+5)-(12+4)
#include <string>
#include <ostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <iostream>
#include <memory>

class Token
{
public:
	enum Type{ integer, plus, minus, lparen, rparen};

	Token(Type type, std::string text)
	: m_type(type)
	, m_text(text)
	{}
	~Token() {}

	friend std::ostream& operator<<(std::ostream& os,const Token& obj)
	{
		return os << " " << obj.m_text << " " << std::endl;
	}


	Type				m_type;
	std::string m_text;
};

std::vector<Token> lex(std::string text)
{
	std::vector<Token> output;

	for (int i  = 0;i<text.size();i++)
	{
		switch (text[i])
		{
		case '+':
			output.push_back({ Token::Type::plus, "+" });
			break;
		case '-':
			output.push_back({ Token::Type::minus, "-" });
			break;
		case'(':
			output.push_back({ Token::Type::lparen,"(" });
			break;
		case')':
			output.push_back({ Token::Type::rparen,")" });
			break;
		default:
			std::ostringstream os;
			os << text[i];
			auto j = i+1;
			for (; j < text.size(); j++)
			{
				if (std::isdigit(text[j]))
				{
					os << text[j];
					++i;
				}
				else
				{
					output.push_back({Token::Type::integer, os.str()});
				}
			}
			break;
		}
	}

	return output;
}


struct Element
{
	virtual int eval() const = 0;
};


class Integer :Element
{
	public:
		Integer(int value)
			:m_value(value)
		{};
		~Integer() {};

		int eval() const override
		{
			return m_value;
		}


	private:
		int m_value;
};



class BinaryOperation :Element
{
	public:
		std::shared_ptr<Element> m_left, m_right;
		enum Type { Adition, Subtraction } m_operation;

		BinaryOperation(std::shared_ptr<Element>left, std::shared_ptr<Element>right, Type operation)
			: m_left(left)
			, m_right(right)
			, m_operation(operation)
		{};
		~BinaryOperation() {};

	int eval() const override
	{
		int left =m_left->eval();
		int right = m_right->eval();
		if (m_operation == Type::Adition)
			return left + right;
		else
			return left - right;
	}
};


std::shared_ptr<Element> parse(std::vector<Token>& tokens)
{
	auto rezult = std::make_unique<BinaryOperation>();
	bool have_left{ false };

	for (int i = 0; i < tokens.size(); i++)
	{
		switch (tokens[i].m_type)
		{
		case Token::Type::integer:
		{
			int num = std::stoi(tokens[i].m_text);
			auto value = std::make_shared<Integer>(num);
			if (!have_left)
			{
				rezult->m_left = value;
				have_left = true;
			}
			else
			{
				rezult->m_right = value;
			}
		}break;
		case Token::Type::plus:
		{
			rezult->m_operation = BinaryOperation::Type::Adition;
		}break;
		case Token::Type::minus:
		{
			rezult->m_operation = BinaryOperation::Type::Subtraction;
		}break;
		case Token::Type::lparen:
		{
			int j = i;
			for (; j < tokens.size(); j++)
			{
				if (tokens[j].m_type == Token::rparen)
					break;
				std::vector<Token> subexpresion(&tokens[i + 1], &tokens[j]);
				auto element = parse(subexpresion);

				if (!have_left)
				{
					rezult->m_left = element;
					have_left = true;
				}
				else
				{
					rezult->m_right = element;
				}
			}
		}break;
		}
	}
}


void testFunction()
{
	std::string text{ "(13-4)-(12+1)" };
	auto tokens = lex(text);

	auto rez = parse(tokens);
	std::cout << rez->eval() << std::endl;


}