#ifndef CAMERA_H
#define CAMERA_H

#include "Game.h"
#include "GameObject.h"
#include "Point.h"

class Camera
{
public:
    static void follow(GameObject*);
    static void unfollow();
    static void update(float);

    static Point pos;
    static float speed;
private:
	static GameObject* focus;
};

#endif // CAMERA_H
