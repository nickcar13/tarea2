#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <iostream>
#include <math.h>
//pyo el que lea
float WIDTH = 500, HEIGHT = 500;
static int RESOLUTIONX = 1366, RESOLUTIONY = 768;
float colors[3] = {};
float ejeY = 1.5, ejeX = 500;

void Display() {
	glFlush();
}

float* RGBToFloat(float red, float green, float blue) {
	red = red / 255;
	green = green / 255;
	blue = blue / 255;

	colors[0] = red;
	colors[1] = green;
	colors[2] = blue;

	return (colors);
}


void pantalla(float red, float green, float blue)
{
	//tama�o del punto usado en px
	glPointSize(5);
	float* ColorFondo = RGBToFloat(red, green, blue);
	//Configuracion del color de borrado o color de fondo
	glClearColor(*ColorFondo, *(ColorFondo + 1), *(ColorFondo + 2), 1);
	//Organizacion de los ejes en funcion de una vista ortogonal

	//limpieza inicial de la pantalla con el color predefinido anteriormente
	glClear(GL_COLOR_BUFFER_BIT);
}

void ejes(float red, float green, float blue) {

	glColor3fv(RGBToFloat(red, green, blue));

	glBegin(GL_LINES);
	glVertex2d(0, -HEIGHT);
	glVertex2d(0, HEIGHT);
	glVertex2d(-WIDTH, 0);
	glVertex2d(WIDTH, 0);
	glEnd();
}

void funcion() {
	glOrtho(-ejeX, ejeX, -ejeY, ejeY, -1, 1);
	float y;
	glBegin(GL_POINTS);
	for (float x = -ejeX; x < ejeX; x += 0.1) {
		y = sin(x * M_PI / 180);
		glVertex2d(x, y);
	}
	glEnd();
}

int main(int arg, char* argv[]) {

	float posX = ((RESOLUTIONX / 2) - (WIDTH / 2));
	float posy = ((RESOLUTIONY / 2) - (HEIGHT / 2) - 40);
	
	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(posX, posy);
	glutCreateWindow("Clase 2");
	glutDisplayFunc(Display);

	pantalla(84, 84, 84);
	ejes(233, 255, 249);
	funcion();
	glutMainLoop();
	return 0;
}