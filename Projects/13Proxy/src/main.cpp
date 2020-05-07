// Proxy design pattern
// An interface for accessing a particular resource

//   Motivation
// exmple 
// You are calling foo.bar()
// This assumes that foo is in the same process as bar
// what if later on, you want to pull all Foo-relatted operation into a separate process
//				-can you avoiding changing your code
//Proxy to the rescue!
//				- same interface,entirely different behavior
//This is called a communication proxy
//				- Other types:logging,virtual, guarding


// PROXY definition
// A class that functions as an interface to a particular resource.
// That resource may be remote,expensive to construct, 
// or may require logging or some other added functionality.


//clasic proxy is smart pointer it is reacting like a normal pointer but it has aditional functionalytis  
//


#include <iostream>

int main()
{


	return 0;
}