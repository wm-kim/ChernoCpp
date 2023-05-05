#include <iostream>

/*
std::move & move assignment operator


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
	
	String(const String& other)
	{
		std::cout << "Copied!\n";
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept
	{
		std::cout << "Moved!\n";
		m_Size = other.m_Size;
		m_Data = other.m_Data;
		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	// move assignment operator 
	// we are not constructing new object, we need to overwrite	the current object;
	// we need to delete the current data and copy the data from the other object
	String& operator=(String&& other) noexcept
	{
		std::cout << "Moved!\n";
		// check for self assignment
		if (this != &other)
		{
			delete[] m_Data;
			m_Size = other.m_Size;
			m_Data = other.m_Data;
			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		return *this;
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
	
	Entity(String&& name)
		: m_Name(std::move(name)) {}

	void PrintName() 
	{
		m_Name.Print();
	}
	
private:
	String m_Name;
};

int main() 
{
	String string = "Hello";
	// make it into temperary object, like a cast 
	 
	// String dest((String&&)string);
	// more elegant and flexible way : compile time figures out what type is coming in
	String dest = std::move(string);

	// assignment operator only get calls when object is already created

	String apple = "Apple";
	String dest;

	// dest = apple; error because we don't have copy assignment operator
	dest = std::move(apple); // dest.=(std::move(apple));
	// move constructor is different from move assignment operator
	
	
	std::cin.get();
}