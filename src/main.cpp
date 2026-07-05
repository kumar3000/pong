/*** GLUT includes ***/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstdio>

/*** Globals ***/
struct Paddle {
  float y_pos{0};
  int state{1}; // temp paddle state for movement
};

Paddle player;

/*** inits ***/
void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
}

/*** Callback Functions ***/
void display() {
  glClear(GL_COLOR_BUFFER_BIT); // clear screen for display
  glLoadIdentity();

  glBegin(GL_QUADS);

  glVertex2f(-8.5, 1 + player.y_pos);
  glVertex2f(-8.5, -1 + player.y_pos);
  glVertex2f(-8, -1 + player.y_pos);
  glVertex2f(-8, 1 + player.y_pos);

  glEnd();
  
  glPointSize(10.0);
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
  gluOrtho2D(-10, 10, -10, 10);

  glMatrixMode(GL_MODELVIEW);
}

void timer(int) { // not using int so i'm not specifying it...
  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, 0); // 1000/60 = 60fps window refresh rate
  
  // lets move the paddle up & down agnostic of keypresses
  if (player.state == 1) {
    if (player.y_pos < 9) {
      player.y_pos += 0.2;
    } else {
      player.state = -1;
    }
  } else if (player.state == -1) {
    if (player.y_pos > -9) {
      player.y_pos -= 0.2;
    } else {
      player.state = 1;
    }
  } else {
    printf("paddle state error");
    exit(1);
  }
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
