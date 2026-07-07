#include "Paddle.h"

int Paddle::movePaddle(float delta_y) {
  if (delta_y > 0.0 && this->y_pos < 9.0) {
    this->y_pos += delta_y;
  } else if (delta_y < 0.0 && this->y_pos > -9.0) {
    this->y_pos += delta_y;
  }

  return 0; // exit success
}

float Paddle::getYPos() {
  return this->y_pos;
}
