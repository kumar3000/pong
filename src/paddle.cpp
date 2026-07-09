#include "paddle.h"

Paddle::Paddle(int s, const std::array<Point, 4> &pts) : state(s), vertices(pts) {
  float x, y;
  x = (vertices[3].x + vertices[0].x) / 2;
  y = (vertices[0].y + vertices[1].y) / 2;
  center = new Point(x, y);
}

Paddle::~Paddle() {
  delete center;
}

Point* Paddle::getCenter() const { return center; }
void Paddle::setCenter(Point *c) { center->x = c->x; center->y = c->y; }

float Paddle::getVertexY(int idx) const { return vertices[idx].y; }
void Paddle::setVertexY(int idx, float val) { vertices[idx].y = val; }

float Paddle::getVertexX(int idx) const { return vertices[idx].x; }
void Paddle::setVertexX(int idx, float val) { vertices[idx].x = val; }

int Paddle::getState() const { return state; }
void Paddle::setState(int s) { state = s; }

int Paddle::getScore() const { return score; }
void Paddle::setScore(int x) { score += x; }
