#include <iostream> 
#include <string>

// You should use member initialize list everywhere 

class Example
{
public:
	Example()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	Example(int x)
	{
		std::cout << "Created Entity with " << x << "!" << std::endl;
	}
};

class Entity
{
private:
	std::string m_Name;
	int x, y, z;
	Example m_Example;
public:
	/*Entity()
	{
		m_Name = "Unknown";
	}*/

	// Initalize list, should be in order of declaration
	Entity() : m_Name("Unknown"), x(0), y(0), z(0) {}

	Entity() : x(0), y(0), z(0) 
	{
		// not using initialize list, create two strings
		m_Name = std::string("Unkown");
		// created two entity
		m_Example = Example(8);
	}

	Entity(const std::string& name)
	{
		m_Name = name;
	}

	const std::string& GetName() const { return m_Name; }
};


int main()
{
	Entity e0;
	std::cout << e0.GetName() << std::endl;

	Entity e1("Cherno");
	std::cout << e1.GetName() << std::endl;

	std::cin.get();
}