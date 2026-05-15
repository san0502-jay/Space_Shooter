#include "player.h"

Player::Player() {

    position ={400,500};

    speed = 300.0f;

    radius = 20.0f;
}

void Player::Update() {

    float deltatime = GetFrameTime();

    if (IsKeyDown(KEY_W) || (IsKeyDown(KEY_UP))) position.y -= speed * deltatime;

    if (IsKeyDown(KEY_S) || (IsKeyDown(KEY_DOWN))) position.y += speed * deltatime;

    if (IsKeyDown(KEY_A) || (IsKeyDown(KEY_LEFT))) position.x -= speed * deltatime;

    if (IsKeyDown(KEY_D) || (IsKeyDown(KEY_RIGHT))) position.x += speed * deltatime;

    if (position.x < radius) position.x = radius;

    if (position.x > 800 - radius ) position.x = 800 - radius;

    if (position.y < radius) position.y = radius;

    if (position.y > 600 - radius ) position.y = 600 - radius;



}

void Player::Draw() {

    DrawTriangle(
        {position.x, position.y - 20},
        {position.x - 15, position.y + 20},
        {position.x + 15, position.y + 20},
        ORANGE
    );
}

