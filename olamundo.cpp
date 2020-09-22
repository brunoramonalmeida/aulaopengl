#include <GL/glut.h>
void mostrarJanela(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP); // Desenhar polígonos
        glVertex2f(0.5, 0.0); // A
        glVertex2f(0.5, 0.5); // B
        glVertex2f(0.0, 0.5); // C
        glVertex2f(0.0, 0.0); // D
        
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    // Callbacks
    glutDisplayFunc(mostrarJanela);
    glutMainLoop();
    return 0;
}