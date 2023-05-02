#include "../../Engine/src/Engine.h"
// relative path is messy use absolute path (compile include path)
#include "Engine.h"
#include <iostream>

// beacuse Engine is in our solution doesn't have to be maually edit settings
// vs automatically does that for us 

// something inside engine changes and we compile game, game is going to compile engine together
int main()
{
	engine::PrintMessage();
	std::cin.get();
}