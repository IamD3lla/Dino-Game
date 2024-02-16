#include "raylib.h"

class Player
{
    public:
        Player(int winWidth, int winHeight);
        void tick(float deltaTime);
    private:
        Texture2D dinoStd{LoadTexture("sheets/DinoSprites - vita.png")};
        Vector2 position{};
        // 1 : facing the right, -1 : facing the left
        float rightLeft{1.f};
        // Animation variables
        float runningTime{};
        int frame{};
        int maxFrames{3};
        float texWidth{}, texHeight{};
        float updateTime{1.f / 6.f};
        float speed{4.f};
        float scale{4.0f};
};