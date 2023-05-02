#include <iostream> 
#include <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
	int m_Age;
public:
	Entity(const String& name) : m_Name(name), m_Age(-1) {}
	explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity)
{
	// print entity
}

int main()
{
	PrintEntity(22);
	
	// "Cherno" is const char array. c++ has to do two conversion
	// 1. const char array -> string.
	// 2. string into Entity
	// Only allow to do one implicit conversion
	PrintEntity(std::string("Cherno"));
	PrintEntity(Entity("Cherno"));

	// Entity a = "Cherno"; error
	Entity a = std::string("Cherno");
	
	// Explicit keyword is used in constructor to prevent implicit conversion 
	Entity b = 22; // error
	Entity b(22);
	Entity b = (Entity)22; 
	Entity b = Entity(22);
	
	std::cin.get();
}