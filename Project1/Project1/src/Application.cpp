#include <iostream>
#include <string>

// std::strigview : a pointer to a string (const char*) + size
// creating view of existing memory instead of allocate whole new memory

#define STRING_VIEW 1

static uint32_t s_AllocCount = 0;

// std::strings tends to allocate in the heap
void* operator new(size_t size)
{
    s_AllocCount++;
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}

# if STRING_VIEW
void PrintName(std::string_view name)
{
	std::cout << name << std::endl;
}
# else
void PrintName(const std::string& name)
{
	std::cout << name << std::endl;
}
# endif

int main() 
{

	std::string name = "Yan Chernoikov"; // allocate 1 time
	// const char* name = "Yan Chernoikov"; 
	
#if STRING_VIEW
	std::string_view firstName(name.c_str(), 3);
	std::string_view lastName(name.c_str() + 4, 9);
#else 
	// PrintName("Yan Chernoikov"); // allocate 1 time
	std::string firstName = name.substr(0, 3);
	std::string lastName = name.substr(4, 9);
#endif
	
	PrintName(firstName);
	PrintName(lastName);

	std::cout << "AllocCount: " << s_AllocCount << std::endl;
	std::cin.get();
}