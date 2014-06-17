#include "Rect.h"

Rect::Rect()
{
    x = 0.0;
    y = 0.0;
    h = 0.0;
    w = 0.0;
}

Rect::Rect(float x,float y,float w,float h){

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Rect::setX(float x){
    this->x = x;
}

void Rect::setY(float y){
    this->y = y;
}

void Rect::setW(float w){
    this->w = w;
}

void Rect::setH(float h){
    this->h = h;
}

float Rect::getX() const{
    return x;
}

float Rect::getY() const{
    return y;
}

float Rect::getW() const{
    return w;
}

float Rect::getH() const{
    return h;
}

Point Rect::getCenter() const{

    Point center;

    center.setX(x + w/2);
    center.setY(y + h/2);

    return center;
}

void Rect::sumPoint(Point p){
    x += p.getX();
    y += p.getY();
}

float Rect::computeDistance(Rect r){
    return getCenter().computeDistance(r.getCenter());
}

bool Rect::hasPoint(Point p){

    bool outX,outY;

    outX = p.getX() < x || p.getX() > x+w;
    outY = p.getY() < y || p.getY() > y+h;

    if(outX || outY){
        return false;
    }else{
        return true;
    }
    
}

bool Rect::isInside(float mouseX, float mouseY){

    bool outX,outY;

    outX = mouseX < x || mouseX > x+w;
    outY = mouseY < y || mouseY > y+h;

    if(outX || outY){
        return false;
    }else{
        return true;
    }
}