#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include <time.h>
#include "math.h"
#include <graphics.h>      // 引用图形库头文件

#define SNAKEADD 15
#define SIDE 15

TCHAR snakehead[] = _T("■");
TCHAR snakebody[] = _T("□");
TCHAR snakfood[] = _T("@");
typedef struct Snake
{
	int x;
	int y;
	Snake *prev;
	Snake *next;
};

typedef struct Food
{
	int x;
	int y;
};
void food(int num[]);//重新食物
void addlength(Snake *head);//添加蛇身

void practice6project3()
{
	initgraph(600, 600);//初始化图形界面
	//画出边框
	POINT pts[] = { { 4, 4 },{ 591, 4 },{ 591,591 },{ 4, 591 } };
	polygon(pts, 4);
	//初始化链表
	//*****************************************************
	Snake *head = NULL;
	Snake *p = NULL;
	Snake *q = NULL;
	head = (Snake*)malloc(sizeof(Snake));
	head->x = 300;
	head->y = 300;
	head->next = NULL;
	head->prev = NULL;
	q = head;
	//*********************************************************

	Snake *start = head;
	char c = 'a',c2;//蛇的移动方向控制
	int key1 = 0;//判断蛇撞墙
	int key2 = 0;//判断蛇撞到自己
	int hx, hy;//收集蛇头移动后的位置，判断是否撞到自己
	int prex, prey;//收集蛇头移动前的位置
	int temp[4];//收收集蛇身位置
	int eat = 1;//蛇是否吃到食物
	int eat2 = 0;
	int num[2];//食物的位置
	int distamce1;//蛇头吃到自己
	int distamce2;//蛇头与食物的距离

				 //food(num);//第一次出现食物

				 //主循环
	while (true)
	{
		clearrectangle(5, 5, 590, 590);//清空

		if (eat == 1)
		{
			if (eat2 == 1)
				addlength(head);
			food(num);
			eat = 0;
			eat2 = 0;
		}
		//画出食物
		outtextxy(num[0], num[1], snakfood);
		//蛇移动
		start = head;//找到头指针

	  //蛇没有撞墙
		if (start->x <585 && start->x>5 && start->y<585 && start->y>5)
		{
			//记录蛇头旧位置
			prex = start->x;
			prey = start->y;
			//**************************************************************************************
			//接收键盘消息并处理
			{
				if (kbhit())//是否换方向
					c2 = getch();
				//去掉错误的行走放向
				switch (c2)
				{
				case 'w':
					if (c == 's')
						;
					else
						c = c2;
					break;
				case 'a':
					if (c == 'd')
						;
					else
						c = c2;
					break;
				case 's':
					if (c == 'w')
						;
					else
						c = c2;
					break;
				case 'd':
					if (c == 'a')
						;
					else
						c = c2;
					break;
				}
				//改变方向
				switch (c)
				{
				case 'w':
					head->y -= SNAKEADD;
					break;
				case 'a':
					head->x -= SNAKEADD;
					break;
				case 's':
					head->y += SNAKEADD;
					break;
				case 'd':
					head->x += SNAKEADD;
					break;
				default:
					break;
				}
			}
			//**************************************************************************************
			
			hx = start->x;
			hy = start->y;
			//******************************************************
			//在这里判断蛇吃到自己			
			//while (start->next != NULL)
			//{
			//	if (hx == start->x& hy == start->y)
			//	{
			//		TCHAR bb[] = _T("游戏结束！");
			//		outtextxy(300, 300, bb);
			//		key2 = -1;
			//	}
			//	start = start->next;
			//}
			//******************************************************
			distamce2 = (int)sqrt(((int)pow(((num[0] * 2 + 15) / 2 - (head->x * 2 + 15) / 2), 2)) + ((int)pow(((num[1] * 2 + 15) / 2 - (head->y * 2 + 15) / 2), 2)));
			//是否吃到食物
			if (distamce2 <= 15)
			{
				eat = 1;
				eat2 = 1;
			}
			//*****************************************************************
			//蛇没有撞墙且蛇没有撞到自己的情况下移动蛇身
			if (key2 != -1)
			{
				start->x = prex;//让蛇头还原到上一个位置
				start->y = prey;
				temp[0] = start->x;
				temp[1] = start->y;
				start = start->next;
				while (start != NULL)//有蛇身 就换数据
				{
					//先把自己的数据存好
					temp[2] = start->x;
					temp[3] = start->y;

					//把上个节点数据下放
					start->x = temp[0];
					start->y = temp[1];

					temp[0] = temp[2];
					temp[1] = temp[3];
					start = start->next;
				}
				//回复蛇头到移动后的位置
				start = head;
				start->x = hx;
				start->y = hy;
			}

			//*****************************************************************
			//画出蛇
			if (key2 != -1)
			{
				outtextxy(start->x, start->y, snakehead);
				start = start->next;
				while (start != NULL)
				{
					outtextxy(start->x, start->y, snakebody);
					start = start->next;
				}
			}
			//*****************************************************************
		}
		//蛇撞墙
		else
		{
			TCHAR aa[] = _T("游戏结束！");
			outtextxy(300, 300, aa);
			key1 = -1;
		}

		//游戏要出口
		if (key1 == -1 || key2 == -1)
			break;
		Sleep(200);
	}
	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
}

//食物在范围内
void food(int num[])
{
	srand((unsigned)time(NULL));
	do
	{
		num[0] = rand() % 590;
		num[1] = rand() % 590;
	} while (!(num[0]<580 && num[0]>10 && num[1]<580 && num[1]>10));
}
//添加蛇身
void addlength(Snake *head)
{
	Snake *start = head;
	while (start->next != NULL)
		start = start->next;
	Snake *n = (Snake*)malloc(sizeof(Snake));
	n->next = NULL;

	n->prev = start;//链接前一个节点
	start->next = n;

}