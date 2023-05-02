#include <iostream> 
#include <string>
#include <memory>

// Scoped Pointer : wrapper over pointer, heap allocate pointer and automate delete thing
// ex. mutex locking - automatic scoped lock


// unique pointer is scoped pointer, can't copy


class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
	
	void Print() {}
};

class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* ptr)
		: m_Ptr(ptr)
	{
	}

	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

int main()
{
	{
		ScopedPtr e = new Entity(); // implicit conversion
	} // e is destroyed here

	{
		std::unique_ptr<Entity> entity(new Entity()); // constructor is explicit
		
		// slightly safer if destructor throw exception and end up having dangling pointer (memory leak)
		std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();  
		std::unique_ptr<Entity> e0 = entity; // error, copy consturctor is deleted
		entity->Print();
	}

	{
		std::shared_ptr<Entity> e0;
		{
			// shared pointer - reference counting 
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			// or new Entity(),this is fine
			// because shared pointer has control block, which has reference count and pointer to object
			// and when construct them together
			e0 = sharedEntity;
		}
	} // if all the reference is gone, then it will be destroyed


	// this is great if you don't want to take ownserhip of entity, it won't keep it alive
	// can ask week pointer "are you still valid"
	{
		std::weak_ptr<Entity> weakEntity;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			weakEntity = sharedEntity;
		} // weak pointer doesn't increase reference count, so it will be destroyed
	} 

	std::cin.get();
}