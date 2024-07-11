#define ROWS 8
#define COLS 8
#include "raylib.h"
#define screenWidth   400
#define screenHeight  400

#define cellWidth  50
#define cellHeight 50

typedef struct Cell{
	int i;
	int j;
}Cell;

void initCell();
void drawCell(Cell cell);
void drawGrid();
int isEven(int,int);
int isOdd(int,int);
void putHorse(Texture2D* ,int posX,int posY);
int isPosValid(int,int);
void markNextMoves(Texture2D*,Sound,int,int);

