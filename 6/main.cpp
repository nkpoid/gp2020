#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <GL/glut.h>
// #include <OpenGL/OpenGL.h>
// #include <GLUT/GLUT.h>

float rotation = 0;

void setup() {
  // LIGHTING
  float lightPosition[4] = {5.25, 2, 0.25, 1};
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

  // MATERIAL
  float ambient[4] = {5.25, 0.5, 0, 1};
  float diffuse[4] = {1, 1, 0.3, 1};
  float specular[4] = {1, 1, 1, 1};
  float shininess[1] = {20.0f};
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, (double)w / h, 0.1, 100);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 3, 13, 0, 0, 0, 0, 1, 0);
}

void display() {
  glEnable(GL_DEPTH_TEST);
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
  {
    glRotatef(rotation, 1, 1, 1);
    glutSolidTorus(1, 3, 64, 64);
  }
  glPopMatrix();

  glutSwapBuffers();
}

void idle() {
  rotation += 1;
  if (rotation > 360) rotation = 0;

  glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    glutIdleFunc(idle);
  } else {
    glutIdleFunc(0);
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("animation sample");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);

  setup();

  glutMainLoop();
}
