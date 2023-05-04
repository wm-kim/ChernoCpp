#include <iostream>
#include <string>
#include <tuple>

/*
struct Person
{
	std::string Name;
	int Age;
};
*/


// Structured bindings C++17
std::tuple<std::string, int> CreatePerson()
{
	return { "John", 25 };
}

int main()
{
	{
		std::tuple<std::string, int> person = CreatePerson();
		// auto person = CreatePerson();
		std::string& name = std::get<0>(person);
		int age = std::get<1>(person);
	}

	{
		std::string name;
		int age;
		std::tie(name, age) = CreatePerson();
	}

	// C++17
	{
		auto [name, age] = CreatePerson();
	}

	std::cin.get();
}