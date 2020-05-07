#pragma once
#include <string>
#include <iostream>

class Person
{
  friend class ResponsiblePerson;
  int age;
public:
  Person(int age) : age(age) {}

  int get_age() const { return age; }
  void set_age(int age) { this->age = age; }

  std::string drink() const { return "drinking"; }
  std::string drive() const { return "driving"; }
  std::string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{
public:
  ResponsiblePerson(const Person& person) : person(person) {}
  
  int get_age() const { return person.age; }
  void set_age(int age) { person.age = age; }

  std::string drink() const 
  {
    if (person.age < 18)
      return "too young";
    return "drinking"; 
  }

  std::string drive() const 
  {
    if (person.age < 16)
      return "to young";
    return "driving"; 
  }
  std::string drink_and_drive() const 
  { 
    return "dead"; 
  }


private:
  Person person;
};