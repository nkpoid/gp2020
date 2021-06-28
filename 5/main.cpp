#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <GL/glut.h>
// #include <OpenGL/OpenGL.h>
// #include <GLUT/GLUT.h>

// GL_LIGHT0
const GLfloat lightPosition0[4] = {5.25, 2.0, 0.25, 1.0};
const GLfloat teapotAmbient0[4] = {0.3, 0.5, 0.0, 1.0};
const GLfloat teapotDiffuse0[4] = {1, 1, 0.3, 1};
const GLfloat teapotSpecular0[4] = {1, 1, 1, 1};
const GLfloat teapotShininess0[1] = {20};

// GL_LIGHT1
const GLfloat lightPosition1[4] = {5.25, 5, 0.25, 1.0};
const GLfloat teapotAmbient1[4] = {0.3, 0.5, 0.0, 1.0};
const GLfloat teapotDiffuse1[4] = {1, 1, 0.3, 1};
const GLfloat teapotSpecular1[4] = {1, 0, 1, 1};
const GLfloat teapotShininess1[1] = {5};

void reshape(int w, int h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30.0, (double)w/h, 1.0, 100.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 3.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display() {
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // glutSolidTeapot(1);
  glutSolidSphere(1, 64, 64);
  glFlush();
}

void setup() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);

  // GL_LIGHT0
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0 , GL_POSITION, lightPosition0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient0);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse0);
  glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular0);
  glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess0);

  // GL_LIGHT1
  glEnable(GL_LIGHT1);
  glLightfv(GL_LIGHT1 , GL_POSITION, lightPosition1);
  glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular1);
  glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess1);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("Hello OpenGL");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);

  setup();

  glutMainLoop();

  return 0;
}
