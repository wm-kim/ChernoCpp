#include <iostream>
#include <string>

// don't like overusing macros, its get very hard to read for the first time

#define WAIT std::cin.get() // don't do this, don't use preprocesser this way

// or use in memory allocation in debug build to know how many bytes are allocated
// from which file and which line. if you replace new keyword into custom keyword

#if 0
// how to use marcro
// #define PR_DEBUG 1

#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#define LOG(x) // will automatically remove this line
#endif

#endif

// don't put space after backslash
#define MAIN int main() \
{\
	std::cin.get(); \
}
//
//int main()
//{
//	WAIT;
//	LOG("Hello World");
//}

MAIN