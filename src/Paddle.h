#pragma once // prevents header from being included multiple times
#include <array>

struct Point { float x, y; };

class Paddle {
  private:
    int state;
    float y_pos; // center of the paddle
    std::array<Point, 4> vertices = {{
      {-8.5f, 1.0f}, {-8.5f, -1.0f}, {-8.0f, -1.0f}, {-8.0f, 1.0f}
    }};

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
