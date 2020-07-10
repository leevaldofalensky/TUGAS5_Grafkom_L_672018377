#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
const double PI = 3.141592653589793;
int i;

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Lee Valdho Falensky - 672018377");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 1.0, 1.0, 0.0);
    //GLfloat light_position0[] = { 100.0,100.0,-350.0,0.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);

}
void jalan_rumah()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex3f(-20, -9.9, 70.0);
    glVertex3f(20, -9.9, 70.0);
    glVertex3f(20, -9.9, 30.1);
    glVertex3f(-20, -9.9, 30.1);
    glEnd();
    glPopMatrix();
}
void rumah()
{
    glPushMatrix();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, -10.0, 30.0);
    glVertex3f(-30.0, 40.0, 30.0);
    glVertex3f(30.0, 40.0, 30.0);
    glVertex3f(30.0, -10.0, 30.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, -10.0, -60.0);
    glVertex3f(-30.0, 40.0, -60.0);
    glVertex3f(30.0, 40.0, -60.0);
    glVertex3f(30.0, -10.0, -60.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(30.0, 40.0, 30.0);
    glVertex3f(30.0, -10.0, 30.0);
    glVertex3f(30.0, -10.0, -60.0);
    glVertex3f(30.0, 40.0, -60.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-30, 40.0, 30.0);
    glVertex3f(-30, -10.0, 30.0);
    glVertex3f(-30, -10.0, -60.0);
    glVertex3f(-30, 40.0, -60.0);
    glEnd();

    //jendel kanan
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(30.1, 25.0, -25.0);
    glColor3f(1, 1, 1);
    glVertex3f(30.1, 8.0, -25.0);
    glColor3f(255, 215, 0);
    glVertex3f(30.1, 8.0, -45.0);
    glColor3f(255, 215, 0);
    glVertex3f(30.1, 25.0, -45.0);

    glColor3f(1, 1, 1);
    glVertex3f(30.1, 25.0, 15.0); glColor3f(1, 1, 1);
    glVertex3f(30.1, 8.0, 15.0); glColor3f(255, 215, 0);
    glVertex3f(30.1, 8.0, -5.0); glColor3f(255, 215, 0);
    glVertex3f(30.1, 25.0, -5.0);
    glEnd();

    glColor3f(0.1, 0.7, 0.5);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex3f(30.2, 17.0, -25.0);
    glVertex3f(30.2, 17.0, -45.0);
    glVertex3f(30.2, 25.0, -35.0);
    glVertex3f(30.2, 8.0, -35.0);

    glVertex3f(30.2, 15.0, 15.0);
    glVertex3f(30.2, 15.0, -5.0);
    glVertex3f(30.2, 25.0, 5.0);
    glVertex3f(30.2, 8.0, 5.0);
    glEnd();

    //jendela kiri
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-15.1, 13.0, -5.0); glColor3f(1, 1, 1);
    glVertex3f(-15.1, -2.0, -5.0); glColor3f(255, 215, 0);
    glVertex3f(-15.1, -2.0, -20.0); glColor3f(255, 215, 0);
    glVertex3f(-15.1, 13.0, -20.0); glColor3f(1, 1, 1);
    glVertex3f(-15.1, 13.0, 20.0); glColor3f(1, 1, 1);
    glVertex3f(-15.1, -2.0, 20.0); glColor3f(255, 215, 0);
    glVertex3f(-15.1, -2.0, 5.0); glColor3f(255, 215, 0);
    glVertex3f(-15.1, 13.0, 5.0);
    glEnd();

    glColor3f(0.1, 0.7, 0.5);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex3f(-15.2, 5.0, -5.0);
    glVertex3f(-15.2, 5.0, -20.0);
    glVertex3f(-15.2, 13.0, -12.5);
    glVertex3f(-15.2, -2.0, -12.5);
    glVertex3f(-15.2, 5.0, 5.0);
    glVertex3f(-15.2, 5.0, 20.0);
    glVertex3f(-15.2, 13.0, 12.5);
    glVertex3f(-15.2, -2.0, 12.5);
    glEnd();

    //ataskanan
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(-0, 30.0 + 45.0, 45.0);
    glVertex3f(39, -40.0 + 70.0, 40.0);
    glVertex3f(39, -40.0 + 70.0, -65.0);
    glVertex3f(-0, 30.0 + 45.0, -65.0);
    glEnd();

    //ataskiri
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(-0, 30.0 + 45.0, 45.0);
    glVertex3f(-39, -40.0 + 70.0, 40.0);
    glVertex3f(-39, -40.0 + 70.0, -65.0);
    glVertex3f(-0, 30.0 + 45.0, -65.0);
    glEnd();

    //jendela depan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(23.0,25.0,30.1);
    glVertex3f(23.0,5.0,30.1);
    glVertex3f(16.0,5.0,30.1);
    glVertex3f(16.0,25.0,30.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(24.0,26.0,30.1);
    glVertex3f(24.0,4.0,30.1);
    glVertex3f(15.0,4.0,30.1);
    glVertex3f(15.0,26.0,30.1);
    glEnd();

    //jendela depan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-23.0,25.0,30.1);
    glVertex3f(-23.0,5.0,30.1);
    glVertex3f(-16.0,5.0,30.1);
    glVertex3f(-16.0,25.0,30.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(-24.0,26.0,30.1);
    glVertex3f(-24.0,4.0,30.1);
    glVertex3f(-15.0,4.0,30.1);
    glVertex3f(-15.0,26.0,30.1);
    glEnd();

    //awan-awan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-30, 40, 30.0);
    glVertex3f(30, 40, 30.0);
    glVertex3f(30, 40, -60.0);
    glVertex3f(-30, 40, -60.0);
    glEnd();

    //segitiga depan
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 40.0, 30.0);
    glVertex3f(0.0, 75.0, 30.0);
    glVertex3f(30.0, 40.0, 30.0);
    glEnd();

    //segitiga belakang
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 40.0, -60.0);
    glVertex3f(0.0, 75.0, -60.0);
    glVertex3f(30.0, 40.0, -60.0);
    glEnd();


    //lantai
    glBegin(GL_QUADS);
    glColor3ub(211, 211, 211);
    glVertex3f(-30, -9.9, 30.0);
    glVertex3f(30, -9.9, 30.0);
    glVertex3f(30, -9.9, -60.0);
    glVertex3f(-30, -9.9, -60.0);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0, 0.5, 0);
    glVertex3f(-70, -10.0, 70.0);
    glVertex3f(70, -10.0, 70.0);
    glVertex3f(70, -10.0, -72.0);
    glVertex3f(-70, -10.0, -72.0);
    glEnd();

    //lemari
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-30.0, 10.0, 29.0);
    glVertex3f(-20.0, 10.0, 29.0);
    glVertex3f(-20.0, 10.0, 25.0);
    glVertex3f(-30.0, 10.0, 25.0);


    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, -10.0, 29.0);
    glVertex3f(-20.0, -10.0, 29.0);
    glVertex3f(-20.0, -10.0, 25.0);
    glVertex3f(-30.0, -10.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, -10.0, 29.0);
    glVertex3f(-20.0, -10.0, 29.0);
    glVertex3f(-20.0, 10.0, 29.0);
    glVertex3f(-30.0, 10.0, 29.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, -10.0, 25.0);
    glVertex3f(-20.0, -10.0, 25.0);
    glVertex3f(-20.0, 10.0, 25.0);
    glVertex3f(-30.0, 10.0, 25.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, -10.0, 29.0);
    glVertex3f(-20.0, -10.0, 25.0);
    glVertex3f(-20.0, 10.0, 25.0);
    glVertex3f(-20.0, 10.0, 29.0);
    glEnd();

    //bingkai lukisan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-10.0, 0.0, -59.0);
    glVertex3f(-10.0, 10.0, -59.0);
    glVertex3f(15.0, 10.0, -59.0);
    glVertex3f(15.0, 0.0, -59.0);
    glEnd();

    //jam kotak
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0, 20.0, -59.0);
    glVertex3f(0.0, 25.0, -59.0);
    glVertex3f(5.0, 25.0, -59.0);
    glVertex3f(5.0, 20.0, -59.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glLineWidth(5);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(2.5, 22.5, -58.9);
    glVertex3f(2.5, 22.5, -58.9);
    glVertex3f(5.0, 25.0, -58.9);
    glEnd();

    //kasur
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-30.0, 0.0, -60.0);
    glVertex3f(-15.0, 0.0, -60.0);
    glVertex3f(-15.0, 0.0, -40.0);
    glVertex3f(-30.0, 0.0, -40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-15.0, 0.0, -40.0);
    glVertex3f(-30.0, 0.0, -40.0);
    glVertex3f(-30.0, -10.0, -40.0);
    glVertex3f(-15.0, -10.0, -40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-15.0, 0.0, -40.0);
    glVertex3f(-15.0, -10.0, -40.0);
    glVertex3f(-15.0, -10.0, -60.0);
    glVertex3f(-15.0, 0.0, -60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-29.9, 0.0, -40.0);
    glVertex3f(-29.9, -10.0, -40.0);
    glVertex3f(-29.9, -10.0, -60.0);
    glVertex3f(-29.9, 0.0, -60.0);
    glEnd();

    //tv
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(29.9, 20.0, -9.0);
    glVertex3f(29.9, 10.0, -9.0);
    glVertex3f(29.9, 10.0, -20.0);
    glVertex3f(29.9, 20.0, -20.0);
    glEnd();

    glPopMatrix();
}
void pintu()
{
    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.0f, 0.0f);
    glVertex3f(-10.0, -10.0, 30.1);
    glVertex3f(-10.0, 20.0, 30.1);
    glVertex3f(10.0, 20.0, 30.1);
    glVertex3f(10.0, -10.0, 30.1);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_POINTS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glVertex3f(-7.0, 3.0, 30.3);
    glEnd();
}
void tampil(void)
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(0.0f, 3.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 0, 1, 0);
    glRotatef(yrot, 1, 0, 0);
    rumah();
    pintu();
    jalan_rumah();
    glEnd();
    glPopMatrix();
    glutSwapBuffers();

}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
	case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case 'q':
    case 'Q':

        break;
	case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
	case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6'://putar kanan
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4'://putar kiri
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();

}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = xrot = x;
        ydiff = yrot = y;
    }
    else {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        xrot = x;
        yrot = y;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
