#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <iostream>
#include <math.h>
//Declaracion de variables globales

float WIDTH = 500, HEIGHT = 500;
static int RESOLUTIONX = 1366, RESOLUTIONY = 768;
float colors[3] = {};


void Display()
{
	glFlush();
}

float *RGBToFloat(float red, float green, float blue)
{
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
	float *ColorFondo = RGBToFloat(red, green, blue);
	//Configuracion del color de borrado o color de fondo
	glClearColor(*ColorFondo, *(ColorFondo + 1), *(ColorFondo + 2), 1);
	//Organizacion de los ejes en Funcion de una vista ortogonal

	//limpieza inicial de la pantalla con el color predefinido anteriormente
	glClear(GL_COLOR_BUFFER_BIT);
}

//graficacion de los ejes color y longitud
void ejes(float red, float green, float blue, float ejeX, float ejeY)
{
	glColor3fv(RGBToFloat(red, green, blue));

	glBegin(GL_LINES);
	glVertex2d(0, -ejeY);
	glVertex2d(0, ejeY);
	glVertex2d(-ejeX, 0);
	glVertex2d(ejeX, 0);
	glEnd();
}

//Graficacion de la funcion en el rango indicado
void dibujarFuncion(float inicio, float final)
{

	//tamaño del punto usado en px
	glPointSize(5);
	float y;

	glBegin(GL_POINTS);
	for (float x = inicio; x < final; x += 0.1)
	{
		y = sin(x * M_PI / 180);
		glVertex2d(x, y);
	}
	glEnd();
}

//Definicion de la zona que se ve de la grafica dejando 0,0 en el centro
void definirVista(float ejeX, float ejeY)
{
	glOrtho(-ejeX, ejeX, -ejeY, ejeY, -1, 1);
}

int main(int arg, char *argv[])
{
	//Constantes usadas
	float ejeY = 1.5, ejeX = 500;

	float posX = ((RESOLUTIONX / 2) - (WIDTH / 2));
	float posy = ((RESOLUTIONY / 2) - (HEIGHT / 2) - 40);

	//Definicion de la pantalla
	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(posX, posy);
	glutCreateWindow("Clase 2");
	glutDisplayFunc(Display);

	//Inicializacion de las funciones llamadas
	definirVista(ejeX, ejeY); //Campo de vision
	pantalla(84, 84, 84); //pantalla con su color
	ejes(233, 255, 249,ejeX,ejeY); //Ejes longitud y color
	dibujarFuncion(-500, 500); //funcion con su rango de vision
	glutMainLoop(); //Loop iniciado del main para glut  
	return 0;
}