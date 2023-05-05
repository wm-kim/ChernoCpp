#include <iostream>

// Argument Evalution Order

void PrintSum(int a, int b)
{
	std::cout << a << " + " << b << " = " << a + b << std::endl;
}

int main() 
{
	int value = 0;
	// this is undefined behavior; up until c++17
	// c++ standard does not specify, various on compiler
	PrintSum(value++, value++); 
	// in c++17 the postfix expression have to be evalution before each other expression
	
	std::cin.get();
}