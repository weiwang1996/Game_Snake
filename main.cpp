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
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息  
	CursorInfo.bVisible = false; //隐藏控制台光标  
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态  
	SetConsoleTitle(L"贪食蛇");//设置窗口名称
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