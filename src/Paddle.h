#pragma once // prevents header from being included multiple times

class Paddle {
  private:
    float y_pos{0.0};
    int state{1};

  public:
    int movePaddle();
    float getYPos();
};
