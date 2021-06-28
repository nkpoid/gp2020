#include <iostream>
#include <GL/glut.h>
// #include <OpenGL/OpenGL.h>
// #include <GLUT/GLUT.h>

void display() {
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
    glColor3f(0, 0.5, 1);
    glVertex2f(0, 0.5);
    glColor3f(1, 0, 0);
    glVertex2f(0.5, -0.5);
    glColor3f(0, 1, 1);
    glVertex2f(-0.5, -0.5);
  glEnd();

  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(500, 500);

  glutCreateWindow("Hello OpenGL");
  glutInitDisplayMode(GLUT_RGBA);
  glClearColor(1, 1, 1, 1);

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
