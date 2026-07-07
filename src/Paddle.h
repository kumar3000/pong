#pragma once // prevents header from being included multiple times
#include <vector>

class Paddle {
  private:
    int state;
    float y_pos; // center of the paddle
    std::vector<std::vector<float>> vertices {
      {-8.5, 1.0},
      {-8.5, -1.0},
      {-8.0, -1.0},
      {-8.0, 1.0}
    };

  public:
    Paddle(int, float); // int state, float y_pos
    ~Paddle() = default;

    int movePaddle(float);
    float getYPos();
    float getVertexY(int);
    void setVertexY(int, float);
    float getVertexX(int);
    void setVertexX(int, float);
};
