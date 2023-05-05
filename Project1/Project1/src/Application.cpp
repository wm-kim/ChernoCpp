#include <iostream>

// lvalue & rvalue

// lvalue reference taking lvalue unless its const
void PrintName(const std::string& name)
{
	std::cout << "[lvalue] " << name << std::endl;
}

// rvalue reference only taking rvalue
// can steal the resources from the temporary value - help with optimization
void PrintName(std::string&& name)
{
	std::cout << "[rvalue] " << name << std::endl;
}

int main() 
{
	std::string firstName = "Yan";
	std::string lastName = "Chernikov";

	std::string fullname = firstName + lastName;

	PrintName(firstName); // lvalue
	PrintName(firstName + lastName); // rvalue
	std::cin.get();
}