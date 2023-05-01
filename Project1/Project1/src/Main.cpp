#include <iostream> 
#include <string>


// don't do this, create copy of this class
// copy a string is dynamic heap allocation, string copy is slow
void PrintString(std::string string)
{
	std::cout << string << std::endl;
}

// pass by reference, no copy
void PrintStringRef(const std::string& string)
{
	std::cout << string << std::endl;
}

int main()
{
	// how to know its size?, string ends with 0
	const char* name = "hello";
	const char name2[6] = { 'h', 'e', 'l', 'l', 'o', 0 }; // 0 or '\0' is the null terminator
	std::string name3 = "hello"; // + "world"; error
	std::string name4 = std::string("hello") + "world"; // ok
	name3 += "world";

	// there is no .contains in c++ string
	bool contains = name3.find("ll") != std::string::npos;
	
	// this is wrong, string literals are always stored in readonly memory
	// char* name5 = "Cherno";
	// in c++11 const char* is possible
	
	const wchar_t* name6 = L"Cherno"; // wide char, 2 bytes
	const char16_t* name7 = u"Cherno"; // 2 bytes
	const char32_t* name8 = U"Cherno"; // 4 bytes

	std::cout << name3 << std::endl;

	// c++14 
	using namespace std::string_literals;
	std::string name9 = "Cherno"s + " hello!";
	std::wstring name10 = L"Cherno"s + L" hello!";
	std::u32string name11 = U"Cherno"s + U" hello!";

	const char* example = R"(Line1
Line2
Line3)";
}