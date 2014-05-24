#include "Point.h"

Point::Point()
{
    x = 0.0;
    y = 0.0;
}

Point::Point(float x,float y){

    this->x = x;
    this->y = y;
}

void Point::setX(float x){
    this->x = x;
}

void Point::setY(float y){
    this->y = y;
}

float Point::getX() const{
    return x;
}

float Point::getY() const{
    return y;
}

float Point::computeDistance(Point p){

    return sqrt(pow(p.x - x,2) + pow(p.y - y,2));
}

Point Point::sum(Point p){

    Point result;

    result.x = x + p.x;
    result.y = y + p.y;

    return result;
}

Point Point::sub(Point p){

    Point result;

    result.x = x - p.x;
    result.y = y - p.y;

    return result;
}

float Point::computeInclination(Point p){
    return atan2(p.y-y,p.x-x);
}

Point Point::vectorXScalar(float scalar){

    Point result;

    result.x = x*scalar;
    result.y = y*scalar;

    return result;
}

Point Point::vectorRotate(float angle,int sentido){

    Point result;
    float magnitude = vectorMagnitude();
    float initialAngle = vectorInclination();

    if(sentido == CLOCKWISE){
        result.x = magnitude * cos(initialAngle + angle);
        result.y = magnitude * sin(initialAngle + angle);
    }else{
        result.x = magnitude * cos(initialAngle - angle);
        result.y = magnitude * sin(initialAngle - angle);
    }
}

float Point::vectorInclination(){
    return atan2(y,x);
}

float Point::vectorMagnitude(){
    return sqrt(pow(x,2) + pow(y,2));
}

Point Point::vectorNegate(){

    Point result;

    result.x = -x;
    result.y = -y;

    return result;
}

Point Point::vectorNormalize(){

    Point result;
    float magnitude = vectorMagnitude();

    result.x = x/magnitude;
    result.y = y/magnitude;

    return result;

}

Point Point::vectorProjX(){

    Point result;

    result.x = x;
    result.y = 0;

    return result;
}

Point Point::vectorProjY(){

    Point result;

    result.x = 0;
    result.y = y;

    return result;
}