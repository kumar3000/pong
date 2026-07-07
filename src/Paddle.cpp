#include "Paddle.h"

Paddle::Paddle(int s, float y) {
  state = new int(s);
  y_pos = new float(y);
}

Paddle::~Paddle() {
  delete state;
  delete y_pos;
}

int Paddle::movePaddle(float delta_y) {
  if (delta_y > 0.0 && *y_pos < 9) {
    *y_pos += delta_y;
  } else if (delta_y < 0.0 && *y_pos > -9) {
    *y_pos += delta_y;
  }

  return 0; // exit success
}

float Paddle::getYPos() {
  return *y_pos;
}
