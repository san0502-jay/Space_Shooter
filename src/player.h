#pragma once

#include <raylib.h>

class Player {

    public:

    Vector2 position;

    float speed;

    float radius;

    Player();

    void  Update();

    void  Draw();
};