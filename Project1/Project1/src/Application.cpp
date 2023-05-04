#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base Constructor" << std::endl; }
	virtual ~Base() { std::cout << "Base Destructor" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() { m_Array = new int[5];  std::cout << "Derived Constructor" << std::endl; }
	~Derived() { delete[] m_Array; std::cout << "Derived Destructor" << std::endl; }
private:
	int* m_Array;
};

int main()
{
	Base* base = new Base();
	delete base;
	std::cout << "---------------------" << std::endl;
	Derived* derived = new Derived();
	delete derived;
	std::cout << "---------------------" << std::endl;
	Base* poly = new Derived();
	delete poly;

	std::cin.get();
}