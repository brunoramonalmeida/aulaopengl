#include <GL/glut.h>
 
GLfloat objX = 0.0f;
GLfloat objY = 0.0f;

// GLfloat velocidade = 0.5f;

void desenhaQuadrado() {
    glBegin(GL_POLYGON); // Quadrado
        glColor3f(0.0,1.0,0.0);
        glVertex2f(2.0, 0.0);
        glVertex2f(2.0, 2.0);
        glVertex2f(0.0, 2.0);
        glVertex2f(0.0, 0.0);
    glEnd();
}

void moverObjeto(GLfloat x, GLfloat y) {
    objX += x;
    objY += y;
}

void teclado(unsigned char key, int x, int y)
{
    switch (key) {
            case 'a':
                moverObjeto(-0.5,0.0);
                     break;
            case 's':
                moverObjeto(0.0,-0.5);
                     break;
            case 'd':
                moverObjeto(0.5,0.0);
                     break;
            case 'w':
                moverObjeto(0.0,0.5);
                     break;
            // case 'p':
            //     velocidade += 0.5f;
            //     break;
            // case 'o':
            //     velocidade -= 0.5f;
            //     break;                
    }
    glutPostRedisplay();
}

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
    glPushMatrix(); 
        glTranslatef(objX,objY,0.0);
        desenhaQuadrado();
    glPopMatrix();
    glFlush();
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Inicialização do GLUT
    glutInitDisplayMode(GLUT_SINGLE); // Modo de visualização
    glutInitWindowSize(800, 600); // Tamanho da Janela 
    glutInitWindowPosition(100, 100); // Posição inicial
    glutCreateWindow("Exemplo 7"); // Título da janela
    // Callbacks
    glutDisplayFunc(displayMe);
    glutKeyboardFunc(teclado); // Registro de callback de teclado
    // -----
    glutMainLoop(); // Loop principal
    return 0;
}