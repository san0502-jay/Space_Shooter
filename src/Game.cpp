#include "game.h"
#include<algorithm>

Game::Game() {

   enemyTexture= LoadTexture("Assets/enemy_space.png");
    bulletTexture= LoadTexture("Assets/bullet.png");

    RestartButton = { 300, 300, 200, 60 };
    PauseButton   = { 700,  10,  80, 40 };
    ResumeButton  = { 300, 300, 200, 60 };
    ExitButton    = { 300, 400, 200, 60 };


    EnemySpawnTimer = 0.0f;
    EnemySpawnInterval = 1.3f;
    ShootCooldown =0.0f;
    ShootInterval = 0.25f;
    DifficultTimer = 0.0f;
    score = 0;
    lives = 3;
    invulnerabilityTimer = 0;

    for (int i = 0; i < 100; i++)
    {
        Star star;

        star.position =
        {
            (float)GetRandomValue(0, SCREEN_W),
            (float)GetRandomValue(0, SCREEN_H)
        };

        star.speed = (float)GetRandomValue(50, 200);
        star.size = (float)GetRandomValue(1, 3);
        stars.push_back(star);
    }
}

Game::~Game() {
    UnloadTexture(enemyTexture);
    UnloadTexture(bulletTexture);
}

void Game::HandleInput(bool& shouldExit) {
    Vector2 mouse = GetMousePosition();
    bool clicked  = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    if (currentGameState == GameState:: GameOver) {
        if (clicked && CheckCollisionPointRec(mouse, RestartButton)) {
            Reset();
        }
    }

    if (currentGameState == GameState:: Playing) {
        if (clicked && CheckCollisionPointRec(mouse, PauseButton)) {
            currentGameState = GameState:: Paused;
        }
    }
    if (currentGameState == GameState::Paused) {
        if (clicked && CheckCollisionPointRec(mouse, ResumeButton))
            currentGameState = GameState::Playing;
    }

    if (currentGameState == GameState::Paused ||
        currentGameState == GameState::GameOver) {
        if (clicked && CheckCollisionPointRec(mouse, ExitButton))
            shouldExit = true;
        }

}

void Game::Update() {

    player.Update();

    EnemySpawnTimer += GetFrameTime();
    ShootCooldown += GetFrameTime();
    DifficultTimer += GetFrameTime();
    if (invulnerabilityTimer > 0)
    {
        invulnerabilityTimer -= GetFrameTime();
        if (invulnerabilityTimer < 0)
        {
            invulnerabilityTimer = 0;
        }
    }

    for (Star& star : stars) {
        star.position.y += star.speed * GetFrameTime();
        if (star.position.y>SCREEN_H) {
            star.position.y = 0;
            star.position.x = (float)GetRandomValue(0, SCREEN_W);
        }
    }

    if (DifficultTimer >= 5.0f)
    {
        if (EnemySpawnInterval > 0.3f)
        {
            EnemySpawnInterval -= 0.02f;
        }

        DifficultTimer = 0.0f;
    }

    if (EnemySpawnTimer >= EnemySpawnInterval) {
        float randomx = GetRandomValue(50.0f,750.0f);

        enemies.push_back(Enemy({randomx,-20},&enemyTexture));
        EnemySpawnTimer = 0.0f;
    }

    if(IsKeyPressed(KEY_SPACE)) {
        if (ShootCooldown >= ShootInterval)
        {

            bullets.push_back(Bullet(player.position, &bulletTexture));
            ShootCooldown = 0;
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
    for (Particle& particle : particles)
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
auto isDead = [](auto& x) { return !x.active; };

    bullets.erase(
        std::remove_if(
            bullets.begin(),
            bullets.end(),
            isDead),
            bullets.end()
            );


    enemies.erase(
        std::remove_if(
            enemies.begin(),
            enemies.end(),
            isDead),
            enemies.end());

    particles.erase(
        std::remove_if(
            particles.begin(),
            particles.end(),
            [](Particle& particle) {
                return particle.life<=0.0f;
            }),
            particles.end()
);


    for (Enemy& enemy : enemies)
    {
        if (CheckCollisionRecs(
                player.GetRect(),
                enemy.GetRect()) &&
            invulnerabilityTimer <= 0)
        {
            lives--;

            invulnerabilityTimer = 1.0f;

            enemy.active = false;

            if (lives <= 0)
            {
                currentGameState = GameState::GameOver;
            }

            break;
        }
    }
}


void Game::Draw() {

    for (Star& star : stars)
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
    for (Particle& particle : particles)
    {
        DrawCircleV(
        particle.position,
        particle.radius,
        ORANGE
    );
    }

    player.Draw(currentGameState == GameState::Playing && invulnerabilityTimer > 0);

    DrawText(TextFormat("Score: %i ",score), 20,20,30,WHITE);
    DrawText(TextFormat("Lives: %i", lives),20,50,30,WHITE);

    if (currentGameState == GameState::Playing) {
        DrawRectangleRec(PauseButton,GRAY);
        DrawText("PAUSE",710,20, 18,WHITE);
    }
    if (currentGameState == GameState::Paused) {
        DrawRectangle(0,0,SCREEN_W,SCREEN_H,Fade(BLACK,0.7f));
        DrawText("PAUSED",300,250,50,WHITE);
        DrawRectangleRec(ResumeButton,GREEN);
        DrawText("RESUME",350,320, 25,WHITE);
        DrawRectangleRec(ExitButton,RED);
        DrawText("EXIT",370,420, 25,WHITE);
    }
    if (currentGameState == GameState::GameOver) {
        DrawText("GAME OVER ", 280, 250, 40, RED);
        DrawRectangleRec(RestartButton, RED);
        DrawText("RESTART",340,320, 25,WHITE);
        DrawRectangleRec(ExitButton,RED);
        DrawText("EXIT",370,420, 25,WHITE);

    }

}


void Game::Reset()
{
    player = Player();

    bullets.clear();

    enemies.clear();

    score = 0;

    lives = 3;

    EnemySpawnTimer = 0.0f;

    EnemySpawnInterval =1.3F;

    DifficultTimer = 0.0f;

    currentGameState = GameState::Playing;
}


void Game::SpawnExplosion(Vector2 position) {
for ( int i = 0; i < 20; i++)
    {

    Particle particle;

    particle.position = position;

    particle.velocity ={(float)GetRandomValue(-200,200),(float)GetRandomValue(-200,200)};

    particle.life = 1.0f;

    particle.radius = (float)GetRandomValue(2,4);

    particles.push_back(particle);

    }
}
