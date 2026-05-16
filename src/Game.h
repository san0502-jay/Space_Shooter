#pragma once

#include "player.h"
#include <vector>
#include "Bullet.h"
#include "Enemy.h"
#include "constants.h"

enum class GameState {
    Playing,
    Paused,
    GameOver,
};

struct Particle {
    Vector2 position;

    Vector2 velocity;

    float life;

    float radius;
};

struct Star {
    Vector2 position;

    float speed;

    float size;

};

class Game {
    public:

    GameState currentGameState = GameState::Playing;

    Game();
    ~Game();

    void Update();
    void Draw();
    void Reset();
    void HandleInput(bool& shouldExit);

private:

    Player player;

    Texture2D enemyTexture;
    Texture2D bulletTexture;

    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    std::vector<Star> stars;
    std::vector<Particle> particles;

    Rectangle RestartButton;
    Rectangle PauseButton;
    Rectangle ResumeButton;
    Rectangle ExitButton;


    float EnemySpawnTimer;
    float EnemySpawnInterval;
    float ShootCooldown;
    float ShootInterval;
    float DifficultTimer;
    int score;
    int lives;
    float invulnerabilityTimer;

    void SpawnExplosion(Vector2 position);

};