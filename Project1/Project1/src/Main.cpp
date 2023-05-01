#include <iostream> 
#include <string>

class Entity
{
private:
	int m_X, m_Y;
	// mutable allows you to modify a variable in a const function
	mutable int var;
public:
	// const means that the function will not modify the class
	int GetX() const
	{
		var = 2;
		// m_X = 2; // This will not work because the function is const
		return m_X;
	}
};

void PrintEntity(const Entity& e)
{
	// e = Entity(); // This will not work because the function is const
	// if GetX was not const, this would not work either
	// because it is not sure that GetX will not modify the class
	std::cout << e.GetX() << std::endl;
}

int main()
{
	const int MAX_AGE = 90;
	const int* a = new int; // can't change content of the pointer
	int const* c = new int; // can't change content of the pointer (same as above)
	
	int* const b = new int; // can't change the pointer

	const int* const d = new int; // can't change the pointer or the content of the pointer
	
	// *a = 2;
	a = (int*)&MAX_AGE;
	std::cout << *a << std::endl;

	std::cin.get();
}