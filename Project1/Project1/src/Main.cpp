#include <iostream> 
#include <string>
#include <memory>

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	//String(const String& other) : m_Buffer(other.m_Buffer), m_Size(other.m_Size) {}
	// or { memcpy(this, &other, sizeof(String)); }

	String(const String& other) : m_Size(other.m_Size)
	{
		std::cout << "Copied String!" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}
	
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

// ** Always pass object by const reference ** 
void PrintString(const String& string)
{
	// if not const, we can do string[2] = 'a';
	std::cout << string << std::endl;
}

int main()
{
	String string = "Cherno";
	String second = string; // Shallow copy

	second[2] = 'a';
	
	std::cout << string << std::endl;
	std::cout << second << std::endl; // this will crash because we are trying to delete the same memory twice

	std::cin.get();
}