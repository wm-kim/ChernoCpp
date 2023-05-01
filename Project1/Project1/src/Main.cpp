#include <iostream> 

class Entity
{
public:
	int* example = new int[5];
	
	Entity()
	{
		// there is no way to know size of the array in heap, but in stack you can know the size
		// example->size(); 
		for (int i = 0; i < 5; i++)
			example[i] = 2;

		int a[5];
		int count = sizeof(a) / sizeof(int);
	}
};

class Entity2
{
public:
	// const int size = 5;
	// int example[size]; should be compile time known constant

	// const expression have to be static 
	// static constexpr int size = 5;
	
	static const int size = 5;
	int example[size];

	Entity2()
	{
		for (int i = 0; i < size; i++)
			example[i] = 2;
	}
}; 

// C++11, consider using this 
#include <array>

class Entity3
{
public:
	std::array<int, 5> example;

	Entity3()
	{
		for (int i = 0; i < example.size(); i++)
			example[i] = 2;
	}
};

int main()
{
	int example[5];             // created on stack, destroy when out of scope
	int* another = new int[5];  // created on heap, destroy when delete is called or program ends

	delete[] another;           
	std::cin.get();
}