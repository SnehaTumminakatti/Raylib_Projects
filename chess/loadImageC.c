#include<stdio.h>
#include<raylib.h>
int main(){
     InitWindow(500,500,"my window");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        Image horse = LoadImage("horse-head.png");
        ImageDraw(&horse,horse)
        DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
        ClearBackground(WHITE);
        EndDrawing();
    }
    return 0;
}