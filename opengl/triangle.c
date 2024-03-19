#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // RED

    glBegin(GL_TRIANGLES);    // Begin drawing the triangle
    glColor3f(1.0, 0.0, 0.0); // Set color to red
    glVertex2f(-0.5, -0.5);   // Define vertex 1
    glColor3f(0.0, 1.0, 0.0); // Set color to green
    glVertex2f(0.5, -0.5);    // Define vertex 2
    glColor3f(0.0, 0.0, 1.0); // Set color to blue
    glVertex2f(0.0, 0.5);     // Define vertex 3
    glEnd();                  

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(640, 480);
    glutCreateWindow("Triangle");

    // Display callback function
    glutDisplayFunc(display);

    // main glut loop that handles events
    glutMainLoop();

    return 0;
}