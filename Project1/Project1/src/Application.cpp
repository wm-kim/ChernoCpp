#include <iostream>
#include <variant>
#include <string>
#include <optional>

// good to know what when wrong instead of saying data is not present
std::optional<std::string> ReadFileAsString()
{
	return {};
}

enum class ErrorCode
{
	None = 0, NotFound = 1, NoAccess = 2
};

std::variant<std::string, ErrorCode> ReadFileAsString2()
{
	return {};
}

// std::variant 
// allow us to not have to worry about the type of the data
// list all the type it could be, and later decide which one it is

int main()
{
	std::variant<std::string, int> data;
	// union size is the size of the largest type
	// but variant size is the size of all the types combined
	// union is more efficent but variant is more type safe
	
	data = "Cherno";
	std::cout << std::get<std::string>(data) << std::endl;
	data.index(); // 0 
	if (auto* value = std::get_if<std::string>(&data)) // returns a pointer to the data if it is a string, otherwise returns nullptr
	{
		std::string& v = *value;
	}
	else
	{

	}
	
	data = 2;
	data.index(); // 1
	 
	std::cout << std::get<int>(data) << std::endl;
	// std::cout << std::get<std::string>(data) << std::endl; - exception
	
	std::cin.get();
}