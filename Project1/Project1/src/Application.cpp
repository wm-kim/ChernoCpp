#include <iostream>

/*
 Singleton is quite counter intuitive of OOP
 this doens't need to be class if you only have single instance of object
 with few data & few functions

 useful when we want to have functionality that applies to global set of data
 ex. random number generator, renderer, audio system, etc.

 almost use class as namespace. singleton class can just behave like namespaces
 there is nothing tied to the "Class"
*/

class Singleton
{
public:
	Singleton(const Singleton&) = delete;
	static Singleton& Get()
	{
		return s_Instance;
	}
private:
	Singleton() {}
	static Singleton s_Instance; // - have to define in cpp file
};

Singleton Singleton::s_Instance; // static member variable


class Random
{
public:
	Random(const Random&) = delete;
	static Random& Get()
	{
		static Random s_Instance; 
		return s_Instance;
	}
	 // float Float() { return m_RandomGenerator; }
	static float Float() { return Get().IFloat(); }
private:
	// internal float function
	float IFloat() { return m_RandomGenerator; }
	Random() {}
	float m_RandomGenerator = 0.5f;
};

// can just have namespace but can lose functionality like assign instance to variable
namespace RandomClass {
	static float s_RandomGenerator = 0.5f;
	static float Float() { return s_RandomGenerator; }
}

int main() 
{
	// creating another instance - delete copy constructor
	Singleton instance = Singleton::Get();
	// Singleton& instance = Singleton::Get();
	
	
	// auto& random = Random::Get();
	// float number = random.Float();

	float number = Random::Float();
	std::cin.get();
}