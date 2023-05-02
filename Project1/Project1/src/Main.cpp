#include <iostream> 
#include <string>
#include <memory>

// why want to overload arrow operator and how to use it in custom classes
// example

class Entity
{
public:
	int x;
public:
	void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		: m_Obj(entity)
	{
	}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	Entity* operator->()
	{
		return m_Obj;
	}

	const Entity* operator->() const
	{
		return m_Obj;
	}
};

struct Vector3
{
	float x, y, z;
	// float x, z, y; 
	// how to tell the offset of each member in the struct
};

int main()
{
	{
		ScopedPtr entity = new Entity();
		entity->Print();
	}

	{
		// const version
		const ScopedPtr entity = new Entity();
		entity->Print();
	}


	// used arrow operator to get the member of the struct
	int offset = (int)&((Vector3*)nullptr)->y; // 4
	std::cout << offset << std::endl;
	
	std::cin.get();
}