#include "Paddle.h"

Paddle::Paddle(int s, float y, const std::array<Point, 4> &pts) : state(s), y_pos(y), vertices(pts) {}

int Paddle::movePaddle(int direction, float step) {
  int i;

  if (direction && y_pos < 9) {
    for (i = 0; i < 4; i++) {
      vertices[i].y += step;
    }
    y_pos += step;
  } else if (!direction && y_pos > -9) {
    for (i = 0; i < 4; i++) {
      vertices[i].y -= step;
    }
    y_pos -= step;
  }

  if (y_pos > 9 || y_pos < -9)
    return 1;

  return 0;
}

float Paddle::getYPos() const {
  return y_pos;
}

float Paddle::getVertexY(int idx) const {
  return vertices[idx].y;
}

void Paddle::setVertexY(int idx, float val) {
  vertices[idx].y = val;
}

float Paddle::getVertexX(int idx) const {
  return vertices[idx].x;
}

void Paddle::setVertexX(int idx, float val) {
  vertices[idx].x = val;
}
