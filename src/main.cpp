/*** Includes ***/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include "Paddle.h"

/*** Defines ***/
#define FPS 1000/60 // 1000/DESIRED_FPS
#define MVSIZE 0.5 // 0.0 to 10.0
#define WSIZE 500
#define PTSIZE 10.0
#define GRIDSIZE 10.0

/*** Globals ***/
std::array<Point, 4> playerPoints {{
  {-8.5, 1.0}, {-8.5, -1.0}, {-8, -1.0}, {-8, 1.0}
}};


std::array<Point, 4> mirrorPoints {{
  {8.5, 1.0}, {8.5, -1.0}, {8, -1.0}, {8, 1.0}
}};

Paddle player(1, 0.0, playerPoints);
Paddle mirror(1, 0.0, mirrorPoints);

/*** Utilities ***/
void debug(std::string error) {
  std::cout << error << std::endl;
  exit(1);
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
}

/*** Callback Functions ***/
void display() {
  glClear(GL_COLOR_BUFFER_BIT); // clear screen for display
  glLoadIdentity();

  // player
  glBegin(GL_QUADS);
  for (int i = 0; i < 4; i++)
    glVertex2f(player.getVertexX(i), player.getVertexY(i));
  glEnd();
  
  // mirror
  glBegin(GL_QUADS);
  for (int i = 0; i < 4; i++)
    glVertex2f(mirror.getVertexX(i), mirror.getVertexY(i));
  glEnd();

  // ball
  glPointSize(PTSIZE);
  glBegin(GL_POINTS);
  glVertex2f(0, 0);
  glEnd();

  glutSwapBuffers();
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);

  // projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-GRIDSIZE, GRIDSIZE, -GRIDSIZE, GRIDSIZE);

  glMatrixMode(GL_MODELVIEW);
}

void readKey(int key, int, int) {
  switch (key) {
    case GLUT_KEY_UP:
      if (player.movePaddle(1, MVSIZE) == 1 || mirror.movePaddle(1, MVSIZE) == 1)
        debug("*.movePaddle() { error }");
      std::cout << "GLUT_KEY_UP: " << player.getYPos() << std::endl;
      break;
    case GLUT_KEY_DOWN:
      if (player.movePaddle(0, MVSIZE) == 1 || mirror.movePaddle(0, MVSIZE) == 1)
        debug("*.movePaddle() { error }");
      std::cout << "GLUT_KEY_DOWN: " << player.getYPos() << std::endl;
      break;
  }
}

void timer(int) { // not using int so i'm not specifying it...
  glutSpecialFunc(readKey);

  glutPostRedisplay();
  glutTimerFunc(FPS, timer, 0);
}


/*** Entry Point ***/
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(200, 100);
  glutInitWindowSize(WSIZE, WSIZE);

  glutCreateWindow("pingy pongy");

  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(0, timer, 0);

  glutMainLoop();
  return 0;
}
