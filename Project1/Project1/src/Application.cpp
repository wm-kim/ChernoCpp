#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// sorting

int main()
{
	std::vector<int> values = { 3, 5, 1, 4, 2 };
	std::sort(values.begin(), values.end()); // using operator <. ascending order
	std::sort(values.begin(), values.end(), std::greater<int>()); // descending order
	std::sort(values.begin(), values.end(), [](int a, int b) 
	{ 
		if( a == 1 )
			return false; 
		if (b == 1)
			return true; // move a to the front

		return a < b; 
	}); 
	
	std::cin.get();
}