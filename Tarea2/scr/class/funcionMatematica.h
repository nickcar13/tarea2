#pragma once
class funcionMatematica
{
public:
	funcionMatematica();
	void configEjes(float x, float y);
	void configEjes(float x, float y, float red, float green,float blue);
	void huevito();
	void corazon();
	
	//Getters y setters
	float getEjeX();
	float getEjeY();
private:

	void dibujarFuncion(float inicio, float final, int pixelSize, float R, float G, float B, int grafica);
	void setEjeX(float x);
	void setEjeY(float y);
	float ejeX = 500, ejeY = 500;
};

