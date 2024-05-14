#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

float a = 0;
float e = 0;
float e2 = 0;
float sun = 0;
int setVertexRotation(float x, float y, float angle_degree, float sX , float sY ,float s)
{
	float M_PI = 3.14f;
	float angle = angle_degree / 180 * M_PI;

	// 공전 적용
	float rotatedX = x * cos(angle) - y * sin(angle) + sX;
	float rotatedY = x * sin(angle) + y * cos(angle) + sY;

	// 자전 적용
	float finalX = rotatedX * cos(s) - rotatedY * sin(s);
	float finalY = rotatedX * sin(s) + rotatedY * cos(s);

	glVertex2f(finalX, finalY);
	return 0;
}

void drawFirstCircle() {
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.85f, 0.4f); // 원의 내부 색상 설정
	glVertex2f(0, 0); 

	// 원의 점 추가
	for (int i = 0; i <= 360; i++) {
		float angle = i * 3.14f / 180;
		float x = 0.5f * cos(angle); 
		float y = 0.5f * sin(angle);

		
		setVertexRotation(x, y, angle, 0, 0,sun);
	}
	glEnd();

	glLineWidth(5.0f); 
	glColor3f(1.0f, 0.5f, 0.0f); 
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= 360; i += 10) {
		float angle = i * 3.14f / 180;
		float x = 0.5f * cos(angle); 
		float y = 0.5f * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
}

void drawSecondCircle() {
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1, 0.4f);

	
	for (int i = 0; i <= 361; i++) {
		float angle = i * 3.14 / 180;
		float x = (0.2f * cos(angle) ); 
		float y = 0.2f * sin(angle);

		
		setVertexRotation(x, y, angle, -0.25f, 0, sun);
	}
	glEnd();
}

void drawThirdCircle() {
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.7f, 0.0f);

	for (int i = 0; i <= 361; i++) {
		float angle = i * 3.14f / 180;
		float x = (0.05f * cos(angle));
		float y = (0.2f * sin(angle));
		float rotated_x = x * cos(-45 * 3.14 / 180) - y * sin(-45 * 3.14 / 180);
		float rotated_y = x * sin(-45 * 3.14 / 180) + y * cos(-45 * 3.14 / 180);
	
		setVertexRotation(rotated_x, rotated_y, angle, 0.25f, -0.25f, sun);
	}
	glEnd();
}
// 직사각형
void drawRectangleWithOutline(float width, float height, float angle_degree, float sX, float sY, float s) {
	// 직사각형 그리기
	glBegin(GL_QUADS);
	glColor3f(91 / 255.0f, 155 / 255.0f, 213 / 255.0f);

	// 좌상단
	setVertexRotation(-width / 2, height / 2, angle_degree, sX, sY, s);
	// 우상단
	setVertexRotation(width / 2, height / 2, angle_degree, sX, sY, s);
	// 우하단
	setVertexRotation(width / 2, -height / 2, angle_degree, sX, sY, s);
	// 좌하단
	setVertexRotation(-width / 2, -height / 2, angle_degree, sX, sY, s);
	glEnd();

	// 아웃라인 그리기
	glLineWidth(2.0f); 
	glColor3f(0.0f, 0.0f, 0.0f); 
	glBegin(GL_LINE_LOOP);

	setVertexRotation(-width / 2, height / 2, angle_degree, sX, sY, s);
	setVertexRotation(width / 2, height / 2, angle_degree, sX, sY, s);

	setVertexRotation(width / 2, height / 2, angle_degree, sX, sY, s);
	setVertexRotation(width / 2, -height / 2, angle_degree, sX, sY, s);

	setVertexRotation(width / 2, -height / 2, angle_degree, sX, sY, s);
	setVertexRotation(-width / 2, -height / 2, angle_degree, sX, sY, s);

	setVertexRotation(-width / 2, -height / 2, angle_degree, sX, sY, s);
	setVertexRotation(-width / 2, height / 2, angle_degree, sX, sY, s);
	glEnd();
}

float angle = 0;
int render()
{
	a += (2 * 3.14) / (60 * 3); //별
	sun += (2 * 3.14) / (60 * 30); //태양
	e +=(2 * 3.14) / (60 * 60); //지구 공전
	e2 += (2 * 3.14) / (60 * 10);//지구 자전

	// 중앙 원
	drawFirstCircle();

	//2
	drawSecondCircle();

	//3
	drawThirdCircle();

	//직사각형
	drawRectangleWithOutline(0.2f, 0.2f, e2, 0.8f, 0.0f, e);
	// 직사각형 위치 계산 (공전 중심)
	float rectCenterX = 0.8f * cos(e);
	float rectCenterY = 0.8f * sin(e);
	// 별의 위치 계산 (직사각형을 중심으로 공전)
	float starOrbitX = rectCenterX + 0.3f * cos(a); // 공전 반지름을 필요에 맞게 조정
	float starOrbitY = rectCenterY + 0.3f * sin(a); // 공전 반지름을 필요에 맞게 조정
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 1.0f, 0.0f); // 노란색

	setVertexRotation(0.0f, 0.0f, 0, starOrbitX, starOrbitY, 0);
	for (int i = 0; i < 360; i = i + 72)
	{
		setVertexRotation(0.1, 0, i + angle, starOrbitX, starOrbitY, 0);
		setVertexRotation(0.05f, 0, i + 36 + angle, starOrbitX, starOrbitY, 0);
	}
	setVertexRotation(0.1f, 0.0f, angle, starOrbitX, starOrbitY, 0);

	glEnd();

	angle += 1;

	glLineWidth(1.5f);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // 검은색

	for (int i = 0; i < 360; i = i + 72)
	{
		setVertexRotation(0.05f, 0.0f, i - 36 + angle, starOrbitX, starOrbitY, 0);
		setVertexRotation(0.1f, 0.0f, i + angle, starOrbitX, starOrbitY, 0); 

		setVertexRotation(0.1f, 0.0f, i + angle, starOrbitX, starOrbitY, 0);
		setVertexRotation(0.05f, 0.0f, i + 36 + angle, starOrbitX, starOrbitY, 0);
	}
	glEnd();
	return 0;
}

int main(void)
{
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(800, 800, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	double lastTime = glfwGetTime();
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);

	while (!glfwWindowShouldClose(window))
	{
		double currentTime = glfwGetTime();
		double deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		glfwPollEvents();
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		render();
		
		glfwSwapBuffers(window);
	}

	
	glfwTerminate();
	return 0;

}