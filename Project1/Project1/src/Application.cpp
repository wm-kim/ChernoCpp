#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Auto keyword
// If I have auto, do I really need to every write any types ? 
// comes end to matter of style.

// server side 
std::string GetName() {}

class Device {};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}
};

// C++14
auto GetName2()
{
	return "Cherno";
}

// C++11
auto GetName3() -> const char*
{
	return "Cherno";
}

int main()
{
	// std::string name = GetName();
	// in client side, code remains the same
	// but this could be a bad thing, because the api can change
	
	// for these cases recommand not to use auto
	auto name = GetName();
	name.size();

	// In this case, auto is useful
	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");


	// iterator is not used in c++11
	// for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	// typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;
	
	DeviceManager dm;
	const DeviceMap& devices = dm.GetDevices();
	// keep in mind that we have to use reference here (not to make a copy)
	const auto& devices2 = dm.GetDevices();

	// auto keywords also used in trailing return types,
	// also can use function decide ruturn type
	
	std::cin.get();
}