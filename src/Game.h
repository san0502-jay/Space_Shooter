#pragma once

#include "player.h"
#include <vector>
#include "Bullet.h"
#include "Enemy.h"

enum class GameState {
    playing,
    paused,
    GameOver,
};

struct particle {
    Vector2 position;

    Vector2 velocity;

    float life;

    float radius;
};

struct star {
    Vector2 position;

    float speed;

    float size;

};

class Game {
    public:

    Player player;




    Texture2D explosionTexture;


    Game();
    GameState currentGameState = GameState::playing;

    void Update();

    void Draw();

    void Reset();

    void SpawnExplosion(Vector2 position);

    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    std::vector<star> stars;
    std::vector<particle> particles;

};