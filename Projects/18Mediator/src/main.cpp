//I will have my one company one day

//#include "ChatRoom.h"
//#include "Person.h"

#include "example.h"


int main()
{
	Mediator m;
	Participant p1(m);
	Participant p2(m);

	p1.say(2);

	/*ChatRoom room;

	Person riste{ "Riste",room };
	Person mile{ "Mile",room };
	Person ace{ "Ace",room };

	room.join(&riste);
	room.join(&mile);
	room.join(&ace);

	riste.pm("Ace", "good to join the conversation");*/
	
	return 0;
}