#include<stdio.h>
#include "raylib.h"
#include "chess.h"
int main(){
    
    InitWindow(screenWidth,screenHeight,"Horse");
    SetTargetFPS(60);
    int posX,posY;
    Image horse = LoadImage("horse-head.png");
    ImageResize(&horse,50,50);
    Texture2D texture = LoadTextureFromImage(horse);
    InitAudioDevice();
    // Music music = LoadMusicStream("horseMusic.mp3");
    // PlayMusicStream(music);
    Sound sound = LoadSound("horseMusic.mp3");
    while(!WindowShouldClose()){
        BeginDrawing();
        initCell();
        drawGrid();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            posX = GetTouchX();
            posY = GetTouchY();
            PlaySound(sound);
        }
        putHorse(&texture,posX,posY);
        markNextMoves(&texture,sound,posX,posY);
        

        ClearBackground(WHITE);
        EndDrawing();
    }
    UnloadTexture(texture);
    CloseAudioDevice();
       // Texture unloading
    return 0;
}
