#include <GL/glut.h>

void display();

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(100, 200);
	glutInitWindowSize(300, 300);

	glutCreateWindow("OpenGL 3D View");

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
    //x,y的範圍皆為-1~1之間
	glVertex3f(0,0,0);
	glVertex3f(0.1,0,0);
	glVertex3f(0.2,0,0);
	glEnd();

	glFlush();
}

