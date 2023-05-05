#include <iostream>

/*
 Move semantics is a C++ feature that allows us to "move" resources from one object to another.

 useful for avoiding unnecessary copies of temporary objects
and enabling more efficient resource transfers between objects.

 Before C++11, there was no straightforward way to distinguish between a temporary object
 and an object whose resources could be "stolen" or moved.

 When a function accepts an rvalue reference as an argument,
 it can safely assume that the passed object is a temporary one,
 and it's permissible to transfer its resources without causing any side effects.
*/

class String 
{
public:
	String() = default;
	String(const char* string)
	{
		std::cout << "Created!\n";
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	
	// copy constructor
	String(const String& other)
	{
		std::cout << "Copied!\n";
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	// move constructor
	// noexcept : this function will not throw any exceptions
	String(String&& other) noexcept
	{
		std::cout << "Moved!\n";
		m_Size = other.m_Size;
		// what happens when the old object is destroyed?
		m_Data = other.m_Data;

		// we need to make sure that the old object doesn't delete the data
		other.m_Size = 0;
		other.m_Data = nullptr;
		// if old object is destroyed, it will just delete nullptr
	}
	
	~String()
	{
		std::cout << "Destroyed!\n";
		delete[] m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
			std::cout << m_Data[i];
	}
private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity
{
public:
	Entity(const String& name)
		: m_Name(name) {}
	
	// Entity should also have a move constructor
	Entity(String&& name)
		: m_Name(std::move(name)) {} // m_Name((String&&)name)

	void PrintName() 
	{
		m_Name.Print();
	}
	
private:
	// why can't we just move it into here -> move constructor
	String m_Name;
};

int main() 
{
	// just want to get String("Cherno") into m_Name
	Entity entity(String("Cherno"));
	entity.PrintName();
	// without move constructor, it will copy the string
	
	std::cin.get();
}