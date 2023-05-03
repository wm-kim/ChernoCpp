#include <iostream>
#include <array>

void PrintArray(int* array, unsigned int size)
{
	for (int i = 0; i < size; i++) {}
}

void PrintArray(std::array<int, 5>& array)
{
	for (int i = 0; i < array.size(); i++) {}
} 

int main()
{
	// why you should use std::array instead of C-style arrays
	// what is advantange?
	std::array<int, 5> data; // stack
	data[0] = 2;
	data[4] = 1;

	int dataOld[5]; // stack
	dataOld[0] = 0;

	// can also use std algorithm with the class
	// std::sort(data.begin(), data.end());

	// and also in debug mode, and it would do bounds checking
	
	std::cin.get();
}