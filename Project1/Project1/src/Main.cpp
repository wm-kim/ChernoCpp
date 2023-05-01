#include <iostream> 
extern int s_Variable; // Declaration of s_Variable

struct Entity
{
	static int x, y;
	static void Print() { std::cout << x << ", " << y << std::endl; }
};

// Definition of static variables
int Entity::x;
int Entity::y;

int main()
{
	Entity e;
	e.x = 2;
	e.y = 3;

	Entity e1;
	e1.x = 5; // Entity::x = 5;
	e1.y = 8; // Entity::y = 8;

	std::cout << s_Variable << std::endl;
	std::cin.get();
}