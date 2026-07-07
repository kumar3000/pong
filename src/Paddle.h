#pragma once // prevents header from being included multiple times

class Paddle {
  private:
    float *y_pos;
    int *state;

  public:
    Paddle(int, float); // int state, float y_pos
    ~Paddle();  
    int movePaddle(float);
    float getYPos();
};
