#pragma once

#include<raylib.h>
class Bullet {
    public:

    Vector2 position;

    float speed;

    bool active;

    Texture2D* bulletTexture;

    Rectangle GetRect();

    Bullet(Vector2 startPosition,Texture2D* texture);

    void Update();

    void Draw();

};
