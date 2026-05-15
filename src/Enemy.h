#pragma once

#include<raylib.h>

class Enemy {
    public:

    Vector2 position;

    float speed;

    float radius;

    bool active;

    Enemy(Vector2 startPosition);

    void Update();

    void Draw();

};