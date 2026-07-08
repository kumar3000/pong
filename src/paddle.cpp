#include "paddle.h"

Paddle::Paddle(int s, float y, const std::array<Point, 4> &pts) : state(s), center(y), vertices(pts) {}

float Paddle::getCenter() const { return center; }
void Paddle::setCenter(float c) { center = c; }

float Paddle::getVertexY(int idx) const { return vertices[idx].y; }
void Paddle::setVertexY(int idx, float val) { vertices[idx].y = val; }

float Paddle::getVertexX(int idx) const { return vertices[idx].x; }
void Paddle::setVertexX(int idx, float val) { vertices[idx].x = val; }

int Paddle::getState() const { return state; }
void Paddle::setState(int s) { state = s; }

int Paddle::getScore() const { return score; }
void Paddle::setScore(int x) { score += x; }
