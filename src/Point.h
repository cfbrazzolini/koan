#ifndef POINT_H
#define POINT_H

#include <cmath>

#define CLOCKWISE 0
#define COUNTER_CLOCKWISE 1

class Point
{
public:
    Point();
    Point(float,float);
    void setX(float);
    void setY(float);
    float getX() const;
    float getY() const;
    float computeDistance(Point);
    Point sum(Point);
    Point sub(Point);
    float computeInclination(Point);
    Point vectorXScalar(float);
    Point vectorRotate(float,int);
    float vectorInclination();
    float vectorMagnitude();
    Point vectorNegate();
    Point vectorNormalize();
    Point vectorProjX();
    Point vectorProjY();

Point operator+(const Point& rhs) const {
   return Point(x + rhs.x, y + rhs.getY());
}

Point operator-(const Point& rhs) const {
   return Point(x - rhs.x, y - rhs.getY());
}

Point operator*(const float rhs) const {
   return Point(x * rhs, y * rhs);
}

private:
	float x;
	float y;
};

#endif // POINT_H
