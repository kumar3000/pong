#ifndef PADDLE_H
#define PADDLE_H

#include <array>
#include <point.h>

class Paddle {
  private:
    int state;
    int score{0};
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
    int getState() const;
    void setState(int);
    int getScore() const;
    void setScore(int);
};

#endif
