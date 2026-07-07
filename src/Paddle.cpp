#include "Paddle.h"

Paddle::Paddle(int s, float y) : state(s), y_pos(y) {}

int Paddle::movePaddle(float delta_y) {
  if (delta_y > 0.0 && y_pos < 9) {
    y_pos += delta_y;
    for (int i = 0; i < 4; i++)
      vertices[i].y += delta_y;
  } else if (delta_y < 0.0 && y_pos > -9) {
    y_pos += delta_y;
    for (int i = 0; i < 4; i++)
      vertices[i].y += delta_y;
  }

  if (y_pos < -9 || y_pos > 9)
    return 1;

  return 0; // success
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
