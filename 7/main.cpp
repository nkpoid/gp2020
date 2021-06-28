#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <GL/glut.h>

#include <iostream>
#include <random>
// #include <OpenGL/OpenGL.h>
// #include <GLUT/GLUT.h>

float rotation = 0;
std::random_device rd;
std::default_random_engine eng(rd());
std::uniform_real_distribution<float> distr(-1, 1);

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
  gluLookAt(0, 2, 13, 0, 0, 0, 0, 1, 0);
}

void display() {
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  int x = 5;
  int y = 5;
  int z = 5;

  glPushMatrix();
  {
    glRotatef(rotation, 1, 1, 1);

    glPushMatrix();
    {
      glTranslatef(-(x - 1) / 2.0f, -(y - 1) / 2.0f, -(z - 1) / 2.0f);

      for (int k = 0; k < z; k++) {
        for (int j = 0; j < y; j++) {
          for (int i = 0; i < x; i++) {
            glPushMatrix();
            {
              glTranslatef(i, j, k);
              glRotatef(distr(eng) * rotation, 0, 1, 1);
              glutSolidCube(0.5);
            }
            glPopMatrix();
          }
        }
      }
    }
    glPopMatrix();
  }
  glPopMatrix();

  glutSwapBuffers();
}

void idle() {
  rotation++;
  glutPostRedisplay();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(600, 600);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("forCubes");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);

  setup();

  glutMainLoop();
}