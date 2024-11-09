#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
void rambut() {

}

void kepala() {
	glBegin(GL_POLYGON);
	for (float angle = 0.0; angle < 2.0 * M_PI; angle += 0.01) {
		float x = 0.2 * cos(angle); // Lebar kepala
		float y = 0.3 * sin(angle); // Tinggi kepala
		glVertex2f(x, y);
	}
	glEnd();
}

void hidung() {

}

void rambut() {

}

void rambut() {

}

void rambut() {

}


int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Sphere - Side View");

	glEnable(GL_DEPTH_TEST);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutMainLoop();

	return 0;
}