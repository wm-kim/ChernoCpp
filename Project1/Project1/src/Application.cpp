#include <string>
#include <sstream>
#include <fstream>
#include <array>
#include <vector>
#include <tuple>

struct ShaderProgrammingSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

// this is one of the optimal ways of returning multiple values
static void ParseShader(const std::string& filepath, std::string* outVertexSource, std::string* outFragmentSource)
// static void ParseShader(const std::string& filepath, std::string& vertexSource, std::string& fragmentSource)
// static std::string*
// static std::array<std::string, 2>  -- created on stack (faster)
// static std::vector<std::string>    -- created on heap

// std::tuple<std::string, std::string> 
// static std::pair<std::string, std::string>

{
	std::ifstream stream(filepath);
	std::string line;
	std::stringstream ss[2];

	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	ShaderType type = ShaderType::NONE;
	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else {
			ss[(int)type] << line << '\n';
		}
	}

	std::string vs = ss[0].str();
	std::string fs = ss[1].str();

	if (outVertexSource) *outVertexSource = vs;

	// vertexSource = vs;
	// fragmentSource = fs;

	// heap allocating
	// return new std::string[]{ vs, fs };

	// using std::array
	// return std::array<std::string, 2>(vs, fs);

	// return std::make_pair(vs, fs);
}

int main()
{
	std::string vs, fs;
	// ParseShader("filepath", vs, fs);
	ParseShader("filepath", &vs, &fs);

	// using heap allocating
	// std::string* sources = ParseShader("filepath");

	
}