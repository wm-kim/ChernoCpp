#include <iostream>

// Union can only have one member, closed linked to type punning
// useful when you want different names for the same memory location

struct Vector2
{
	float x, y;
};

struct Vector4
{
	union 
	{
		// anonymous struct
		struct 
		{
			float x, y, z, w;
		};
		struct
		{
			// a is same memory location as x
			// b is same memory location as y
			Vector2 a, b;
		};
	};

	// this creates whole object 
	// Vector2 GetA() { return Vector2(); }

	// Type punning
	/*Vector2& GetA()
	{
		return *(Vector2*)&x;
	}*/
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
	struct Union
	{
		union
		{
			float a;
			int b;
		};
	};

	Union u;
	u.a = 2.0f;
	std::cout << u.a << ", " << u.b << std::endl;

	{
		Vector4 vector = { 1.0f, 2.0f, 3.0f, 4.0f };
		
		PrintVector2(vector.a);
		PrintVector2(vector.b);
		vector.z = 500.0f;
		std::cout << "-----------------" << std::endl;
		PrintVector2(vector.a);
		PrintVector2(vector.b);
	}
	
	std::cin.get();
}