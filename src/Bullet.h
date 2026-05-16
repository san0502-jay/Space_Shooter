#pragma once

#include<raylib.h>
class Bullet {
    public:

    Vector2 position;

    float speed;

    bool active;

    Bullet(Vector2 startposition);

    Texture2D bulletTexture;
    
    Rectangle GetRect();

    void Update();

    void Draw();

};
