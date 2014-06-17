#include "CustomMath.h"

float CustomMath::degToRad(float alpha) {
    return alpha*PI/180;
}

float CustomMath::radToDeg(float alpha) {
    return alpha*180/PI;
}
