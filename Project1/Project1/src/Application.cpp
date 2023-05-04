#include <iostream>

// dynamic cast : its a tool more like a function, evaluate not in compile time but in run time
// useful cases, and how to use dynamic cast

class Entity
{
public:
	// having virtual function will make VTable of this class
	virtual void PrintName() {}
};

class Player : public Entity
{
	 
};

class Enemy : public Entity
{

};

int main()
{
	Player* player = new Player();
	Entity* actuallyPlayer = player;
	Entity* actuallyEnemy = new Enemy();
	
	// This is dangerous, since e1 is acutally Enemy
	// If we trying to do with unique to player, that enemy doesn't have
	// for example accessing data members that only player has, it will crash
	Player* p = (Player*)actuallyEnemy;

	// dynamic cast, if cast is valid it will return pointer to player
	// but if its not it will return null if it fails
	// the operand of dynamic cast must have a polymorphic class
	Player* p0 = dynamic_cast<Player*>(actuallyEnemy);
	if (p0) {}
	// in C# : if (p0 is Player) {}
	
	Player* p1 = dynamic_cast<Player*>(actuallyPlayer);

	// How is it know the player is actually player?
	// stores RTTI (Run Time Type Information) a bit of overhead 

	std::cin.get();
}