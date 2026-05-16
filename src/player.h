#pragma once

#include <raylib.h>

class Player {

    public:
    Texture2D playerTexture;

    Vector2 position;

    float speed;

    float radius;

    Rectangle GetRect();

    Player();

    void  Update();

    void Draw(bool isInvulnerable);
};