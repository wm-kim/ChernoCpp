#include <iostream>
#include <array>

// you can use int but usually in c++ use size_t interally
template<typename T, size_t S>
class Array
{
public:
	/*
	Array(int size)
	{
		// let us allocate memory on stack - can allocate on runtime
		// compiler doens't know how big is size is, lack of compiler optimization
		// but can be useful in some cases
		// m_Data = (int*)alloca(size * sizeof(int));
	}
	*/
	// int Size() const { return 5; }
	constexpr size_t Size() const { return 5; }
	T& operator[](size_t index) 
	{
		/*if (!(index < S)) - don't include in release mode
		{
			__debugbreak();
		}*/
		return m_Data[index]; 
	}
	const T& operator[](size_t index) const { return m_Data[index]; }  // const verison
		T* Data() { return m_Data; }
		const T* Data() const { return m_Data; }
private:
	T m_Data[S];
};

int main() 
{
	Array<int, 5> data; 

	// take andantage that in compile time know the size
	static_assert(data.Size() < 10, "Size is too large!"); // needs constexpr

	Array<std::string, data.Size()> newArray;

	for (int i = 0; i < data.Size(); i++)
	{
		// data[i] = 2; // need index operator return reference type
		std::cout << data[i] << std::endl;
	}

	memset(data.Data(), 0, data.Size() * sizeof(int));
	// since this is stack allocated its gaurenteed to be contiguous
	memset(&data[0], 0, data.Size() * sizeof(int));

	std::cin.get();
}