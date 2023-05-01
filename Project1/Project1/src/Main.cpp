#include <iostream> 
#include <iostream>

#define LOG(x) std::cout << x << std::endl

void Increment(int value)
{
	// int value = 5; 
	value++;
}

void Increment2(int* value)
{
	(*value)++;
}

// just a syntax suger, look nicer simpler to read
// there is nothing you can don with reference that you can't do with pointers
void Increment3(int& value)
{
	value++;
}

int main()
{
	int a = 5;
	// int& ref; // error: a reference must be initialized
	int& ref = a;
	ref = 2;
	Increment(a);

	int b = 8; 
	ref = b; // cannot change reference, just copys the value
	
	// a = 8, b = 8

	LOG(a);

	std::cin.get();
}