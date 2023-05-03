#include <iostream>
#include <string>

// sort of meta-programming in c++ - this could get really complicated
// for example generate entire meta langauge, don't abuse this
// Templates are evaluated at compile time
// extremely useful for logging system & material system (rendering graphics)
template<typename T, int N>
class Array
{
private:
	T m_Array[N];
public:
	int GetSize() const { return N; }
};

// Tmemplates in c++
// get compiler write code for you, based on set of rules

template<typename T>
void Print(T value)
{
	std::cout << value << std::endl;
} 

int main()
{
	// based on the type of the argument, compiler will generate a function
	// if the Print function is not used, the compiler will not generate a function
	Print(5);
	Print("Hello");
	Print(5.5f);

	Array<std::string, 50> array;
	std::cout << array.GetSize() << std::endl;

	std::cin.get();
}