#include "raylib.h"
#include "Player.h"

int main()
{

    int winWidth{480}, windHeight{480};
    InitWindow(winWidth, windHeight, "Dino Game!");

    Texture2D bg{LoadTexture("sheets/background.png")};

    Player dino{winWidth, windHeight};

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawTexture(bg, 0, 0, WHITE);
        dino.tick(GetFrameTime());

        EndDrawing();
    }


}