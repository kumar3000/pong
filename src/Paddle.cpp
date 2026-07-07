#include "Paddle.h"

Paddle::Paddle(int s, float y) : state(s), y_pos(y) {}

int Paddle::movePaddle(float delta_y) {
  if (delta_y > 0.0 && y_pos < 9) {
    y_pos += delta_y;
  } else if (delta_y < 0.0 && y_pos > -9) {
    y_pos += delta_y;
  }
  
  if (y_pos > 9 || y_pos < -9)
    return 1;

  return 0; // success
}

float Paddle::getYPos() {
  return y_pos;
}
