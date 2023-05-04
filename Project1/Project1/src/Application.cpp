#include <iostream>
#include <fstream>
#include <optional>

// optional data in c++. simplify code and makes your code more readable

std::string ReadFileAsString(const std::string& filepath, bool& outSuccess)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		// read file
		stream.close();
		outSuccess = true;
		return result;
	}

	outSuccess = false;
	return std::string();
}

std::optional<std::string> ReadFileAsString2(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		// read file
		stream.close();
		return result;
	}

	return {};
}


int main()
{
	{
		std::string data = ReadFileAsString("data.txt");
		if (!data.empty())
			std::cout << "data: " << data << std::endl;
		else
			std::cout << "Could not read file" << std::endl;
	}

	{
		bool fileOpenedSuccesfully;
		std::string data = ReadFileAsString("data.txt", fileOpenedSuccesfully);
		if (fileOpenedSuccesfully)
		{
			// do something with data
		}
		else
		{
			// handle error
		}
	}

	{
		std::optional<std::string> data = ReadFileAsString2("data.txt");
		std::string value = data.value_or("Not present");
		std::cout << value << std::endl;
 
		if (data.has_value()) // if(data) is also valid
		{
			// do something with data
		}
		else
		{
			// std::string& string = *data;
			// data.value();
			std::cout << "File could not be opened!" << std::endl;
		}
	}

	std::cin.get();
}