#include"game.h"
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ  
	CursorInfo.bVisible = false; //���ؿ���̨���  
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬  
	SetConsoleTitle(L"̰ʳ��");//���ô�������
	Game* game = new Game();
	game->NewGame();
	do
	{
		delete game;
		Game* game = new Game();
		game->SettingGame();
		game->PlayGame();
		game->GameOver();
	} while (!game->Exit());
	Sleep(1000);
	
	return 0;
	//game
}