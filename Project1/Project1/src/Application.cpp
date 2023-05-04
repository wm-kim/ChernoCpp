#include <iostream>

// C.C++ style type casting; should learn from experience

class Base
{
public:
	Base() {}
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() {}
	~Derived() {}
};

class AnotherClass : public Base
{
public:
	AnotherClass() {}
	~AnotherClass() {}
};

// C++ style type casting (static cast)
// these can do whatever C style casting can do (+alpha)
// not adding new fucntionality but its syntax suger
// 1. static_cast : static cast, compile time check
// 2. dynamic_cast : perform a check and may return null if it fails
// 3. const_cast : adding or removing const 
// 4. reinterpret_cast : don't want to convert anything, just want reinterpreting memory

int main()
{
	// C style type casting
	double value = 5.25;
	double a = (int)value + 5.3;

	// static cast
	double s = static_cast<int>(value) + 5.3;
	// double s = static_cast<AnotherClass*>(&value) + 5.3; - error (compile time checking)
	
	// dynamic_cast
	Derived* derived = new Derived();
	Base* base = derived;
	// atempt conversion
	AnotherClass* ac = static_cast<AnotherClass*>(base);
	if (ac) {}

	std::cin.get();
}