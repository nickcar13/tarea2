#define _USE_MATH_DEFINES

#include "funcionMatematica.h"
#include "Colores.h"
#include <GL/glut.h>
#include <iostream>
#include <math.h>

Colores colorFuncion;

funcionMatematica::funcionMatematica()
{
}

void funcionMatematica::configEjes(float x, float y, float red, float green, float blue)
{
	setEjeX(x);
	setEjeY(y);
	glOrtho(-ejeX, ejeX, -ejeY, ejeY, -1, 1);

	glColor3fv(colorFuncion.RGBToFloat(red, green, blue));

	glBegin(GL_LINES);
	glVertex2d(0, -ejeY);
	glVertex2d(0, ejeY);
	glVertex2d(-ejeX, 0);
	glVertex2d(ejeX, 0);
	glEnd();
}

void funcionMatematica::huevito()
{
	dibujarFuncion(-10, 10, 5, 216, 140, 154, 1);
	dibujarFuncion(-500, 500, 5, 241, 196, 83, 2);
	dibujarFuncion(-500, 500, 5, 229, 107, 111, 3);
}

void funcionMatematica::corazon()
{
	dibujarFuncion(-500, 500, 4, 196, 40, 71, 4);
	dibujarFuncion(-500, 500, 4, 196, 40, 71, 5);
}

void funcionMatematica::dibujarFuncion(float inicio, float final, int pixelSize, float R, float G, float B, int grafica)
{
	glColor3fv(colorFuncion.RGBToFloat(R, G, B));

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
		for (float x = inicio; x < final; x += 0.01)
		{
			y = sqrt(25 - pow(x, 2));
			glVertex2d(x, y);
		}
		break;
	case 3:
		for (float x = inicio; x < final; x += 0.01)
		{
			y = -sqrt(100 - (2 * pow(x, 2)));
			glVertex2d(x, y);
		}
		break;
	case 4:
		for (float x = inicio; x < final; x += 0.01)
		{
			y = (sqrt(1 - pow((abs(x) - 1), 2))) + 10;
			glVertex2d(x, y);
		}
		break;
	case 5:
		for (float x = inicio; x < final; x += 0.01)
		{
			y = (-2.5 * sqrt(1 - (abs(x) / 2))) + 10;
			glVertex2d(x, y);
		}
		break;
	}
	glEnd();
}

void funcionMatematica::configEjes(float x, float y)
{
	setEjeX(x);
	setEjeY(y);

	glOrtho(-ejeX, ejeX, -ejeY, ejeY, -1, 1);

	glColor3fv(colorFuncion.RGBToFloat(255, 255, 255));

	glBegin(GL_LINES);
	glVertex2d(0, -ejeY);
	glVertex2d(0, ejeY);
	glVertex2d(-ejeX, 0);
	glVertex2d(ejeX, 0);
	glEnd();
}

float funcionMatematica::getEjeX()
{
	return ejeX;
}

float funcionMatematica::getEjeY()
{
	return ejeY;
}

void funcionMatematica::setEjeX(float x)
{
	ejeX = x;
}

void funcionMatematica::setEjeY(float y)
{
	ejeY = y;
}
