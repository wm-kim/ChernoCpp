#include <iostream> 
#include <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}
	
	const String& GetName() const { return m_Name; }
};

int main()
{
	Entity* e;
	{
		Entity entity; // called default constructor
		e = &entity;
		std::cout << entity.GetName() << std::endl;
	}

	{
		// create on heap, now we are responsible for deleting it
		Entity* entity = new Entity("Cherno"); 
		e = entity;
		std::cout << entity->GetName() << std::endl;
	}

	// If you can create object like this do it
	// this is the fastest way in c++ to intantiate object
	Entity entity2 = Entity("Cherno");
	

	{
	    // when using new keyword 
		// it allocates memory but also calls constructor 
		e = new Entity();
		// this is not calling constructor
		Entity* e = (Entity*)malloc(sizeof(Entity)); 
	}

	// placement new : decide where the memory comes from 
	// not really allocating memory just calling constructor and intialize Entity in a specific memory address
	{
		int a = 2;
		int* b = new int[50];
		
		Entity* e = new(b) Entity();
	}
	
	std::cin.get();
	delete e;
}