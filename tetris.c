#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include"tetris.h"
//BLOCK
int blocks[28][4][4] =
{
	//■■■■
	{
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 1,1,1,1 },
		{ 0,0,0,0 }
	},
	{
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 }
	},
	{
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 1,1,1,1 },
		{ 0,0,0,0 }
	},
	{
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 }
	},

	//■■
	//■■
	{
		{ 1,1,0,0 },
		{ 1,1,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 1,1,0,0 },
		{ 1,1,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 1,1,0,0 },
		{ 1,1,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 1,1,0,0 },
		{ 1,1,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	},

	//■
	//■■
	//■
	{
		{ 0,1,0,0 },
		{ 0,1,1,0 },
		{ 0,1,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,0,0,0 },
		{ 1,1,1,0 },
		{ 0,1,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,1,0,0 },
		{ 1,1,0,0 },
		{ 0,1,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,1,0,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	},

	//  ■
	//■■
	//■
	{
		{ 0,0,1,0 },
		{ 0,1,1,0 },
		{ 0,1,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,1,1,0 },
		{ 0,0,1,1 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,0,1,0 },
		{ 0,1,1,0 },
		{ 0,1,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,1,1,0 },
		{ 0,0,1,1 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	},

	//■
	//■■
	//  ■
	{
		{ 0,1,0,0 },
		{ 0,1,1,0 },
		{ 0,0,1,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,1,1,0 },
		{ 1,1,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,1,0,0 },
		{ 0,1,1,0 },
		{ 0,0,1,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,1,1,0 },
		{ 1,1,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	},

	//■
	//■
	//■■
	{
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,1,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,0,0,0 },
		{ 1,1,1,0 },
		{ 1,0,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 1,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,0,0,0 },
		{ 0,0,1,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }
	},
	
	//■■
	//■
	//■
	{
		{0,0,0,0},
		{0,1,1,0},
		{0,1,0,0},
		{0,1,0,0}
	},
	{
		{0,0,0,0},
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0}
	},
	{
		{0,0,1,0},
		{0,0,1,0},
		{0,1,1,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,1,0,0},
		{0,1,1,1},
		{0,0,0,0}
	}
};

static int level = 1;
static int score = 0;
static int speed = 180;

int board[BOARD_HEIGHT + 1][BOARD_WIDTH + 12] = { 0 };

void ConsoleInit() {
	printf("테트리스 게임\n");
	printf("게임을 진행 하시려면 아무키를 눌러주세요.");
	_getch();
	CursorVisible(FALSE);
	system("cls");
}

void CursorVisible(bool blnCursorVisible) {
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = blnCursorVisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void SetCursorPosition(int posX, int posY) {
	COORD pos = { posX, posY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetCursorPosition() {
	COORD pos;
	CONSOLE_SCREEN_BUFFER_INFO Buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Buf);
	pos = Buf.dwCursorPosition;
	return pos;
}

void DrawField() {
	for (int x = 1; x <= BOARD_WIDTH; x++) {
		board[BOARD_HEIGHT][x] = 1;
		SetCursorPosition(BOARD_X+x*2, BOARD_HEIGHT+2);
		printf("━");
	}
	for (int y = 0; y < BOARD_HEIGHT+1; y++) {
		board[y][0] = 1;
		SetCursorPosition(BOARD_X, BOARD_Y + y);
		if (y == BOARD_HEIGHT)
			printf("┗");
		else 
			printf("┃");
	}
	for (int y = 0; y < BOARD_HEIGHT+1; y++) {
		board[y][BOARD_WIDTH + 1] = 1;
		SetCursorPosition(BOARD_X+(BOARD_WIDTH+1)*2, BOARD_Y + y);
		if (y == BOARD_HEIGHT)
			printf("┛");
		else
			printf("┃");
	}

	board[20][0] = 1;
	board[20][11] = 1;
}

void ShowScore() {
	SetCursorPosition(40, 3);
	printf("레벨:%d", level);
	SetCursorPosition(40, 5);
	printf("점수:%d", score);
}

void CountScore() {
	score += 10;
	if (score % 30 == 0) {
		speed -= 10;
		level++;
	}
	ShowScore();
}
void WriteBlock(int Type) {
	COORD pos = GetCursorPosition();
	for (int i = 0; i < BLOCK_NUM; i++) {
		for (int j = 0; j < BLOCK_NUM; j++)
		{
			SetCursorPosition(pos.X + (j * 2), pos.Y + i);
			if (blocks[Type][i][j] == 1)
				printf("■");
		}
		SetCursorPosition(pos.X, pos.Y);
	}
}

BOOL CheckPosition(int Type, int moveX, int moveY) {
	COORD pos = GetCursorPosition();

	int arrX = pos.X + moveX;
	int arrY = pos.Y + moveY;

	arrX = (arrX / 2) - 2;
	arrY = arrY - 2;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (blocks[Type][y][x] == 1 && board[arrY + y][arrX + x] == 1)
				return FALSE;
		}
	}
	return TRUE;
}

void BoardInit(int Type, int moveX, int moveY) {
	COORD pos = GetCursorPosition();

	int arrX = pos.X + moveX;
	int arrY = pos.Y + moveY;

	arrX = (arrX / 2) - 2;
	arrY = arrY - 2;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (blocks[Type][y][x] == 1) {
				board[arrY + y][arrX + x] = 1;
			}
		}
	}
}

void BlockDown(int colum) {
	for (int y = colum; y > 0; y--) {
		for (int x = 1; x <= 10; x++) {
			board[y][x] = board[y - 1][x];
		}
	}

	for (int x = 1; x <= 10; x++) {
		board[0][x] = 0;
	}

	for (int y = 1; y < BOARD_HEIGHT; y++) {
		for (int x = 1; x <= BOARD_WIDTH; x++) {
			SetCursorPosition(BOARD_X+(x*2), y + BOARD_Y);
			if (board[y][x] == 1)
				printf("■");
			else
				printf("  ");
		}
	}
}

void ClearBlock(int rotation, int move1, int move2)
{
	int x, y;
	COORD cursor = GetCursorPosition();

	if (CheckPosition(rotation, move1, move2) == TRUE) {
		for (y = 0; y < 4; y++) {
			for (x = 0; x < 4; x++) {
				SetCursorPosition(cursor.X + (x * 2), cursor.Y + y);
				if (blocks[rotation][y][x] == 1)
					printf("  ");
			}
		}
		SetCursorPosition(cursor.X + move1, cursor.Y + move2);
	}
}

void RemoveLine() {
	int i = 0;
	for (int y = 19; y > 0; y--) 
	{
		for (int x = 1; x <= 10; x++)
		{
			if (board[y][x] == 1)
				i++;
		}
		if (i == 10) {
			BlockDown(y);
			CountScore();
		}
		if (i == 0) {
			break;
		}
		i = 0;
	}
}

void StartGame() {
	int Type;
	int input_kb;

	srand((unsigned)time(0));
	
	while (1) {
		SetCursorPosition(12, 2);
		Type = ((rand() % 7) * 4) + 1;

		if (level == FULL_LEVEL) {
			SetCursorPosition(40, 12);
			printf("Game Clear");
			_getch();
			system("cls");
		}
		
		if (CheckPosition(Type,0,0) == FALSE) {
			EndGame();
			return;
		}

		while (1)
		{
			int pc = 0;
			int k=0;

			while (!_kbhit()) {
				WriteBlock(Type);
				Sleep(DELAY + speed);
				if (CheckPosition(Type, 0, 1) == FALSE) {
					pc = 1;
					BoardInit(Type, 0, 0);
					RemoveLine();
					break;
				}
				ClearBlock(Type, 0, 1);
			}

			if (pc == 1) break;

			input_kb = _getch();

			switch (input_kb)
			{
			case LEFT:
				ClearBlock(Type, -2, 0);
				WriteBlock(Type);
				break;
			case RIGHT:
				ClearBlock(Type, 2, 0);
				WriteBlock(Type);
				break;
			case UP:
				k = Type / 4;
				k *= 4;
				if ((Type + 1) <= (k + 3))
					k = Type + 1;

				if (CheckPosition(k, 0, 0) == TRUE) {
					ClearBlock(Type, 0, 0);
					Type = k;
					WriteBlock(Type);
					break;
				}
				break;
				
			case DOWN:
				ClearBlock(Type, 0, 2);
					break;
			case SPACE:
				while (1) {
					ClearBlock(Type, 0, 1);
					if (CheckPosition(Type, 0, 1) == FALSE) {
						WriteBlock(Type);
						BoardInit(Type, 0, 0);
						break;
					}
				}
			default:break;
			}//end switch
		}//end while(block)
	}// end while(game)

}

void EndGame() {
	SetCursorPosition(40, 12);
	printf("GameOver");
	_getch();
	system("cls");
}
