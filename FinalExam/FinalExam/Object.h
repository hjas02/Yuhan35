#pragma once
#include <GLFW/glfw3.h>

// Base class
class Object {
public:
    float x, y, width, height;
    float r, g, b;
    float r2, g2, b2;

    Object(float x, float y, float width, float height, float r, float g, float b, float r2, float g2, float b2)
        : x(x), y(y), width(width), height(height), r(r), g(g), b(b), r2(r2), g2(g2), b2(b2) {}

    void draw() const {
        glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex2f(x - width, y - height);
        glVertex2f(x + width, y - height);
        glVertex2f(x + width, y + height);
        glVertex2f(x - width, y + height);
        glEnd();
        glLineWidth(2.0f);
        glColor3f(r2, g2, b2);
        glBegin(GL_LINE_LOOP);

        glVertex2f(x - width, y - height);
        glVertex2f(x + width, y - height);
        glVertex2f(x + width, y + height);
        glVertex2f(x - width, y + height);

        glEnd();
    }

    virtual void OnCollisionEnter(Object& other) {
    }
};

// Derived classes
class Player : public Object {
public:
    Player(float x, float y)
        : Object(x, y, 0.0625, 0.0825, 1.0f, 0.0f, 0.0f , 0,1,0) {}

    void OnCollisionEnter(Object& other) override {
    }
};


class EnemyBlock : public Object {
public:
    EnemyBlock(float x, float y , float h)
        : Object(x, y, 0.0625, h, 0.0f, 1.0f, 0.0f , 0.0f, 1.0f, 0.0f) {}
    void OnCollisionEnter(Object& other) override {
    }
};

class Floor : public Object {
public:
    Floor(float x, float y)
        : Object(x, y, 1.0f, 0.1f, 1.0f, 0.784f, 0.059f, 1.0f, 0.784f, 0.059f) {}

    void OnCollisionEnter(Object& other) override {
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
};

int PhysicsAABB(Object A, Object B) {
    float left1 = A.x - A.width;
    float right1 = A.x + A.width;
    float bottom1 = A.y - A.height;
    float top1 = A.y + A.height;

    float left2 = B.x - B.width;
    float right2 = B.x + B.width;
    float bottom2 = B.y - B.height;
    float top2 = B.y + B.height;

    if (left1 > right2 || right1 < left2 || top1 < bottom2 || bottom1 > top2)
        return 0; 
    else
        return 1; //Ãæµ¹
}
