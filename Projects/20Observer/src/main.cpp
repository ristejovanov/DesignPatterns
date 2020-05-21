#include "MyPerson.h"

int main()
{
	MyPerson riste(27, 4);
	MyPersoneObsrver ob;
	riste.addLieners(&ob);
	riste.setAge(28);


	return 0;
}