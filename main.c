#include<stdio.h>
#include"tetris.h"
int main() {
	ConsoleInit(); //�ʱ�ȭ��

	DrawField();

	ShowScore();

	StartGame();
}