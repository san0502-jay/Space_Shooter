#include "raylib.h"
#include "Game.h"
#include "Constants.h"

int main() {
    InitWindow(SCREEN_W, SCREEN_H, "Space Shooter");
    SetTargetFPS(60);

    Game game;
    bool shouldExit = false;

    while (!WindowShouldClose() && !shouldExit) {

            game.HandleInput(shouldExit);

            if (game.currentGameState == GameState::Playing) {
                game.Update();
            }

            BeginDrawing();

            ClearBackground(BLACK);

            game.Draw();

            EndDrawing();
        }

        CloseWindow();

        return 0;

}