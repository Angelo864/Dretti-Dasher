#include "raylib.h"

int main()
{
    // window dimensions
    const int windowWidth{512};
    const int windowHeight{380};

    // initialize the window
    InitWindow(windowWidth, windowHeight, "Dretti Dasher!");

    // acceleration due to gravity  (pixels/frame)/frame
    const int gravity{1};

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 -scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;

    const int jumpVel{-22};
    bool isInAir{};

    
    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // ground check
        if (scarfyPos.y >= windowHeight - scarfyRec.height)
        {
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // rectangle is in the air
            velocity += gravity;
            isInAir = true;
        }

        // check for jump
         if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // apply gravity
        velocity += gravity;
        
        // update position
        scarfyPos.y += velocity;

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        // stop drawing
        EndDrawing();    
    
    }
    UnloadTexture(scarfy);
    CloseWindow();
}
