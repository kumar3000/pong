#include "Paddle.h"

Paddle::Paddle(int s, float y) : state(s), y_pos(y) {}

int Paddle::movePaddle(float delta_y) {
  if (delta_y > 0.0 && y_pos < 9) {
    y_pos += delta_y;
    for (int i = 0; i < 4; i++)
      vertices[i][1] += delta_y;
  } else if (delta_y < 0.0 && y_pos > -9) {
    y_pos += delta_y;
    for (int i = 0; i < 4; i++)
      vertices[i][1] += delta_y;
  }

  if (y_pos < -9 || y_pos > 9)
    return 1;

  return 0; // success
}

float Paddle::getYPos() {
  return y_pos;
}

float Paddle::getVertexY(int idx) {
  return vertices[idx][1];
}

void Paddle::setVertexY(int idx, float val) {
  vertices[idx][1] = val;
}

float Paddle::getVertexX(int idx) {
  return vertices[idx][0];
}

void Paddle::setVertexX(int idx, float val) {
  vertices[idx][0] = val;
}
