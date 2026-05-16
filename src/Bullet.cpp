#include "Bullet.h"


Bullet::Bullet(Vector2 startposition) {
    position = startposition;

    speed = 500.0f;

    active = true;
    bulletTexture = LoadTexture("Assets/bullet.png");

}

void Bullet::Update() {
    float deltatime = GetFrameTime();

    position.y -= speed*deltatime;
    if (position.y < 0.0f) active = false;


}


void Bullet::Draw() {
    if (active) {
        DrawTexture(
     bulletTexture,
     position.x - bulletTexture.width / 2,
     position.y - bulletTexture.height / 2,
     WHITE
 );
    }
}


Rectangle Bullet::GetRect()
{
    return
    {
        position.x - bulletTexture.width / 2,
        position.y - bulletTexture.height / 2,
        (float)bulletTexture.width,
        (float)bulletTexture.height
    };
}
