#include <GL/glut.h>

GLfloat objX = 0.0f;
GLfloat objY = 0.0f;
GLfloat scX = 1.0f;
GLfloat scY = 1.0f;

GLfloat angulo = 0.0f;
GLfloat rotateX = 0.0f;
GLfloat rotateY = 1.0f;
GLfloat rotateZ = 0.0f;

GLfloat xstep = 0.2f;
GLfloat ystep = 0.2f;

GLfloat windowWidth;
GLfloat windowHeight;

void Timer(int value)
{
    if (objX < -10 || objX > 10)
        xstep = -xstep;
    objX += xstep;
        

    // objY += ystep;

    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);
}


void desenhaQuadrado()
{
    glBegin(GL_POLYGON); // Quadrado
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(2.0, 0.0);
    glVertex2f(2.0, 2.0);
    glVertex2f(0.0, 2.0);
    glVertex2f(0.0, 0.0);
    glEnd();
}

void moverObjeto(GLfloat x, GLfloat y)
{
    objX += x;
    objY += y;
}

void abertura(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // askjdajsk
    glFlush();
}

void displayMe(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();             // limpar
    gluOrtho2D(-10, 10, -10, 10); // define um plano de visualização
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES); // EIXO Y
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.0, -10.0);
    glVertex2f(0.0, 10.0);
    glEnd();
    glBegin(GL_LINES); // EIXO Y
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-10.0, 0);
    glVertex2f(10.0, 0);
    glEnd();
    glPushMatrix();
    glTranslatef(objX, objY, 0.0);
    glRotatef(angulo, rotateX, rotateY, rotateZ);
    glScalef(scX, scY, 0.0);
    desenhaQuadrado();
    glPopMatrix();
    glFlush();
}

void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        moverObjeto(-0.5, 0.0);
        break;
    case 's':
        moverObjeto(0.0, -0.5);
        break;
    case 'd':
        moverObjeto(0.5, 0.0);
        break;
    case 'w':
        moverObjeto(0.0, 0.5);
        break;
    case 'r':
        angulo += 5.0f;
        break;
    case 'x':
        glutDisplayFunc(displayMe);
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

void tecladoEspecial(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_PAGE_UP:
            scX += 1.1;
            scY += 1.1;
        break;
        case GLUT_KEY_PAGE_DOWN:
            scX -= 1.1;
            scY -= 1.1;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);            // Inicialização do GLUT
    glutInitDisplayMode(GLUT_SINGLE); // Modo de visualização
    glutInitWindowSize(800, 600);     // Tamanho da Janela
    glutInitWindowPosition(100, 100); // Posição inicial
    glutCreateWindow("Exemplo 10");    // Título da janela
    // Callbacks
    glutDisplayFunc(abertura);
    glutKeyboardFunc(teclado);        // Registro de callback de teclado
    glutSpecialFunc(tecladoEspecial); // Registro de callback de teclado
    glutTimerFunc(33, Timer, 1);      // Registro de callback de animação
    // -----
    glutMainLoop(); // Loop principal
    return 0;
}