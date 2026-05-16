#include "player.h"
#include "Constants.h"

Player::Player() {

    position ={400,500};

    speed = 300.0f;

    radius = 45.0f;
    playerTexture = LoadTexture("Assets/player_space.png");


}

void Player::Update() {

    float deltatime = GetFrameTime();

    if (IsKeyDown(KEY_W) || (IsKeyDown(KEY_UP))) position.y -= speed * deltatime;

    if (IsKeyDown(KEY_S) || (IsKeyDown(KEY_DOWN))) position.y += speed * deltatime;

    if (IsKeyDown(KEY_A) || (IsKeyDown(KEY_LEFT))) position.x -= speed * deltatime;

    if (IsKeyDown(KEY_D) || (IsKeyDown(KEY_RIGHT))) position.x += speed * deltatime;

    if (position.x < radius) position.x = radius;

    if (position.x > SCREEN_W- radius ) position.x = SCREEN_W - radius;

    if (position.y < radius) position.y = radius;

    if (position.y > SCREEN_H - radius ) position.y = SCREEN_H - radius;



}

void Player::Draw() {


    Rectangle source =
    {
        0,
        0,
        (float)playerTexture.width,
        (float)playerTexture.height
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
        playerTexture,
        source,
        destination,
        origin,
        0.0f,
        WHITE
    );

}

Rectangle Player::GetRect()
{
    return
    {
        position.x - 25,
        position.y - 25,
        51,
        51
    };

}

