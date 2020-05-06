#pragma once

template<typename T>
class Property
{
	public:
		Property(T prop)
		{
			*this = prop;
		};

		T operator=(T newProp)
		{
			return _value = newProp;
		}

		operator T()
		{
			return _value;
		}

	private:
		T _value;
};

struct Creature
{
	Property<int> _agility{10};
	Property<int> _strenght{5};
};


void test()
{
	Creature cr;
	cr._agility = 10;
	int x = cr._strenght;

	// conclusion the class is actting like property class does not exist 
	// and the property class is just a vraper over the int variables
	// this is the same like a shared_ptr it is just a vraper over the row pointer it dosn't change anything just add some extra stuf.
}