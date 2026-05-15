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

class Game {
    public:

    Player player;


    Game();
    GameState currentGameState = GameState::playing;

    void Update();

    void Draw();

    void Reset();

    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
};