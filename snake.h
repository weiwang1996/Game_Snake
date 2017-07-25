#pragma once
#include"point.h"
#include"food.h"
#include<deque>
#include<iostream>
using namespace std;
class Snake
{
public:
	enum MoveDirection{ UP, LEFT, DOWN, RIGHT };//用枚举来描述蛇移动的四个方向
	Snake()//初始化蛇 规定蛇开始只有两个长度，并且向上移动
	{
		snake.push_back(Point(18, 16));
		snake.push_back(Point(16, 16));
		_direction = MoveDirection::UP;
	}
	//移动一步收集一次 蛇新的点集合
	void Move()
	{
		switch (_direction)//根据此时的方向来判断该如何移动，只处理头和尾
		{
		case Snake::UP:
			snake.push_front(Point(snake.begin()->Getx(), snake.begin()->Gety() -1));
				break;
		case Snake::DOWN:
			snake.push_front(Point(snake.begin()->Getx(), snake.begin()->Gety()+1));
			break;
		case Snake::LEFT:
			snake.push_front(Point(snake.begin()->Getx() -2, snake.begin()->Gety()));
			break;
		case Snake::RIGHT:
			snake.push_front(Point(snake.begin()->Getx()+2, snake.begin()->Gety()));
			break;
		}
		snake.pop_back();//向前移动后 后面pop出一个点
	}
	bool ChangeDirection(MoveDirection direction)//能否更改方向，若是方向和移动方向相反不可改变方向
	{
		if ((direction + 2) % 4 == _direction)//方向相反
			return false;
		else
		{
			_direction = direction;
			return true;
		}
	}
	void PrintSnake(HANDLE hout)//用point里的方法打印蛇
	{
		for (Point& point : snake)//相当于 for(int i=0;i<snake.size();++I) 遍历蛇身
		{
			Point::SetOutputPostition(point.Getx(), point.Gety(), hout);
			point.Plot(hout);
		}
	}
	bool EatSelf()//判断头是否碰到自身 游戏犯规
	{
		for (Point &point : snake)
		{
			if (point == *snake.begin())
			{
				if (&point == &(*snake.begin()))//忽略 蛇头与蛇身重合的情况
					continue;
				else
					return true;
			}
		}
		return false;
	}
	bool FoodHitSnake(Point &point)//判断随机产生的点是否 产生在蛇身上
	{
		for (Point &foodhitsnake : snake)
		{
			if (point == foodhitsnake)
				return true;
		}
		return false;
	}
	bool HitEdge()//判断是否撞墙
	{
		int x = snake.begin()->Getx();
		int y = snake.begin()->Gety();
		if ((x == 0) || (y == 2) || (x == 78) || (y == 24)) //和默认墙的位置进行比较  
			return true;
		else
			return false;
	}
	Point& Head()//返回蛇头
	{
		return *snake.begin();
	}
	Point& Tail()//返回蛇尾
	{
		return *(snake.end()-1);
	}
	bool Eat(Food& food)
	{
		int Foodx = food.GetPosition().Getx();
		int Foody = food.GetPosition().Gety();
		int Headx = Head().Getx();
		int Heady = Head().Gety();
		bool ToEat = ((Foodx == Headx) && (Foody == (Heady + 1)) && (_direction == MoveDirection::DOWN))
			|| ((Foodx == Headx) && (Foody == (Heady - 1)) && (_direction == MoveDirection::UP))
			|| ((Foodx + 2 == Headx) && (Foody == Heady) && (_direction == MoveDirection::LEFT))
			|| ((Foodx - 2 == Headx) && (Foody == Heady) && (_direction == MoveDirection::RIGHT));
		if (ToEat)
		{
			snake.push_front(food.GetPosition());
			return true;
		}
		return false;
	}
	
private:
	deque<Point> snake;//用一个双端队列来描述蛇 
	MoveDirection  _direction;//方向
};