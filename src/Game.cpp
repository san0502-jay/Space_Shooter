#include "game.h"
#include<algorithm>


float enemySpawnTimer;
float enemySpawnInterval;
float shootcooldown;
float shootinterval;
float difficulttimer;
int score;




Game::Game() {

    enemySpawnTimer = 0.0f;
    enemySpawnInterval = 1.3f;
    shootcooldown =0.0f;
    shootinterval = 0.25f;
    difficulttimer = 0.0f;
    score = 0;


    explosionTexture = LoadTexture("Assets/03.png");

    for (int i = 0; i < 100; i++)
    {
        star star;

        star.position =
        {
            (float)GetRandomValue(0, 800),
            (float)GetRandomValue(0, 600)
        };

        star.speed = (float)GetRandomValue(50, 200);

        star.size = (float)GetRandomValue(1, 3);

        stars.push_back(star);
    }
}

void Game::Update() {
    player.Update();
    enemySpawnTimer += GetFrameTime();
    shootcooldown += GetFrameTime();
    difficulttimer += GetFrameTime();

    for (star& star : stars) {
        star.position.y += star.speed * GetFrameTime();
        if (star.position.y>600) {
            star.position.y = 0;
            star.position.x = (float)GetRandomValue(0, 800);
        }
    }

    if (difficulttimer >= 5.0f)
    {
        if (enemySpawnInterval > 0.3f)
        {
            enemySpawnInterval -= 0.02f;
        }

        difficulttimer = 0.0f;
    }

    if (enemySpawnTimer >= enemySpawnInterval) {
        float randomx = GetRandomValue(50.0f,750.0f);

        enemies.push_back(Enemy({randomx,-20}));

        enemySpawnTimer = 0.0f;
    }

    if(IsKeyPressed(KEY_SPACE)) {
        if (shootcooldown >= shootinterval)
        {

            bullets.push_back(Bullet(player.position));
            shootcooldown = 0;
        }

    }

    for (Bullet& bullet : bullets) {
        bullet.Update();
    }

    for (Enemy& enemy : enemies) {
        if (enemy.active) {
            enemy.Update();
        }
    }
    for (particle& particle : particles)
    {
        particle.position.x += particle.velocity.x * GetFrameTime();

        particle.position.y += particle.velocity.y * GetFrameTime();

        particle.life -= GetFrameTime();
    }
    for (Bullet& bullet : bullets) {
        for (Enemy& enemy : enemies) {
            if (bullet.active && enemy.active) {
                if (CheckCollisionRecs(
         bullet.GetRect(),
         enemy.GetRect())) {
                    bullet.active = false;

                    enemy.active = false;
                    SpawnExplosion(enemy.position);
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

    particles.erase(
        std::remove_if(
            particles.begin(),
            particles.end(),
            [](particle& particle) {
                return particle.life<=0.0f;
            }),
            particles.end()
);


    for (Enemy& enemy : enemies) {
        if (CheckCollisionRecs(
         player.GetRect(),
         enemy.GetRect())) {
            currentGameState = GameState:: GameOver;
              }
    }
}





void Game::Draw() {

    for (star& star : stars)
    {
        DrawCircleV(
            star.position,
            star.size,
            WHITE
        );
    }


    for (Bullet& bullet : bullets) {
        bullet.Draw();
    }

    for (Enemy& enemy : enemies) {
        if (enemy.active) {
            enemy.Draw();
        }
    }
    for (particle& particle : particles)
    {
        DrawCircleV(
        particle.position,
        particle.radius,
        ORANGE
    );
    }
    player.Draw();

    DrawText(TextFormat("Score: %i ",score), 20,20,30,WHITE);
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


void Game::SpawnExplosion(Vector2 position) {
for ( int i = 0; i < 20; i++)
    {

    particle particle;

    particle.position = position;

    particle.velocity ={(float)GetRandomValue(-200,200),(float)GetRandomValue(-200,200)};

    particle.life = 1.0f;

    particle.radius = (float)GetRandomValue(2,4);

    particles.push_back(particle);


}
}
