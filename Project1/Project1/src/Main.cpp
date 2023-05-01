#include <iostream> 
#include <string>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
public:
	const std::string& GetName() const
	{ 
		m_DebugCount++;
		return m_Name; 
	}
};

int main()
{
	const Entity e;
	e.GetName();

	int x = 8;

	// doesn't write this lamdba very often
// 
	// define capture method, by value
	// mutable lambda means we can change the value of x, when we capture by value
	auto f = [=]() mutable
	{
		// int y = x; 
		// y++;
		// std::cout << y << std::endl;
		
		x++; // just going to create local variable 
		// make more cleaner
		std::cout << x << std::endl;
	};
	
	// x = 8;
	
	std::cin.get();
}