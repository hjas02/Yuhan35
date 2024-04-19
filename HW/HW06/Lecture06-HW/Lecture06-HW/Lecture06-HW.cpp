#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>

#include "star.hpp"
#include "MSList.cpp"
#include <random>
void errorCallback(int error, const char* description)
{
	std::cerr << "\033[1;31mGLFW Error: " << description << "\033[0m" << std::endl;
}

MSList<star*> starList;

int initialize()
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<float> dist(0.0f, 1.0f);
	std::uniform_real_distribution<float> distX(-0.9f, 0.9f);//(1,1) (-1, -1) 화면끝부분
	std::uniform_real_distribution<float> distY(-0.9f, 0.9f);
	for (int i = 0; i < 300; i++)
	{
		float r = dist(rng);
		float g = dist(rng);
		float b = dist(rng);
		float x = distX(rng);
		float y = distY(rng);
		star* newStar = new star(r, g, b, x, y);
		starList.add(newStar);
	}
	return 0;
}
int release()
{
	for (int i = 0; i < starList.get_size(); ++i) {
		delete starList[i]; 
	}
	return 0;
}

int update()
{
	return 0;
}

int render()
{
	glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < starList.get_size(); i++)
	{
		star* a = starList[i];
		a->render();
	}

	return 0;
}

int main(void)
{
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "GameEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);

	initialize();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		update();
		render();
		glfwSwapBuffers(window);
	}

	release();

	glfwTerminate();
	return 0;

}