#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Posisi objek
float x = 0.0f;
float y = 0.0f;

int windowWidth = 1000;
int windowHeight = 600;


// Fungsi untuk menampilkan string
void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string);
        string++;
    }
}

void rambut() {
    glColor3f(0.0f, 0.1f, 0.1f);  // Warna rambut (hitam)
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.1f, y + 0.2f);
    glVertex2f(x + 0.1f, y + 0.2f);
    glVertex2f(x, y + 0.3f);
    glEnd();
}

void mata() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (float angle = 0.0f; angle < 2.0f * M_PI; angle += 0.1f) {
        float mx = 0.02f * cos(angle) + x - 0.05f;
        float my = 0.02f * sin(angle) + y + 0.15f;
        glVertex2f(mx, my);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (float angle = 0.0f; angle < 2.0f * M_PI; angle += 0.1f) {
        float mx = 0.02f * cos(angle) + x + 0.05f;
        float my = 0.02f * sin(angle) + y + 0.15f;
        glVertex2f(mx, my);
    }
    glEnd();
}

void badan() {
    glColor3f(0.0f, 0.0f, 0.6f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x - 0.1f, y - 0.005f);
    glVertex2f(x + 0.1f, y - 0.005f);
    glVertex2f(x + 0.1f, y - 0.3f);
    glVertex2f(x - 0.1f, y - 0.3f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.1f, y - 0.005f);
    glVertex2f(x + 0.1f, y - 0.005f);
    glVertex2f(x + 0.1f, y - 0.3f);
    glVertex2f(x - 0.1f, y - 0.3f);
    glEnd();
}

void tangankanan() {
    glColor3f(0.0f, 0.0f, 0.6f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x + 0.1f, y - 0.005f);
    glVertex2f(x + 0.2f, y - 0.2f);
    glVertex2f(x + 0.15f, y - 0.25f);
    glVertex2f(x + 0.1f, y - 0.1f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.1f, y - 0.005f);
    glVertex2f(x + 0.2f, y - 0.2f);
    glVertex2f(x + 0.15f, y - 0.25f);
    glVertex2f(x + 0.1f, y - 0.1f);
    glEnd();
}

void tangankiri() {
    glColor3f(0.0f, 0.0f, 0.6f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x - 0.1f, y - 0.005f);
    glVertex2f(x - 0.2f, y - 0.2f);
    glVertex2f(x - 0.15f, y - 0.25f);
    glVertex2f(x - 0.1f, y - 0.1f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.1f, y - 0.005f);
    glVertex2f(x - 0.2f, y - 0.2f);
    glVertex2f(x - 0.15f, y - 0.25f);
    glVertex2f(x - 0.1f, y - 0.1f);
    glEnd();
}

void kakikanan() {
    glColor3f(0.6f, 0.0f, 0.0f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x + 0.1f, y - 0.3f);
    glVertex2f(x + 0.1f, y - 0.5f);
    glVertex2f(x + 0.005f, y - 0.5f);
    glVertex2f(x + 0.0f, y - 0.3f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.1f, y - 0.3f);
    glVertex2f(x + 0.1f, y - 0.5f);
    glVertex2f(x + 0.005f, y - 0.5f);
    glVertex2f(x + 0.0f, y - 0.3f);
    glEnd();
}

void kakikiri() {
    glColor3f(0.6f, 0.0f, 0.0f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x - 0.0f, y - 0.3f);
    glVertex2f(x - 0.1f, y - 0.3f);
    glVertex2f(x - 0.1f, y - 0.5f);
    glVertex2f(x + 0.0f, y - 0.5f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.0f, y - 0.3f);
    glVertex2f(x - 0.1f, y - 0.3f);
    glVertex2f(x - 0.1f, y - 0.5f);
    glVertex2f(x + 0.0f, y - 0.5f);
    glEnd();
}

void mulut() {
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(x - 0.05f, y + 0.05f);
    glVertex2f(x + 0.05f, y + 0.05f);
    glEnd();
}

void kepala() {
    glColor3f(1.0f, 0.98f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.1f, y + 0.2f);
    glVertex2f(x + 0.1f, y + 0.2f);
    glVertex2f(x + 0.1f, y - 0.005f);
    glVertex2f(x - 0.1f, y - 0.005f);
    glEnd();

    mata();
    mulut();
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