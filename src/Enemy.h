#pragma once

#include<raylib.h>

class Enemy {
    public:

    Vector2 position;

    float speed;

    float radius;

    bool active;

    Texture2D enemyTexture;

    Rectangle GetRect();

    Enemy(Vector2 startPosition);

    void Update();

    void Draw();

};