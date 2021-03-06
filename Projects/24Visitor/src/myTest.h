#pragma once
#include <sstream>


template<typename T>
class Visitor
{
	public:
		virtual void visit(T& obj) = 0;
};


class VisitorBase
{
public:
	~VisitorBase() = default;
};


class Expresion
{
	virtual void accept(VisitorBase& obj)
	{
		auto visit = dynamic_cast<Visitor<Expresion>*>(&obj);
	}
};

class DoubleExpresion
	:public Expresion
{
	public:
		DoubleExpresion(double value)
			:m_value(value)
		{

		}

		double getValue()
		{
			return m_value;
		}

	private:
		double m_value;
};


class AditionExpresion
	:public Expresion
{
	public:
		AditionExpresion(Expresion* left, Expresion* right)
			:m_left(left)
			,m_right(right)
		{

		}

		Expresion* getLeft()
		{
			return m_left;
		}

		Expresion* getRight()
		{
			return m_right;
		}

	private:
		Expresion* m_left;
		Expresion* m_right;
};

class ExpresionPrinter
	:public VisitorBase
	, public Visitor<DoubleExpresion>
	, public Visitor<AditionExpresion>
{
	public:

};

