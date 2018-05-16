#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

struct List2
{
	int num;
	char name[11];
	struct List2 *next;
};

void JosephProblem3();
int p6p1Display();
void look(List2 *head,int num);//遍历
void restar(List2 *head,int num);//重新输入
void play(List2 *head,int num);
void practice6project1()
{
	char k;
	int num = 0;
	struct List2 *p = NULL;
	struct List2 *q = NULL;
	struct List2 *head = NULL;

	printf("开始：\n");
	do
	{
		if (head == NULL)
		{
			num++;
			head = (struct List2*)malloc(sizeof(struct List2));//初始化链表				
			printf("名字和密码：");
			fflush(stdin);
			scanf("%s%d", &head->name, &head->num);
			head->next = NULL;
			q = head;
		}
		else
		{
			num++;
			p = (struct List2*)malloc(sizeof(struct List2));
			p->next = NULL;
			q->next = p;//上一个节点连接到这个节点		
			printf("\n名字和密码：");
			fflush(stdin);
			scanf("%s%d", &p->name, &p->num);
			q = p;
		}
		printf("添加成功，现在有%d个人。按y/Y继续添加，按其他键完成:", num);
		k = getch();
	} while (k == 'y' || k == 'Y');
	q->next = head;//循环链表
	fflush(stdin);
	List2 * h1 = head;
	List2 * h2 = head;
	List2 * h3 = head;
	int key;
	while (true)
	{
		system("cls");
		key = p6p1Display();
		switch (key)
		{
		case 1:
			
			look(h1, num);
			break;
		case 2:
			
			restar(h2,num);
			break;
		case 3:
			
			play(h3,num);
			break;
		case 4:
			break;
		default:
			printf("输入错误！");
			getch();
			break;
		}
		if (key == 4)
			break;
	}
}


int p6p1Display()
{
	int k;
	printf("==========================================\n");
	printf("1.显示信息\n");
	printf("2.重新输入密码\n");
	printf("3.开始“数N退出”\n");
	printf("4.返回上一级菜单\n");
	printf("==========================================\n");
	printf("请选择：");
	scanf("%d", &k);
	return k;
}

void look(List2 *head,int num)//显示数据
{
	printf("数据如下：\n");
	for (int i = 0; i < num; i++)
	{
		printf("%s\t%d\n", head->name, head->num);
		head = head->next;
	}
	getch();
}

void restar(List2 *head,int num)//重新输入密码
{
	printf("开始重新输入：\n");
	printf("===============================================\n");
	for (int i = 0; i < num; i++)
	{
		printf("%s\t", head->name);
		scanf("%d", &head->num);
		head = head->next;
	}
	printf("输入完成！");
	getch();
}



void play(List2 *head,int num)//开始游戏
{
	char k;
	struct List2 *star;
	star = head;
	int key = 0;
	int target = star->num;


	printf("\n游戏开始：\n");
	while (num != 0)
	{
		if (star->num != -1)
		{
			key++;
			if (key == target)
			{
				num--;
				printf("%s\t%d\n", star->name, star->num);
				target = star->num;
				key = 0;
				star->num = -1;

			}
			star = star->next;
		}
		else
			star = star->next;
	}
	getch();
}