#include <iostream> 

// how the compiler knows if we have Log function in another file?
// Linker automatically finds it - if it doesn't cause link error
void Log(const char* message);

int main()
{
	std::cout << "Hello World!" << std::endl;
	std::cin.get();
}