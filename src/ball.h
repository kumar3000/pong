#ifndef BALL_H
#define BALL_H

#include "point.h"

class Ball {
  private:
  Point pos;
  float speed;
  int horz, vert;

  public:
    Ball(Point, float, int, int);
    ~Ball() = default;
    
    void moveBall(float, float);

    float getX() const;
    void setX(float);
    float getY() const;
    void setY(float);
    float getSpeed() const;
    void setSpeed(float);
    int getHorzState() const;
    void setHorzState(int);
    int getVertState() const;
    void setVertState(int);
};

#endif
