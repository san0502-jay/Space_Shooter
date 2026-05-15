#include "game.h"
#include<algorithm>


float enemySpawnTimer;
float enemySpawnInterval;
int score;



Game::Game() {

    enemySpawnTimer = 0.0f;
    enemySpawnInterval = 1.3f;
    score = 0;
}

void Game::Update() {
  player.Update();
    enemySpawnTimer += GetFrameTime();

    if (enemySpawnTimer >= enemySpawnInterval) {
        float randomx = GetRandomValue(50,750);

        enemies.push_back(Enemy({randomx,-20}));

        enemySpawnTimer = 0.0f;
    }

    if(IsKeyPressed(KEY_SPACE)) {
        bullets.push_back(Bullet(player.position));
    }

    for (Bullet& bullet : bullets) {
        bullet.Update();
    }

    for (Enemy& enemy : enemies) {
        if (enemy.active) {
        enemy.Update();
    }
}
    for (Bullet& bullet : bullets) {
        for (Enemy& enemy : enemies) {
            if (bullet.active && enemy.active) {
              if  (CheckCollisionCircles(
                bullet.position,
                5,
                enemy.position,
                enemy.radius)) {
                  bullet.active = false;

                  enemy.active = false;
                  score += 10;
              }
            }
        }
    }


bullets.erase(
    std::remove_if(
        bullets.begin(),
        bullets.end(),
        [](Bullet& bullet ) {
            return !bullet.active;
        }),
        bullets.end()
        );


    enemies.erase(
        std::remove_if(
            enemies.begin(),
            enemies.end(),
            [](Enemy& enemy) {
                return !enemy.active;
            }),
            enemies.end());


    for (Enemy& enemy : enemies) {
        if  (CheckCollisionCircles(
              player.position,
              5,
              enemy.position,
              enemy.radius)) {
            currentGameState = GameState:: GameOver;
              }
    }
}





void Game::Draw() {


    for (Bullet& bullet : bullets) {
        bullet.Draw();
    }

    for (Enemy& enemy : enemies) {
        if (enemy.active) {
            enemy.Draw();
        }
    }
    player.Draw();

    DrawText(TextFormat("Score: %i ",score), 20,20,30,BLACK);
}


void Game::Reset()
{
    player = Player();

    bullets.clear();

    enemies.clear();

    score = 0;

    enemySpawnTimer = 0.0f;

    currentGameState = GameState::playing;
}