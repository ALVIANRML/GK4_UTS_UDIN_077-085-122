#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Posisi objek
float x = 0.0f;
float y = 0.0f;

int windowWidth = 1000;
int windowHeight = 600;

// Batasan pergerakan
const float batasAtas = 0.0f;
const float batasBawah = -1.0f;
const float batasKiri = -1.0f;
const float batasKanan = 1.0f;

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

void rumahpertama() {
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.96f, -0.1f);
    glVertex2f(-0.35f, -0.1f);
    glVertex2f(-0.35f, -0.8f);
    glVertex2f(-0.96f, -0.8f);
    glEnd();

    glColor3f(0.5f, 0.25f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.7f, -0.4f);
    glVertex2f(-0.55f, -0.4f);
    glVertex2f(-0.55f, -0.8f);
    glVertex2f(-0.7f, -0.8f);
    glEnd();

    glColor3f(0.7f, 0.85f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(-0.75f, -0.2f);
    glVertex2f(-0.75f, -0.35f);
    glVertex2f(-0.9f, -0.35f);
    glEnd();

    glColor3f(0.6f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(-0.31f, -0.1f);
    glVertex2f(-0.65f, 0.3f);
    glEnd();
}

void rumahkedua() {
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.35f, -0.1f);
    glVertex2f(0.96f, -0.1f);
    glVertex2f(0.96f, -0.8f);
    glVertex2f(0.35f, -0.8f);
    glEnd();

    glColor3f(0.5f, 0.25f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.55f, -0.4f);
    glVertex2f(0.7f, -0.4f);
    glVertex2f(0.7f, -0.8f);
    glVertex2f(0.55f, -0.8f);
    glEnd();

    glColor3f(0.7f, 0.85f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.75f, -0.2f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.9f, -0.35f);
    glVertex2f(0.75f, -0.35f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    renderBitmapString(0.55f, -0.15f, GLUT_BITMAP_HELVETICA_18, "Supermarket");
}

void background() {
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();
}

bool isCollision(float newX, float newY) {
    // Cek apakah posisi baru masuk area rumah pertama
    if (newX > -0.6f && newX < -0.35f && newY < -0.1f && newY > -0.5f) return true;
    // Cek apakah posisi baru masuk area rumah kedua
    if (newX > 0.35f && newX < 0.96f && newY < -0.1f && newY > -0.8f) return true;
    // Cek apakah kaki kanan atau kaki kiri masuk area rumah
    if ((newX > -0.96f && newX < -0.20f && newY < 0.10f && newY < 0.10f) || (newX > 0.35f && newX < 0.96f && newY < -0.3f)) return true;
    // Tidak ada tabrakan
    return false;
}


void handleKeypress(unsigned char key, int xMouse, int yMouse) {
    float moveStep = 0.05f;
    float newX = x;
    float newY = y;

    switch (key) {
    case 'w':
        newY += moveStep;
        break;
    case 's':
        newY -= moveStep;
        break;
    case 'a':
        newX -= moveStep;
        break;
    case 'd':
        newX += moveStep;
        break;
    }

    // Cek batasan layar hijau dan hindari tabrakan dengan rumah dan kaki
    if (newX >= batasKiri && newX <= batasKanan && newY >= batasBawah && newY <= batasAtas && !isCollision(newX, newY)) {
        x = newX;
        y = newY;
        glutPostRedisplay();
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    background();
    rumahpertama();
    rumahkedua();
    rambut();
    kepala();
    badan();
    tangankanan();
    tangankiri();
    kakikanan();
    kakikiri();
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Keyboard Movement Character");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handleKeypress);  // Tambahkan fungsi keyboard

    glutMainLoop();
    return 0;
}
