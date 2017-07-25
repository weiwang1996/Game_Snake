#pragma once
#include"point.h"
#include"food.h"
#include<deque>
#include<iostream>
using namespace std;
class Snake
{
public:
	enum MoveDirection{ UP, LEFT, DOWN, RIGHT };//��ö�����������ƶ����ĸ�����
	Snake()//��ʼ���� �涨�߿�ʼֻ���������ȣ����������ƶ�
	{
		snake.push_back(Point(18, 16));
		snake.push_back(Point(16, 16));
		_direction = MoveDirection::UP;
	}
	//�ƶ�һ���ռ�һ�� ���µĵ㼯��
	void Move()
	{
		switch (_direction)//���ݴ�ʱ�ķ������жϸ�����ƶ���ֻ����ͷ��β
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
		snake.pop_back();//��ǰ�ƶ��� ����pop��һ����
	}
	bool ChangeDirection(MoveDirection direction)//�ܷ���ķ������Ƿ�����ƶ������෴���ɸı䷽��
	{
		if ((direction + 2) % 4 == _direction)//�����෴
			return false;
		else
		{
			_direction = direction;
			return true;
		}
	}
	void PrintSnake(HANDLE hout)//��point��ķ�����ӡ��
	{
		for (Point& point : snake)//�൱�� for(int i=0;i<snake.size();++I) ��������
		{
			Point::SetOutputPostition(point.Getx(), point.Gety(), hout);
			point.Plot(hout);
		}
	}
	bool EatSelf()//�ж�ͷ�Ƿ��������� ��Ϸ����
	{
		for (Point &point : snake)
		{
			if (point == *snake.begin())
			{
				if (&point == &(*snake.begin()))//���� ��ͷ�������غϵ����
					continue;
				else
					return true;
			}
		}
		return false;
	}
	bool FoodHitSnake(Point &point)//�ж���������ĵ��Ƿ� ������������
	{
		for (Point &foodhitsnake : snake)
		{
			if (point == foodhitsnake)
				return true;
		}
		return false;
	}
	bool HitEdge()//�ж��Ƿ�ײǽ
	{
		int x = snake.begin()->Getx();
		int y = snake.begin()->Gety();
		if ((x == 0) || (y == 2) || (x == 78) || (y == 24)) //��Ĭ��ǽ��λ�ý��бȽ�  
			return true;
		else
			return false;
	}
	Point& Head()//������ͷ
	{
		return *snake.begin();
	}
	Point& Tail()//������β
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
	deque<Point> snake;//��һ��˫�˶����������� 
	MoveDirection  _direction;//����
};