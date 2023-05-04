#include <iostream>

// multidemensional array

int main()
{
	int* array = new int[5];
	
	// 2D array
	// can cause a memory fragmentation 
	// instead of having one continous buffer, thsi will create 5 seperate buffers
	// have to jump into different memory locations to get to the next row ( a lot slower )
	// can optimize memory accessing when you have a continous buffer
	// avoid 2d arrays if possible

	int** a2d = new int* [5];
	for (int i = 0; i < 5; i++)
		a2d[i] = new int[5];

	a2d[0][0] = 0;
	a2d[0][1] = 0;
	a2d[0][2] = 0;

	// this will just delete the array of pointers
	// delete[] a2d;

	for (int i = 0; i < 5; i++)
		delete[] a2d[i];
	delete[] a2d;

	int* array2 = new int[5 * 5];
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
			array2[x + y * 5] = 2;
	
	std::cin.get();
}