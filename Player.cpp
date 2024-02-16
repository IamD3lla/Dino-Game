#include "Player.h"
#include "raymath.h"

Player::Player(int winWidth, int winHeight)
{

    texWidth = dinoStd.width / 24;
    texHeight = dinoStd.height;

    position.y = winHeight/2 + 49;

}

void Player::tick(float deltaTime)
{

    //Witch frame in the spritesheet
    Rectangle source{frame * texWidth, texHeight, rightLeft * texWidth, texHeight};
    //Position and size
    Rectangle dest{position.x, position.y, texWidth * scale, texHeight * scale};

    Vector2 direction{};
    if(IsKeyDown(KEY_A)){
        position.x-=4;
        direction.x--;
    } 
    if(IsKeyDown(KEY_D)) {
        position.x+=4;
        direction.x++;
    }
    //Checks if the Lenght of direction is being alterated
    if(Vector2Length(direction) != 0)
    {
        direction.x < 0 ? rightLeft = -1 : rightLeft = 1;
        source = Rectangle{(frame + 3 ) * texWidth, texHeight, rightLeft * texWidth, texHeight};
    }
    else
    {
        source = Rectangle{frame * texWidth, texHeight, rightLeft * texWidth, texHeight};
    }


    //update frames
    runningTime += deltaTime;
    if(runningTime >= updateTime)
    {
        frame++;
        runningTime = 0;
        if(frame > maxFrames)
        {
            frame = 0;
        }
    }

    
    //Drawing the texture
    DrawTexturePro(dinoStd, source, dest, Vector2{}, 0, WHITE);
   

}