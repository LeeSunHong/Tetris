#include<stdio.h>
#include"tetris.h"
int main() {
	ConsoleInit(); //초기화면

	DrawField();

	ShowScore();

	StartGame();
}