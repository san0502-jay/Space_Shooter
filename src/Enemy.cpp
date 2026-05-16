#include "Enemy.h"

Enemy::Enemy(Vector2 startPosition, Texture2D* texture) {

    position = startPosition;

    speed = 100.0f;

    radius = 55.0f;

    active = true;

    Enmeytexture = texture;


}

void Enemy::Update() {
    float deltaTime = GetFrameTime();

    position.y += speed * deltaTime;

    if (position.y > 650) {
        active = false;
    }
}

void Enemy::Draw() {

    Rectangle source =
    {
        0,
        0,
        (float)Enmeytexture->width,
        (float)Enmeytexture->height
    };

    Rectangle destination =
    {
        position.x,
        position.y,
        80,
        80
    };

    Vector2 origin =
    {
        40,
        40
    };

    DrawTexturePro(
        *Enmeytexture,
        source,
        destination,
        origin,
        0.0f,
        WHITE
    );

}


Rectangle Enemy::GetRect()
{
    return
    {
        position.x - 30,
        position.y - 30,
        62,
        62
    };
}
