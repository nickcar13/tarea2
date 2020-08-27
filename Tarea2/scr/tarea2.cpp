/*Codigo creado por Nicolas Castañeda y Margarita Martinez*/
#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include "class/Ventana.h"
#include "class/funcionMatematica.h"


void Display()
{
	glFlush();
}

int main(int arg, char *argv[])
{
	//Constantes usadas
	float ejeY = 15, ejeX = 25;

	funcionMatematica funcion; //Objeto encargdo de graficar las funciones
	Ventana ventana1(arg, *argv); //Objeto encargado de la ventana
	ventana1.bufferSimple("Funcion matematica",Display); //creacion de la ventana

	ventana1.configVentana(255, 255, 234); //Configuracion del color dela ventana
	funcion.configEjes(ejeX, ejeY, 17, 19, 68); //color y tamaño de los ejes
	funcion.huevito(); //Grafica del huevo
	funcion.corazon(); //grafica del corazon

	ventana1.ciclo(); //inicia el mainloop

	return 0;
}