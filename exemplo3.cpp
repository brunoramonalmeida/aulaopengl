#include <GL/glut.h>
 
void displayMe(void)
{
    gluOrtho2D(-400, 400, -400, 400);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON); // Desenhar polígonos
        glColor3f(1.0,1.0,0.0);
        glVertex2f(20, 0.0);
        glVertex2f(20, 20);
        glVertex2f(0.0, 20);
        glVertex2f(0.0, 0.0);
    glEnd();
    glFlush();
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exemplo 3");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}