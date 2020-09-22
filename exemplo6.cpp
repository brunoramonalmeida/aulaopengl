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
    glTranslatef(1.5,1.5,0.0);
    glRotatef(45.0,0.0,0.0,1.0);
    glBegin(GL_POLYGON); // Quadrado
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
    glutInit(&argc, argv); // Inicialização do GLUT
    glutInitDisplayMode(GLUT_SINGLE); // Modo de visualização
    glutInitWindowSize(800, 600); // Tamanho da Janela 
    glutInitWindowPosition(100, 100); // Posição inicial
    glutCreateWindow("Exemplo 4"); // Título da janela
    // Callbacks
    glutDisplayFunc(displayMe);
    // -----
    glutMainLoop(); // Loop principal
    return 0;
}