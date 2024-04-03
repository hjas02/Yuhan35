#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

float moveFactorX = 0.0f;
float moveFactorY = 0.0f;
float scaleFactor = 1.0f;
double x = 0.0;
double y = 0.0;
double x2 = 0.0;
double y2 = 0.0;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void CursorPosition(GLFWwindow* window, double xpos, double ypos)
{
    int L = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    int R = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
    if (L == GLFW_PRESS)//이동
    {
        double t = xpos - x;
        double t2 = y - ypos;
        if (t > 0) //x
        {
            moveFactorX += t * 0.001;
        }
        else if (t < 0)
        {
            moveFactorX += t * 0.001;
        }

        if (t2 > 0)//y
        {
            moveFactorY += t2 * 0.001;
        }
        else if (t2 < 0)
        {
            moveFactorY += t2 * 0.001;
        }
    }

    if (R == GLFW_PRESS) // 확대,축소
    {
        double t = xpos - x;
        if (t > 0) //확대
        {
            scaleFactor += t * 0.00001;
        }
        else if (t < 0) // 축소
        {
            scaleFactor += t * 0.00001;
        }
    }
    else
    {
        x = xpos;
        y = ypos;
    }
}
int render()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.8f + moveFactorX) * scaleFactor, (0.3f + moveFactorY) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((-0.8f + moveFactorX) * scaleFactor, (0.3f + moveFactorY) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.0f + moveFactorX) * scaleFactor, (-0.4f + moveFactorY) * scaleFactor);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.0f + moveFactorX) * scaleFactor, (1.0f + moveFactorY) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((-0.5f + moveFactorX) * scaleFactor, (-0.8f + moveFactorY) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.3f + moveFactorX) * scaleFactor, (-0.3f + moveFactorY) * scaleFactor);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.0f + moveFactorX) * scaleFactor, (1.0f + moveFactorY) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((-0.3f + moveFactorX) * scaleFactor, (-0.3f + moveFactorY) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.5f + moveFactorX) * scaleFactor, (-0.8f + moveFactorY) * scaleFactor);
    glEnd();
    return 0;
}
int main(void)
{
    if (!glfwInit())
        return -1;
    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetCursorPosCallback(window, CursorPosition);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        render();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}