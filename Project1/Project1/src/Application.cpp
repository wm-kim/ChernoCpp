#include <iostream>
#include <array>
#include <vector>
#include <functional>

// lambda : ways to create function without having to pyhsically create function
// quick disposable function

// how to use, when to use?
// when you need to create a function that is only used once

void Foreach(const std::vector<int>& array, const std::function<void(int)>& func)
{
	for (int value : array)
		func(value);
}

int main()
{
	std::vector<int> values = { 1, 5, 4, 2, 3 };

	// lambda 
	// C++ lambda expressions : https://en.cppreference.com/w/cpp/language/lambda

	// what is called "capturing"
	// pass outside variable into lambda function (by refernce or by value)
	// [=] : capture all outside variable by value
	// [&] : capture all outside variable by reference
	int a = 5;

	auto lambda = [=](int value) { std::cout << "Value: " << value << std::endl; };
	auto lambda2 = [=](int value) mutable { a = 5; std::cout << "Value: " << value << std::endl; };
	Foreach(values, lambda);

	// typicall usecase
	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
	std::cout << *it << std::endl;
	
	std::cin.get();
}