#include <iostream> 
#include <string>
#include <memory>
#include <vector>

// unlike std::array, std::vector can be resized
// lot of studios create their own version of standard library make them more optimized and faster	
// ex EA-STL (github usually more faster than standard library https://github.com/electronicarts/EASTL)

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

// Do remember passing by reference
void Function(const std::vector<Vertex>& vertices)
{

}

int main()
{
	// Vertex* vertices = new Vertex[5];
	// 
	// also can pass primitive types
	// Its is hard to decide whether should using std::vector<Vertex*> or std::vector<Vertex>
	// technically more optimal to store vertex instead of pointers, 
	// but when it comes to resize the vector, it will copy the entire vector
	std::vector<Vertex> vertices;
	vertices.push_back({ 1, 2, 3 }); 
	vertices.push_back({ 4, 5, 6 });
	
	vertices.erase(vertices.begin() + 1);
	
	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	// range based for loop
	for (Vertex& v : vertices)
		std::cout << v << std::endl;
	
	vertices.clear();

	std::cin.get();
}