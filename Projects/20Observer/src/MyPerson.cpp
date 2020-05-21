#include "MyPerson.h"

MyPerson::MyPerson(int age, int experiance)
	:m_age(age)
	,m_experiance(experiance)
{

}

void MyPerson::setAge(int age)
{
	m_age = age;

	notified(*this, "age");

}

void MyPerson::setExperiance(int experiance)
{
	m_experiance = experiance;
}

int MyPerson::getAge()
{
	return m_age;
}

int MyPerson::getExperiance()
{
	return m_experiance;
}
