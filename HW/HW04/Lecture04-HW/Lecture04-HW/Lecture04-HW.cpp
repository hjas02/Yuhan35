//과제물 프로젝트명: Lecture04_HW
//idle : 화면색 검정색으로 clear
//마우스 오른쪽 KeyDown하면 : 빨간색
//마우스 오른쪽 KeyUp하면 : 원상복구
//마우스 왼쪽 KeyDown하면 : 녹색
//마우스 왼쪽 KeyUp하면 : 원상복구
//마우스 오른쪽 KeyDown하고 드래그 중이면 : 파랑색
//마우스 왼쪽 KeyDown하고 드래그 중이면 : 마젠타색

#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

bool cursorMoved = false;
bool a, b;
double x = 0.0;
double y = 0.0;

void CursorPosition(GLFWwindow* window, double xpos, double ypos)
{
    int L = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    int R = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);

    cursorMoved = (xpos != x) || (ypos != y);
    x = xpos;
    y = ypos;
    if (!cursorMoved) {
        if (L == GLFW_PRESS)
        {
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        }
        else if (R == GLFW_PRESS)
        {
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        }
    }
    if(cursorMoved)
    {
        if (L == GLFW_PRESS)
        {
            glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        }
        else if (R == GLFW_PRESS)
        {
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        }
    }
}

void MouseButton(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)//좌클릭
    {
        if (action == GLFW_PRESS)
        {
            a = true;
        }
        else if (action == GLFW_RELEASE)
        {
            a = false;
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT)//우클릭
    {
        if (action == GLFW_PRESS)
        {
            b = true;
        }
        else if (action == GLFW_RELEASE)
        {
            b = false;
        }
    }
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "GameEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, CursorPosition);
    glfwSetMouseButtonCallback(window, MouseButton);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        if (cursorMoved)
        {
            if (a) 
            {
                glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
            }
            else if(b)
            {
                glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
            }
            else 
            {
                glClearColor(0.f, 0.f, 0.f, 1.f);
            }
        }
    }
    glfwTerminate();
    return 0;
}