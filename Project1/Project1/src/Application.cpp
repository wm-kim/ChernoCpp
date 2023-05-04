#include <iostream>
#include <any>

int main()
{
	std::any data;
	data = 2;
	data = "Cherno";
	data = std::string("Cherno");
	
	// will get exception if we try to cast to wrong type
	std::string& string = std::any_cast<std::string&>(data);

	// can store any type while std::variant have to list all types
	// the fact that std::variant requires to list out all types is a good thing - type safe
	// variant is just typesafe union

	// std::any is for small data types it just store as a union
	// when we store a big data type it will dynamically allocate memory (more than 32 bytes)
	// (not good performance)
	// std::variant performs faster if you deal with larger data
	
	// when to use std::any? - bit of a useless
	
	std::cin.get();
}