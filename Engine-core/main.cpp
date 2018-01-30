#include "src/graphics/window.h"
#include "src/math/maths.h"
#include "src/utils/fileutils.h"
int main()
{
	using namespace engine;
	using namespace graphics;
	using namespace math;
	Window window("Hello", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::string file = read_file("main.cpp");

	std::cout << file << std::endl;

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	while (window.closed() == 0)
	{
		window.clear();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
		window.update();
	}
	return 0;
}