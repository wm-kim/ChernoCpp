#include <iostream> 
#include <string>
#include <memory>
#include <vector>

// Optimizing the usage of std::vector by avoiding unnecessary copies
struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}

	Vertex(const Vertex& vertex)
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

int main()
{
	// if the vector has not enough space
	// it will allocate more space and copy the old data to the new location
	std::vector<Vertex> vertices; 
	
	// reserve the space for the vector
	vertices.reserve(3);

	vertices.push_back(Vertex(1, 2, 3));
	vertices.push_back(Vertex(4, 5, 6));
	vertices.push_back(Vertex(7, 8, 9));

	// whould like to construct the vertex in the vector by using emplace_back
	vertices.emplace_back(Vertex(1, 2, 3));
	vertices.emplace_back(Vertex(4, 5, 6));
	vertices.emplace_back(Vertex(7, 8, 9));

	std::cin.get();
}