#pragma once
#include<iostream>
#include<windows.h>
using namespace std;
class Point
{
public:
	Point(){}
	Point(int x, int y)
		: _x(x)
		, _y(y)
	{}
	static void SetOutputPostition(int x,int y,HANDLE hout)//创建句柄
	{
		COORD pos;//定义字符在屏幕上的位置
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hout, pos);//控制台光标设置
	}
	void Plot(HANDLE hout)
	{
		SetOutputPostition(_x, _y, hout);//设置到x,y处打印'■'
		cout << "¡ö";
	}
	void Clear(HANDLE hout)
	{
		SetOutputPostition(_x, _y, hout);
		cout << "  ";
	}
	void SetPosition(int x, int y)
	{
		_x = x;
		_y = y;
	}
	void Clear()
	{
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//从标准输出流中获取句柄
		cout << " ";
	}
	bool operator==(Point& point)
	{
		return point._x == _x&&point._y == _y;
	}
	int Getx()
	{
		return _x;
	}
	int Gety()
	{
		return _y;
	}
private:
	int  _x;
	int  _y;
};
