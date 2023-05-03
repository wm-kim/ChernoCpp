#include <iostream>

// why don't use namespace std;
// 1. want to know what I am using
// 2. avoid possible errors in the future
// don't use namespace in header file (never do that)
// just use inside the function or small scope

namespace apple {
	// implicit conversion
	void print(const std::string& text)
	{
		std::cout << text << std::endl;
	}
}

namespace orange {
	// don't require any kind of conversion
	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << text << std::endl;
	}
}

using namespace apple;
using namespace orange;

int main()
{
	print("Hello"); // olleh

	std::cin.get();
}