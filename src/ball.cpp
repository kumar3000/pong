#include "ball.h"

Ball::Ball(Point p, float v, int x, int y) : pos(p), speed(v), horz(x), vert(y) {}

Point Ball::moveBall(float gridSize, float ptSize) {
  // This function returns the old coordinates of the ball
  Point p = {pos.x, pos.y};

  if (horz && pos.x < gridSize - ptSize / 100) {
    pos.x += speed;
  } else {
    horz = 0;
  }

  if (!horz && pos.x > -gridSize + ptSize / 100) {
    pos.x -= speed;
  } else {
    horz = 1;
  }

  if (vert && pos.y < gridSize - ptSize / 100) {
    pos.y += speed;
  } else {
    vert = 0;
  }

  if (!vert && pos.y > -gridSize + ptSize / 100) {
    pos.y -= speed;
  } else {
    vert = 1;
  }

  return p;
}

float Ball::getX() const { return pos.x; }
void Ball::setX(float newx) { pos.x = newx; }

float Ball::getY() const { return pos.y; }
void Ball::setY(float newy) { pos.y = newy; }

int Ball::getHorzState() const { return horz; }
void Ball::setHorzState(int state) { horz = state; }

int Ball::getVertState() const { return vert; }
void Ball::setVertState(int state) { vert = state; }
