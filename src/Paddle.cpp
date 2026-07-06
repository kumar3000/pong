#include "Paddle.h"

int Paddle::movePaddle() {
  if (this->state == 1) {
    if (this->y_pos < 9) {
      this->y_pos += 0.2;
    } else {
      this->state = -1;
    }
  } else if (this->state == -1) {
    if (this->y_pos > -9) {
      this->y_pos -= 0.2;
    } else {
      this->state = 1;
    }
  } else {
    return 1; // exit failure
  }
  return 0; // exit success
}

float Paddle::getYPos() {
  return this->y_pos;
}
