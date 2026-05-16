#pragma once

#include <raylib.h>

class Player {

    public:
    Texture2D playerTexture;
    Rectangle GetRect();

    Vector2 position;

    float speed;

    float radius;

    Player();

    void  Update();

    void  Draw();
};