#pragma once
#include"point.h"
#include<iostream>
using namespace std;
class Food
{
public:
	Food()
	{
		position.SetPosition(20, 24);//��ʼ����һ��λ��
	}
	Food(int x,int y)
	{
		position.SetPosition(x, y);//����λ��
	}
	void FoodPlace(int x,int y)
	{
		position.SetPosition(x, y);
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		//���ñ�����ɫ
		SetConsoleTextAttribute(hout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Point::SetOutputPostition(x, y, hout);
		cout << "��";
	}
	Point& GetPosition()
	{
		return position;
	}
	void Show()
	{
		cout << '(' << position.Getx() << ',' << position.Gety() << ')' ;
	}
private:
	Point position;
};