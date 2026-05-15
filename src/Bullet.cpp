#include "Bullet.h"


Bullet::Bullet(Vector2 startposition) {
    position = startposition;

    speed = 500.0f;

    active = true;

}

void Bullet::Update() {
    float deltatime = GetFrameTime();

    position.y -= speed*deltatime;
    if (position.y < 0.0f) active = false;


}


void Bullet::Draw() {
    if (active) {
        DrawCircleV(position,5,RED);
    }
}

