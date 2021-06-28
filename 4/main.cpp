#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <GL/glut.h>
// #include <OpenGL/OpenGL.h>
// #include <GLUT/GLUT.h>

void reshape(int w, int h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30.0, (double)w/h, 1.0, 100.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 5.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

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

  glutWireTeapot(1.0);
  glutWireCube(2.0);
  glutWireSphere(3, 10, 10);
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

  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
