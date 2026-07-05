/*** GLUT includes ***/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstdio>

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
}

/*** Callback Functions ***/
void display() {
  glClear(GL_COLOR_BUFFER_BIT); // clear screen for display
  glLoadIdentity();

  glBegin(GL_QUADS);

  glVertex2f(-9, 1);
  glVertex2f(-9, -1);
  glVertex2f(-8, -1);
  glVertex2f(-8, 1);

  glEnd();

  glutSwapBuffers();
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);

  // projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-10, 10, -10, 10);

  glMatrixMode(GL_MODELVIEW);
}

void timer(int) { // not using int so i'm not specifying it...
  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, 0); // 1000/60 = 60fps window refresh rate
}

/*** Entry Point ***/
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(200, 100);
  glutInitWindowSize(500, 500);

  glutCreateWindow("pingy pongy");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(0, timer, 0);
  init();

  glutMainLoop();
  return 0;
}
