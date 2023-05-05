#include <iostream>
#include <string>
#include <memory>

// How to Track memory allocation
// Trace back in callstack where the memory allocation is coming from
// VS has memory allcation tracking profile tools

// quick way to track memory allocation
struct AllocationMatrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMatrics s_AllocationMatrics;

void* operator new (size_t size)
{
	s_AllocationMatrics.TotalAllocated += size;
	// std::cout << "Allocating " << size << " bytes\n";
	// breakpoint here
	return malloc(size);
}

void operator delete (void* memory, size_t size)
{
	s_AllocationMatrics.TotalFreed += size; 
	// std::cout << "Freeing " << size << " bytes\n";
	free(memory);
}

static void PrintMemoryUsage()
{
	std::cout << "Memory Usage: " << s_AllocationMatrics.CurrentUsage() << " bytes\n";
}

struct Object
{
	int x, y, z;
};

int main() 
{
	PrintMemoryUsage();
	std::string string = "Cherno";
	PrintMemoryUsage();
	{
		std::unique_ptr<Object> obj = std::make_unique<Object>();
		PrintMemoryUsage();
	}
	PrintMemoryUsage();

	std::cin.get();
}