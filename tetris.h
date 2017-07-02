#ifndef __TETRIS_H_
#define __TETRIS_H_

#include<Windows.h>

#define bool int
#define TRUE 1
#define FALSE 0

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define BOARD_X 4
#define BOARD_Y 2

#define BLOCK_TYPE_NUM 28
#define BLOCK_NUM 4

#define FULL_LEVEL 30

#define DELAY 100

enum ControlKeys {
	LEFT = 75,
	RIGHT = 77,
	UP = 72,
	DOWN = 80,
	SPACE = 32
};

void ConsoleInit();
void CursorVisible(bool blnCursorVisible);
void SetCursorPosition(int posX, int posY);
COORD GetCursorPosition();

void StartGame();
void EndGame();

void DrawField();
void ShowScore();
void CountScore();
void WriteBlock(int Type);
void BoardInit(int type, int moveX, int moveY);
void RemoveLine();
void BlockDown(int colum);
void ClearBlock(int rotation, int move1, int move2);
BOOL CheckPosition(int Type, int moveX, int moveY);
#endif
