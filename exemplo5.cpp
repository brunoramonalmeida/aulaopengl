#include <GL/glut.h>

GLfloat t;

void teclado(unsigned char key, int x, int y)
{
    switch (key) {
            case 'r':
                     glColor3f(1.0, 0.0, 0.0); // Vermelho
                     break;
            case 'g':
                     glColor3f(0.0, 1.0, 0.0); // Verde
                     break;
            case 'b':
                     glColor3f(0.0, 0.0, 1.0); // Azul
                     break;
    }
    glutPostRedisplay();
}

void especiais(int key, int x, int y)
{
    if(key == GLUT_KEY_UP) {
           t += 5;
    }
    if(key == GLUT_KEY_DOWN) {
           t -= 5;
    }
    glutPostRedisplay();
}
 
void displayMe(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // limpar
    gluOrtho2D(-100, 100, -100, 100);
    
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON); // Desenhar polígonos
        glVertex2f(t+1.0, 0.0);
        glVertex2f(t+1.0, t+1.0);
        glVertex2f(0.0, t+1.0);
        glVertex2f(0.0, 0.0);
    glEnd();
    glFlush();
}

void Inicializa (void)
{   
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    t = 1.0f;
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exemplo 4");
    // Registro das Callbacks
    glutDisplayFunc(displayMe);
    glutKeyboardFunc(teclado); // Registro de callback de teclado
    glutSpecialFunc(especiais); // Registro de teclas especiais  

    Inicializa();
    glutMainLoop();
    return 0;
}