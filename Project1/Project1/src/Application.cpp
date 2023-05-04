#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		auto start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		auto end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took " << ms << "ms" << std::endl;
	}
};

void Function()
{
	Timer timer;
	
	for (int i = 0; i < 100; i++)
	{
		// std::endl; can be slow
		//	std::cout << "Hello " << i << std::endl;
		std::cout << "Hello\n";;
	}
}

// platform independent c++ stl way of figuring out how much time passes
// can be used for building profiling tools

int main()
{
	using namespace std::chrono_literals;

	auto start = std::chrono::high_resolution_clock::now();
	// pause execution for 1 second
	std::this_thread::sleep_for(1s);
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;
	std::cout << "Duration: " << duration.count() << "s" << std::endl;

	Function();

	std::cin.get();
}