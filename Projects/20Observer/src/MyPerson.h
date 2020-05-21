#pragma once
#include <iostream>


#include "MyPerson.h"
#include "Observer.h"
#include "Observable.h"

class MyPerson
	:public Observable<MyPerson>
{
public:
	MyPerson(int age,int experiance);

	void setAge(int age);
	void setExperiance(int experiance);

	int getAge();
	int getExperiance();

private:

	int m_age;	
	int m_experiance;
};



class MyPersoneObsrver
	:public Observer<MyPerson>
{
	public:
		void field_changed(MyPerson& source, std::string field)
		{
			std::cout << "In class MyPersone field " + field + "has change" << std::endl;
		}
 };

