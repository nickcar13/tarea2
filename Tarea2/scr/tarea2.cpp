/*Codigo creado por Nicolas Castañeda y Margarita Martinez*/
#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <iostream>
#include <math.h>

#include "class/Ventana.h"

//Declaracion de variables globales
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
void dibujarFuncion(float inicio, float final, int pixelSize, float R, float G, float B, int grafica)
{
	glColor3fv(RGBToFloat(R,G,B));

	//tamaño del punto usado en px
	glPointSize(pixelSize);
	float y;

	glBegin(GL_POINTS);
	switch (grafica) {
	case 1:
		for (float x = inicio; x < final; x += 0.1)
		{
			y = cos(x);
			glVertex2d(x, y);
		}
		break;
	case 2:
		for (float x = inicio; x < final; x+= 0.01)
		{
			y = sqrt(25-pow(x,2));
			glVertex2d(x, y);
		}
		break;
	case 3:
		for (float x = inicio; x < final; x += 0.01)
		{
			y = -sqrt(100-(2 * pow(x, 2)));
			glVertex2d(x, y);
		}
		break;
	case 4:
		for (float x = inicio; x < final; x += 0.01)
		{
			y = (sqrt(1 - pow((abs(x)-1),2) ))+10;
			glVertex2d(x, y);
		}
		break;
	case 5:
		for (float x = inicio; x < final; x += 0.01)
		{
			y = (-2.5*sqrt(1 - (abs(x)/ 2))) +10 ;
			glVertex2d(x, y);
		}
		break;
	}
	glEnd();
}

void huevito() {
	dibujarFuncion(-10, 10, 5, 216, 140, 154, 1);
	dibujarFuncion(-500, 500, 5, 241, 196, 83, 2);
	dibujarFuncion(-500, 500, 5, 229, 107, 111, 3);
}

void corazon() {
	dibujarFuncion(-500, 500, 4, 196, 40, 71, 4);
	dibujarFuncion(-500, 500, 4, 196, 40, 71, 5);
}

//Definicion de la zona que se ve de la grafica dejando 0,0 en el centro
void definirVista(float ejeX, float ejeY)
{
	glOrtho(-ejeX, ejeX, -ejeY, ejeY, -1, 1);
}

int main(int arg, char *argv[])
{
	//Constantes usadas
	float ejeY = 15, ejeX = 25;

	Ventana ventana1(arg, *argv);
	ventana1.bufferSimple("Hello",Display);

	//Inicializacion de las funciones llamadas
	definirVista(ejeX, ejeY); //Campo de vision
	ventana1.configVentana(255, 255, 234); //pantalla con su color
	ejes(17, 19, 68,ejeX,ejeY); //Ejes longitud y color
	huevito(); //funcion con su rango de vision
	corazon();

	ventana1.ciclo();
	return 0;
}