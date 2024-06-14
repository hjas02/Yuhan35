#pragma comment(lib, "Opengl32.lib")

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "Object.h"
//#include "Transform.cpp"
void errorCallback(int error, const char* description)
{
    printf("GLFW Error: %s\n", description);
}

Player player(0.0f, 0.0f);
EnemyBlock enemy(0.3f, 0.0f, 0.165);
EnemyBlock enemy2(0.7f, 0.0f,0.55);

Floor floor1(0, -0.495f);

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}

int Physics()
{
    return 0;
}

int Initialize()
{
    return 0;
}

int Update()
{
    
    return 0;
}

int Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Player 렌더링
    player.draw();
    // EnemyBlock 렌더링
    enemy.draw();
    enemy2.draw();
    // Floor 렌더링
    floor1.draw();
    return 0;
}

int main(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    Initialize();

    glClearColor(0.0f, 0.12f, 0.39f, 1.0f);
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        Physics();
        Update();
        Render();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
