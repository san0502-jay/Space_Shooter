#include "Enemy.h"

Enemy::Enemy(Vector2 startPosition) {
    position = startPosition;

    speed = 100.0f;

    radius = 20.0f;

    active = true;

}

void Enemy::Update() {
    float deltaTime = GetFrameTime();

    position.y += speed * deltaTime;

    if (position.y > 650) {
        active = false;
    }
}

void Enemy::Draw() {
    DrawCircleV(position,radius,RED);
}
