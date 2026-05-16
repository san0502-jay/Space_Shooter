#pragma once

#include<raylib.h>

class Enemy {
    public:

    Vector2 position;

    float speed;

    float radius;

    bool active;

    Texture2D* Enmeytexture;

    Rectangle GetRect();

    Enemy(Vector2 startPosition,Texture2D* texture);

    void Update();

    void Draw();

};