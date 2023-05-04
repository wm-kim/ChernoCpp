#include <iostream>

// Type Punning : get that type as pointer and cast it to another type of pointer and dereference it

// more practical example
struct Entity
{
	int x, y;

	int* GetPositions()
	{
		return &x;
	}
};

int main()
{
	int a = 50;
	double value = (double)a; 
	std::cout << value << std::endl;

	// Type Punning integer into double
	// convert int pointer to double pointer and dereference it
	// this going to look 4 bytes pass of integer and write that memory
	double value2 = *(double*)&a;
	double& value3 = *(double*)&a;
	value2 = 0.0; // can cause crash

	Entity e = { 5, 8 };
	int* position = (int*)&e;
	std::cout << position[0] << ", " << position[1] << std::endl;
	
	int y = *(int*)((char*)&e + 4); // char is 1 byte, so 4 bytes pass of x is y
	std::cout << y << std::endl;

	// it can be useful if you don't want to deal with copying or conversions
	// if you don't like dealing raw cast, can use reinterpret_cast (same thing)
	{
		int* position = e.GetPositions();
		position[0] = 2;
	}

	std::cin.get();
}