#pragma once

#include <raylib.h>

class Player {

    public:

    Vector2 position;

    float speed;

    float radius;

    Rectangle GetRect();

    Player();
    ~Player();

    void  Update();

    void Reset();

    void Draw(bool isInvulnerable);

    private:

    Texture2D playerTexture;
};