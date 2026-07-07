#pragma once // prevents header from being included multiple times
#include <array>

struct Point { float x, y; };

class Paddle {
  private:
    int state;
    float center; // center of the paddle
    std::array<Point, 4> vertices;

  public:
    Paddle(int s, float y, const std::array<Point, 4> &pts); // int state, float y_pos
    ~Paddle() = default;

    float getCenter() const;
    void setCenter(float);
    float getVertexY(int) const;
    void setVertexY(int, float);
    float getVertexX(int) const;
    void setVertexX(int, float);
    int getState();
    void setState(int);
};
