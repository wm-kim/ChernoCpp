#include <iostream>
#include <array>
#include <vector>

// function pointer comes from C
// function is just cpu instructions. somewhere in binary (executable file)
// function pointer finds the address of the function in the binary

void HelloWorld(int a)
{
	std::cout << "Hello World Value : " << a << std::endl;
}

void PrintValue(int value)
{
	std::cout << "Value : " << value << std::endl;
}

void Foreach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}

int main()
{
	// this is confusing, so people tend to use auto or typedef 
	// void(*function)() = HelloWorld;
	typedef void(*HelloWorldFunction)(int);
	
	auto function = HelloWorld; // implicit convertion (& not needed)
	HelloWorldFunction function2 = HelloWorld;

	function(8);

	// example of why you use function pointer.
	// tell function what to do
	std::vector<int> values = { 1, 5, 4, 2 ,3 };
	Foreach(values, PrintValue);

	// lambda
	Foreach(values, [](int value) { std::cout << "Value : " << value << std::endl; });
	
	std::cin.get();
}