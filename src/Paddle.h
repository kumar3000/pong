#pragma once // prevents header from being included multiple times

class Paddle {
  private:
    int state;
    float y_pos;

  public:
    Paddle(int, float); // int state, float y_pos
    ~Paddle() = default;
    int movePaddle(float);
    float getYPos();
};
