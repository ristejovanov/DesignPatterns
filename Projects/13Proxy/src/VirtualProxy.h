#pragma once
#include <iostream>
#include <string>

class Image
{
	virtual void drow() = 0;
};

class BitMap
	:public Image
{
public:
	BitMap(std::string fileName)
	{
		std::cout << "Loading bitmap from " << fileName << std::endl;
	};
	~BitMap() {};

	void drow() override
	{
		std::cout << "drowing bitmap " << std::endl;
	}
};


class ImproveBitmap
	:public Image
{
	public:
		ImproveBitmap(std::string fileName)
			:_fileName(fileName)
		{}

		void drow() override
		{
			if (_bitmap == nullptr)
			{
				_bitmap = new BitMap(_fileName);
			}
			_bitmap->drow();
		}

	private:
		std::string _fileName;
		BitMap* _bitmap{ nullptr };
};

void bitmapTest()
{
	ImproveBitmap bitmap("pokemon.png");
	bitmap.drow();

}