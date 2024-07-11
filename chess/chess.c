#include "chess.h"
#include "raylib.h"
Cell grid[COLS][ROWS];

void initCell(){
    for(int i=0;i<COLS;i++){
        for(int j=0;j<ROWS;j++){
            grid[i][j].i=i;
            grid[i][j].j=j;
        }
    }
}

void drawCell(Cell cell){
    if(isEven(cell.i,cell.j)||isOdd(cell.i,cell.j)){
        DrawRectangle(cell.i*cellWidth,cell.j*cellHeight,cellWidth,cellHeight,GRAY);
    }else{
        DrawRectangle(cell.i*cellWidth,cell.j*cellHeight,cellWidth,cellHeight,WHITE);

    }
}

void drawGrid(){
    for(int i=0;i<COLS;i++){
        for(int j=0;j<ROWS;j++){
            drawCell(grid[i][j]);
        }
    }
}

int isEven(int row,int col){
    return (!(row%2) && !(col%2));
}

int isOdd(int row,int col){
    return ((row%2) && (col%2));
}

void putHorse(Texture2D* texture, int posX,int posY){
    int row = posX/50;
    int col = posY/50;
    DrawTexture(*texture, row*50, col*50, WHITE);
}

int isPosValid(int row,int col){
    return ((row>=0) && (row<=ROWS) && (col<=COLS) && (col>=0));
}
void markNextMoves(Texture2D* texture,Sound sound, int row,int col){
    int offsets[][2]={{-1,-2},{-1,2},{-2,-1},{-2,1},{1,-2},{1,2},{2,-1},{2,1}};
    row = row/50;
    col =col/50;
    for(int i=0;i<8;i++){
        int hx=row+offsets[i][0];
        int hy=col+offsets[i][1];
        if(isPosValid(hx,hy)){
            DrawTexture(*texture, hx*50, hy*50, WHITE);
        }
    }
}
