#include <GL/glut.h>

float WIDTH = 500, HEIGHT = 500;
static int RESOLUTIONX = 1366, RESOLUTIONY = 768;
float colors[3] = {};

void Display() {
	glFlush();
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

	return 0;
}