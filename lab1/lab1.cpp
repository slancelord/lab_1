#include <iostream>
#include "glut.h"

class Point {
private:
	float X;
	float Y;
public:
	Point();
	Point(float aX, float aY);
	float getX() const;
	float getY() const;
	void setX(float aX);
	void setY(float aY);
	void draw() const;
};

Point::Point() {
	X = 0;
	Y = 0;
}

Point::Point(float aX, float aY) {
	X = aX;
	Y = aY;
}

float Point::getX() const {
	return X;
}

float Point::getY() const {
	return Y;
}

void Point::setX(float aX) {
	X = aX;
}

void Point::setY(float aY) {
	Y = aY;
}

void Point::draw() const {
	glBegin(GL_POINTS);
	glVertex2f(X, Y);
	glEnd();
}

Point midPoint(Point A, Point B) {
	float y = 1;
	Point mid((A.getX() + B.getX() * y) / (1 + y), (A.getY() + B.getY() * y) / (1 + y));
	return mid;
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	Point T[3] = {
		Point(50, 50),
		Point(325, 600),
		Point(600, 50)
	};
	Point P = midPoint(T[0], T[1]);
	int n = 5000000;
	while (n--) {
		P = midPoint(P, T[rand() % 3]);
		P.draw();
	}

	glFlush();

	// Отправляем на прорисовку
}
void myInit() {
	glClearColor(1, 1, 1, 0);
	//задание цвета фона (белый)
	glColor3f(0, 0, 0);
	// задание цвета рисования (черный)
	glPointSize(1);
	// размер точки
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 640);
	// задание окнной системы координат (Слева снизу начало)

}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	//инициализируем glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//устанавливаем режим дисплея
	glutInitWindowSize(640, 640);
	//устанавливаем размер окна
	glutCreateWindow("OpenGL example");
	//открываем окно на экране
	glutDisplayFunc(myDisplay);
	//регистрируем функцию обратного вызова
	myInit();
	glutMainLoop();
	//входим в бесконечный цикл

}