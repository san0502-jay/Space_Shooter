#include "raylib.h"
#include "Game.h"

int main()
{
    InitWindow(800, 600, "Space Shooter");
    Rectangle restartbutton = {300,300,200,60};
    Rectangle pausebutton = {700,10,80,40};
    Rectangle resumebutton = {300,300,200,60};
    Rectangle exitbutton = {300,400,200,60};
    bool buttonPressed = false;
    bool shouldExit = false;

    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose() && !shouldExit)

    {

        if (game.currentGameState == GameState::GameOver)
        {

            if (CheckCollisionPointRec(GetMousePosition(), restartbutton)&&
                IsMouseButtonPressed (MOUSE_BUTTON_LEFT)) {
                buttonPressed = true;
                game.Reset();
                }}

        if (CheckCollisionPointRec(GetMousePosition(), pausebutton)&&
                IsMouseButtonPressed (MOUSE_BUTTON_LEFT)) {
            buttonPressed = true;
            game.currentGameState = GameState::paused;
                }

        if ( game.currentGameState == GameState::paused) {
            if (CheckCollisionPointRec(GetMousePosition(), resumebutton)&&
                    IsMouseButtonPressed (MOUSE_BUTTON_LEFT)) {
                buttonPressed = true;
                game.currentGameState = GameState::playing;
                    }
        }

        if (game.currentGameState == GameState::paused ||
            game.currentGameState == GameState::GameOver) {
            if (CheckCollisionPointRec(GetMousePosition(), exitbutton)&&
                   IsMouseButtonPressed (MOUSE_BUTTON_LEFT)) {
                buttonPressed = true;
                shouldExit = true;
                   }
            }


        if (game.currentGameState == GameState::playing  ||  game.currentGameState == GameState::GameOver)
        {
            if (CheckCollisionPointRec(GetMousePosition(), pausebutton) &&
                IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                game.currentGameState = GameState::paused;
            }
        }

        if (game.currentGameState == GameState::playing) {
            game.Update();
        }

        BeginDrawing();

        ClearBackground(WHITE);

        game.Draw();

        if (game.currentGameState == GameState::playing) {
            DrawRectangleRec(pausebutton,GRAY);
            DrawText("PAUSE",710,20, 18,WHITE);
        }



        if (game.currentGameState == GameState::paused) {
            DrawRectangle(0,0,800,600,Fade(BLACK,0.7f));
            DrawText("PAUSED",300,250,50,WHITE);
            DrawRectangleRec(resumebutton,GREEN);
            DrawText("RESUME",350,320, 25,WHITE);
            DrawRectangleRec(exitbutton,RED);
            DrawText("EXIT",370,420, 25,WHITE);
        }


        if (game.currentGameState == GameState::GameOver) {
            DrawText("GAME OVER ", 280, 250, 40, RED);
            DrawRectangleRec(restartbutton,buttonPressed ? RED : RED);
            DrawText("RESTART",340,320, 25,WHITE);
            DrawRectangleRec(exitbutton,RED);
            DrawText("EXIT",370,420, 25,WHITE);

        }


        EndDrawing();
    }

    CloseWindow();

    return 0;
}