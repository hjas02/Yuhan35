#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <thread>
/*
  화면 800x800(-1.0f ~ 1.0f)
  1M : 1.0f =  400px / 0.1f = 40px 
  0.0025f = 1px
   
   중력가속도 = 9.8 
   60fps = 9.8 / 60  (0.1633)

*/
class Rectangle {
public:
    float x, y, width, height;
    float r, g, b;
    float r2, g2, b2;

    Rectangle(float x, float y, float width, float height, float r, float g, float b, float r2, float g2, float b2)
        : x(x), y(y), width(width), height(height), r(r), g(g), b(b), r2(r2), g2(g2), b2(b2) {}

    void draw() const {
        // 사각형 그리기
        glBegin(GL_QUADS);
        glColor3f(r, g, b);

        glVertex2f(x - width, y - height);
        glVertex2f(x + width, y - height);
        glVertex2f(x + width, y + height);
        glVertex2f(x - width, y + height);

        glEnd();

        // 아웃라인 그리기
        glLineWidth(2.0f);
        glColor3f(r2, g2, b2);
        glBegin(GL_LINE_LOOP);

        glVertex2f(x - width, y - height);
        glVertex2f(x + width, y - height);
        glVertex2f(x + width, y + height);
        glVertex2f(x - width, y + height);

        glEnd();
    }

    bool checkCollision(const Rectangle& other) const {
        float left1 = x - width;
        float right1 = x + width;
        float bottom1 = y - height;
        float top1 = y + height;

        float left2 = other.x - other.width;
        float right2 = other.x + other.width;
        float bottom2 = other.y - other.height;
        float top2 = other.y + other.height;

        return !(left1 > right2 || right1 < left2 || top1 < bottom2 || bottom1 > top2);
    }
};

class Game {
private:
    GLFWwindow* window;
    Rectangle player;
    Rectangle land;
    double speed;
    double gravity;

public:
    Game()
        : window(nullptr),
        player(0.0, 0.0, 0.1, 0.1, 1, 0, 0, 0, 1, 0), //플레이어 1M 정사각형
        land(0.0, -0.8, 2.0, 0.1, 0, 0, 1, 0, 1, 0),
        speed(0), gravity(9.8 / 60) {}

    void init() {
        if (!glfwInit()) {
            std::cerr << "GLFW initialization failed!" << std::endl;
            exit(EXIT_FAILURE);
        }

        glfwSetErrorCallback(errorCallback);

        window = glfwCreateWindow(800, 800, "MuSoeunEngine", NULL, NULL);  
        if (!window) {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);
        glfwSetKeyCallback(window, keyCallback);
        glfwSetWindowUserPointer(window, this);
    }

    void run() {
        const int fps = 60;
        const std::chrono::milliseconds frame_duration(1000 / fps);

        while (!glfwWindowShouldClose(window)) {
            auto start_time = std::chrono::steady_clock::now();

            glClear(GL_COLOR_BUFFER_BIT);

            render();

            glfwSwapBuffers(window);
            glfwPollEvents();

            auto end_time = std::chrono::steady_clock::now();
            auto elapsed = end_time - start_time;
            auto sleep_duration = frame_duration - elapsed;

            if (sleep_duration > std::chrono::milliseconds::zero()) {
                std::this_thread::sleep_for(sleep_duration);
            }
        }

        glfwDestroyWindow(window);
        glfwTerminate();
    }

    static void errorCallback(int error, const char* description) {
        std::cerr << "GLFW Error: " << description << std::endl;
    }

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));

        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
        if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
            game->player.y += 0.5f ;
        }
        if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
            game->player.x += 0.1f;
        }
        if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
            game->player.x -= 0.1f;
        }
    }

    void render() {
        player.draw();
        land.draw();
        std::cout << speed << std::endl;
        if (!player.checkCollision(land)) {
            speed -= gravity;
            player.y += speed;
        }
        else {
            speed = 0;
        }
    }
};

int main() {
    Game game;
    game.init();
    game.run();

    return 0;
}
