#include <iostream> 
#include <string>

struct Entity 
{
public:
	virtual std::string GetName() = 0;
};

class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) {}

	std::string GetName() override { return m_Name; }
};

int main()
{
	// Don't have ability to create an instance of Entity
	// Entity* e = new Entity();

	// should implement all the pure virtual functions 
	// in order to be able to create an instance of the class

	// interface in c++ is just class with pure virtual function in c++
	
	std::cin.get();
}