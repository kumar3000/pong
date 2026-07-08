/*** Includes ***/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include "paddle.h"
#include "ball.h"

/*** Defines ***/
#define FPS 1000/60 // 1000/DESIRED_FPS
#define MVSIZE 0.5f // 0.0 to 10.0
#define WSIZE 500
#define PTSIZE 10.0f
#define GRIDSIZE 10.0f
#define PADLSPEED 0.15f
#define BALLSPEED 0.15f
#define DIFFICULTY 0.0f // how much the ball speeds up by per collision

/*** Globals ***/
/* std::array<Point, 4> playerPointsLeft {{
  {-8.5, 1.0}, {-8.5, -1.0}, {-8, -1.0}, {-8, 1.0}
}}; */
std::array<Point, 4> playerPointsOrigin {{
  {-0.25f, 1.0f}, {-0.25f, -1.0f}, {0.25f, -1.0f}, {0.25f, 1.0f}
}};
Paddle player(2, 0.0f, playerPointsOrigin);

/* std::array<Point, 4> mirrorPoints {{
  {8.5, 1.0}, {8.5, -1.0}, {8, -1.0}, {8, 1.0}
}};
Paddle mirror(2, 0.0, mirrorPoints); */

Point ballPoints = {5.0, 0.0};
Ball ball(ballPoints, BALLSPEED, 1, 1);

/*** Utilities ***/
void debug(std::string error) {
  std::cout << error << std::endl;
  exit(1);
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
}

void collision() {
  if (ball.getX() <= player.getVertexX(3) 
      && ball.getX() >= player.getVertexX(0) 
      && ball.getY() <= player.getVertexY(0) 
      && ball.getY() >= player.getVertexY(1)) {
    player.setScore(1);
    ball.setSpeed(ball.getSpeed() + DIFFICULTY);

    if (ball.getHorzState() == 1) {
      ball.setHorzState(0);
    } else {
      ball.setHorzState(1);
    }
  }
}

void renderChar(float x, float y, void *font, int c, float r, float g, float b) {
  glColor3f(r, g, b);
  glRasterPos2f(x, y);

  glutBitmapCharacter(font, c);
}

void readKey(unsigned char key, int, int) {
  switch (key) {
    case 3:
      exit(0);
    case 107:
      player.setState(1);
      break;
    case 106:
      player.setState(0);
      break;
    default:
      player.setState(2);
      break;
  }
}

/*** Callback Functions ***/
void display() {
  glClear(GL_COLOR_BUFFER_BIT); // clear screen for display
  glLoadIdentity();
  
  glColor3f(1.0f, 1.0f, 1.0f);

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
  glVertex2f(ball.getX(), ball.getY());
  glEnd();

  renderChar(-GRIDSIZE + 0.5, GRIDSIZE - 1.0, GLUT_BITMAP_TIMES_ROMAN_24, player.getScore() % 10 + 48, 1.0f, 1.0f, 1.0f);

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

void timer(int) {
  // Player paddle movement
  if (player.getState() == 1 && player.getCenter() < GRIDSIZE - 1) {
    for (int i = 0; i < 4; i++) {
      player.setVertexY(i, player.getVertexY(i) + PADLSPEED);
    }
    player.setCenter(player.getCenter() + PADLSPEED);
  } else if (player.getState() == 0 && player.getCenter() > -GRIDSIZE + 1) {
    for (int i = 0; i < 4; i++) {
      player.setVertexY(i, player.getVertexY(i) - PADLSPEED);
    }
    player.setCenter(player.getCenter() - PADLSPEED);
  }

  // Ball movement
  ball.moveBall(GRIDSIZE, PTSIZE);
  collision();

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
  glutKeyboardFunc(readKey);
  glutTimerFunc(0, timer, 0);

  glutMainLoop();
  return 0;
}
