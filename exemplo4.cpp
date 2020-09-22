#include <GL/glut.h>
 
void displayMe(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // limpar
    gluOrtho2D(-10, 10, -10, 10); // define um plano de visualização
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES); // EIXO Y
        glColor3f(1.0,1.0,1.0);
        glVertex2f(0.0, -10.0);
        glVertex2f(0.0, 10.0);
    glEnd();
    glBegin(GL_LINES); // EIXO Y
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-10.0, 0);
        glVertex2f(10.0, 0);
    glEnd();
    glBegin(GL_POLYGON); // Desenhar polígonos
        glColor3f(0.0,1.0,0.0);
        glVertex2f(2.0, 0.0);
        glVertex2f(2.0, 2.0);
        glVertex2f(0.0, 2.0);
        glVertex2f(0.0, 0.0);
    glEnd();
    glBegin(GL_POLYGON); // Desenhar polígonos
        glColor3f(0.0,1.0,0.0);
        glVertex2f(2.0, 0.0);
        glVertex2f(2.0, 2.0);
        glVertex2f(0.0, 2.0);
        glVertex2f(0.0, 0.0);
    glEnd();
    glFlush();
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exemplo 4");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}