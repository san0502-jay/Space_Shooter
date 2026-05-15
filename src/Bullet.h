#pragma once

#include<raylib.h>
class Bullet {
    public:

    Vector2 position;

    float speed;

    bool active;

    Bullet(Vector2 startposition);

    void Update();

    void Draw();

};
