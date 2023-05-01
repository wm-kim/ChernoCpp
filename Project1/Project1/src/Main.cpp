#include <iostream> 

// how the compiler knows if we have Log function in another file?
// Linker automatically finds it - if it doesn't cause link error
void Log(const char* message);

int main()
{
	int a = 8;
	a++;
	const char* string = "Hello";
	
	for (int i = 0; i < 5; i++)
	{
		const char c = string[i];
		std::cout << c << std::endl;
	}

	std::cout << "Hello World!" << std::endl;
	std::cin.get();
}