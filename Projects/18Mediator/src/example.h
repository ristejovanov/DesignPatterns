#pragma once
#include <vector>

class Mediator;

struct IParticipant
{
  virtual void say(int value) = 0;
  virtual void recive(IParticipant* from, int v) = 0;
};

struct Mediator
{
  Mediator() {}
  ~Mediator() {}


  void brodcast(IParticipant* sender, int value)
  {
    for (auto p : participants)
    {
      p->recive(sender, value);
    }
  }

  std::vector<IParticipant*>  participants;
};


struct Participant : IParticipant
{
  int value{ 0 };
  Mediator& mediator;

  Participant(Mediator& mediator) : mediator(mediator)
  {
    mediator.participants.push_back(this);
  }

  void say(int value) override
  {
    mediator.brodcast(this, value);
  }

  void recive(IParticipant* from, int v) override
  {
    if (from != this)
    {
      value += v;
    }
  }
};



