#pragma once
#include"food.h"
#include"snake.h"
#include"point.h"
#include<iostream>
#include<windows.h>
#include<time.h>
#include"conio.h"
using namespace std;
class Game
{
public:
	Game()
	{
		_exit = false;
		_length = 80;
		_width = 24;
		_score = 0;
	}
	bool Exit()
	{
		return _exit;
	}
	void NewGame()
	{
		//SMALL_RECT rc = { 0, 0, 80 - 1, 25 - 1 }; // 重置窗口位置和大小  
		system("cls");
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
		//system("color 81");  
		COORD position = { 30, 6 };
		SetConsoleCursorPosition(hOut, position);
		//设置输出“SNAKE”  
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << " ■■■   ■     ■  ■■■  ■    ■ ■■■■";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		Point::SetOutputPostition(30, 7, hOut);
		cout << "■    ■  ■■   ■ ■    ■ ■   ■  ■";
		Point::SetOutputPostition(30, 8, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "■        ■ ■  ■ ■    ■ ■  ■   ■";
		Point::SetOutputPostition(30, 9, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << " ■■■   ■  ■ ■ ■■■■ ■■     ■■■";
		Point::SetOutputPostition(30, 10, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "      ■  ■   ■■ ■    ■ ■  ■   ■";
		Point::SetOutputPostition(30, 11, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "■    ■  ■     ■ ■    ■ ■   ■  ■";
		Point::SetOutputPostition(30, 12, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << " ■■■   ■     ■ ■    ■ ■    ■ ■■■■";
		cout << endl;
		Point::SetOutputPostition(40, 20, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

		cout << "Press any key to start...";
		/*while (true)
		{
			Point::SetOutputPostition(27, 20, hOut);
			cout << "Press any key to start...";

			Sleep(70);
			for (int i = 0; i < 25; i++)
				cout << "\b \b";
			Sleep(70);
			if (_kbhit())
				break;
		}*/
		cin.get();
	}
	void SettingGame()
	{
		system("cls");
		char chooselevel;
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
		//system("color 81");  
		COORD position = { 30, 6 };
		SetConsoleCursorPosition(hOut, position);
		//设置输出“SNAKE”  
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << " ■■■   ■     ■  ■■■  ■    ■ ■■■■";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		Point::SetOutputPostition(30, 7, hOut);
		cout << "■    ■  ■■   ■ ■    ■ ■   ■  ■";
		Point::SetOutputPostition(30, 8, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "■        ■ ■  ■ ■    ■ ■  ■   ■";
		Point::SetOutputPostition(30, 9, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << " ■■■   ■  ■ ■ ■■■■ ■■     ■■■";
		Point::SetOutputPostition(30, 10, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "      ■  ■   ■■ ■    ■ ■  ■   ■";
		Point::SetOutputPostition(30, 11, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "■    ■  ■     ■ ■    ■ ■   ■  ■";
		Point::SetOutputPostition(30, 12, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << " ■■■   ■     ■ ■    ■ ■    ■ ■■■■";
		cout << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		Point::SetOutputPostition(30, 15, hout);
		cout << "***************************************************" << endl;
		Point::SetOutputPostition(30, 16, hout);
		cout << "*              choose    difficulity  :           *" << endl;
		Point::SetOutputPostition(30, 17, hout);
		cout << "*                 <1> easy                        *" << endl;
		Point::SetOutputPostition(30, 18, hout);
		cout << "*                 <2> normal                      *" << endl;
		Point::SetOutputPostition(30, 19, hout);
		cout << "*                 <3> hard                        *" << endl;
		Point::SetOutputPostition(30, 20, hout);
		cout << "***************************************************" << endl;
		while (true)
		{
			Point::SetOutputPostition(30, 22, hout);
			cout << "请输入挑战等级：";
			cin >> chooselevel;
			if (chooselevel == '1' || chooselevel == '2' || chooselevel == '3')
			{
				_level = chooselevel -'0' ;
				switch (_level)
				{
				case 1: _speed = 500; break;
				case 2: _speed = 250; break;
				case 3: _speed = 150; break;
				default:
					break;
				}
				break;
			}
			else
			{
				cout << "                              输入出错！ （应该输入1、2、3）" << endl;
			}
		}
	}
	void PaintMap()
	{
		system("cls");
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hout, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);//设置颜色
		for (int i = 0; i <= 78; i += 2)
		{
			for (int j = 0; j < 25; j++)
			{
				if ((i == 0) || (i == 78) || (j == 0) || (j == 24))
				{
					Point::SetOutputPostition(i, j, hout);
					cout << "■";
				}

			}
		}
		for (int x = 2; x <= 78; x += 2)
		{
			Point::SetOutputPostition(x, 2, hout);
			cout << "■";
		}
	}
	void ShowState()
	{
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hout,  
			FOREGROUND_RED  | FOREGROUND_INTENSITY);
		Point::SetOutputPostition(2, 1, hout);
		cout << "Difficulity :";
		SetConsoleTextAttribute(hout,
			FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		switch (_level)
		{
		case 1: cout << "Easy"; break;
		case 2:cout << "Normal"; break;
		case 3:cout << "Hard"; break;
		}
		SetConsoleTextAttribute(hout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "■";
		SetConsoleTextAttribute(hout,   FOREGROUND_RED  | FOREGROUND_INTENSITY);
		cout << "Press ";
		SetConsoleTextAttribute(hout,
			FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "WASD ";
			cout<<"to move your snake.";
		SetConsoleTextAttribute(hout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "■";
		SetConsoleTextAttribute(hout,  FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout << "      Score : ";
		SetConsoleTextAttribute(hout,
			FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout<< _score << "            ";
	}
	void UpdateScore(bool eaten)
	{
		if (eaten)
		{
			HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hout, BACKGROUND_GREEN | FOREGROUND_RED | 
				BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
			_score += 10;
			Point::SetOutputPostition(58, 1,hout);
			cout << "score : " << _score;
			int spaceUsed = 0;
			for (int s = _score; s != 0; s /= 10)
				spaceUsed++;
			for (int i = 0; i < 10 - spaceUsed; i++)
				cout << ' ';
		}
	}
	bool DricetionChanged()
	{
		char _ch;
		if (_kbhit())
		{
			_ch = _getch();
			switch (_ch)
			{
			case 'w':case'W':
				return _snake.ChangeDirection(_snake.UP); break;
			case 's':case'S':
				return _snake.ChangeDirection(_snake.DOWN); break;	
			case 'a':case'A':
					return _snake.ChangeDirection(_snake.LEFT); break;	
			case 'd':case'D':
						return _snake.ChangeDirection(_snake.RIGHT); break;
			default:
				break;
			}
		}
		return false;
	}
	void RandomFood(Food& food)
	{
		srand(static_cast<unsigned>(time(NULL)));
		int x = 0;
		int y = 0;
		while (true)
		{
			x = rand() % (_length / 2) * 2;
			y = rand() % (_width /2) * 2;
			if ((x <= 2) || (y <= 6) || (x >= 70) || (y >= 20))
				continue;//产生到墙上 重新产生
			if (!_snake.FoodHitSnake(Point(x, y)))
				break;//不产生在蛇身上
			else
				continue;
		}
		_food.FoodPlace(x,y);//位置核实 投放food
	}
	void PlayGame()
	{
		//初始化界面
		system("cls");
		PaintMap();
		ShowState();
		_food.FoodPlace(20, 20);//初始化food位置
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		_snake.PrintSnake(hout);
		while (1)
		{
			_snake.Tail().Clear(hout);
			DricetionChanged();
			bool eaten = _snake.Eat(_food);
			if (!eaten)
				_snake.Move();
			else
				RandomFood(_food);
			UpdateScore(eaten);
			SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | 
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			_snake.Head().Plot(hout);
			if (_snake.EatSelf() || _snake.HitEdge())
			{
				Sleep(1000);
				SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_RED);//如果碰到身体 或者撞到墙显示颜色不一样
				_snake.Head().Plot(hout);
				Sleep(3000);
				break;//并且结束
			}
			Sleep(_speed);
		}
	}
	void GameOver()
	{
		int x = 28;
		int y = 3;
		system("cls");
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		Point::SetOutputPostition(x, y, hOut);
		cout << "       ■■■■■";
		Point::SetOutputPostition(x, y + 1, hOut);
		cout << "    ■■■■■■■■ ";
		Point::SetOutputPostition(x, y + 2, hOut);
		cout << "  ■■■ ■■■ ■■■ ";
		Point::SetOutputPostition(x, y + 3, hOut);
		cout << " ■■■    ■    ■■■ ";
		Point::SetOutputPostition(x, y + 4, hOut);
		cout << "  ■■■  ■■  ■■■";
		Point::SetOutputPostition(x, y + 5, hOut);
		cout << "   ■■■■■■■■■";
		Point::SetOutputPostition(x, y + 6, hOut);
		cout << "     ■■■■■■■";
		Point::SetOutputPostition(x, y + 7, hOut);
		cout << "     ■■ ■■ ■■";
		Point::SetOutputPostition(x, y + 8, hOut);
		cout << "                        ";
		Point::SetOutputPostition(x, y + 9, hOut);
		cout << "     ■■ ■■ ■■ ";
		Point::SetOutputPostition(x, y + 10, hOut);
		cout << "      ■■■■■■";
		Point::SetOutputPostition(x + 7, y + 13, hOut);
		cout << "GAME  OVER";
		Point::SetOutputPostition(x + 7, y + 15, hOut);
		cout << "Score : " << _score;
		Point::SetOutputPostition(x + 4, y + 17, hOut);
		cout << "Play Again?(Y/N)";
		char _ch;
		while (1)
		{
			cin >> _ch;
			if (_ch == 'n' || _ch == 'N')
			{
				_exit = true;
				break;
			}
			else if (_ch=='y'||_ch=='Y')
			{
				break;
			}
		}
		Point::SetOutputPostition(x - 1, y + 19, hOut);
	}
private:
	bool  _exit;//是否退出
	int _length;//地图长度
	int _width;//地图宽度
	int _level;//等级
	int _speed;//加速设置游戏难度
	int _score;//成绩
	Snake _snake;
	Food _food;



};