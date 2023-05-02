#include <iostream> 
#include <string>
#include <memory>
#include <vector>

// static local variable allows to declare varaible inside function of life time of program
// however its scope is limited to scope(function, if statement, ...)

void Function()
{
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}

class Singleton
{
public:
	static Singleton& Get()
	{
		static Singleton instance;
		return instance;
	}

	void Hello() { std::cout << "Hello" << std::endl; }
};

int main()
{
	Singleton::Get().Hello();
	std::cin.get();
}