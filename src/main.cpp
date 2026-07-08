/*** Includes ***/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include "paddle.h"

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
Paddle player(2, 0.0, playerPoints);

/* std::array<Point, 4> mirrorPoints {{
  {8.5, 1.0}, {8.5, -1.0}, {8, -1.0}, {8, 1.0}
}};
Paddle mirror(2, 0.0, mirrorPoints); */

Point ball = {0.0, 0.0};

float speed = 0.2f;

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
  /* glBegin(GL_QUADS);
  for (int i = 0; i < 4; i++)
    glVertex2f(mirror.getVertexX(i), mirror.getVertexY(i));
  glEnd(); */

  // ball
  glPointSize(PTSIZE);
  glBegin(GL_POINTS);
  glVertex2f(ball.x, ball.y);
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

void readState(int key, int, int) {
  switch (key) {
    case GLUT_KEY_UP:
      player.setState(1);
      break;
    case GLUT_KEY_DOWN:
      player.setState(0);
      break;
    default:
      player.setState(2);
      break;
  }
}

void timer(int) { // not using int so i'm not specifying it...
  if (player.getState() == 1 && player.getCenter() < GRIDSIZE - 1) {
    for (int i = 0; i < 4; i++) {
      player.setVertexY(i, player.getVertexY(i) + speed);
    }
    player.setCenter(player.getCenter() + speed);
  } else if (player.getState() == 0 && player.getCenter() > -GRIDSIZE + 1) {
    for (int i = 0; i < 4; i++) {
      player.setVertexY(i, player.getVertexY(i) - speed);
    }
    player.setCenter(player.getCenter() - speed);
  }

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
  glutSpecialFunc(readState);
  glutTimerFunc(0, timer, 0);

  glutMainLoop();
  return 0;
}
