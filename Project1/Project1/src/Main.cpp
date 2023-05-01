#include <iostream> 
#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
	int var = 7;
	// data at that address is presumed to be type of we given, doesn't mean anything
	// void* ptr = nullptr;
	// void *ptr = NULL; #define NULL 0
	void* ptr = &var;
	*ptr = 10; // don't know how to write the data

	// create a variable on a heap
	char* buffer = new char[8];
	memset(buffer, 0, 8);

	delete[] buffer;
	std::cin.get();
}