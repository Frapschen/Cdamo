#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#define N 5
#define LEN 10
 struct List
{
	char name[10];
	struct List *next;
};
 struct List2
 {
	 int num;
	 struct List2 *next;
 };

void JosephProblem1(char ary[][LEN], int);
void JosephProblem2();
void JosephProblem3();
int Practice4project1DisplayMenu();

void practice4project1()
{
	int key;
	for (;;)
	{
		system("cls");
		key = Practice4project1DisplayMenu();
		switch (key)
		{
		case 1:
			char name[N][LEN];
			int i, k;//k表示数到第K个人是即出队
			printf("请依次输入%d个人名（每个人名不超过10个字）：\n", N);
			for (i = 0; i < N; i++)
				scanf("%s", &name[i]);
			printf("\n请输入数到第几个人退出：");
			scanf("%d", &k);
			JosephProblem1(name, k);
			getch();
			break;
		case 2:
			JosephProblem2();
			getch();
			break;
		case 3:
			JosephProblem3();
			getch();
			break;
		case 4:
			break;
		default:
			printf("输入错误！");
			break;
		}
		if (key == 4)
			break;
	}
}
int Practice4project1DisplayMenu()
{
	system("cls");
	int key;
	printf("******************实战4项目1功能菜单***********\n");
	printf("*****        1. 功能1->普通约瑟夫问题     *****\n");
	printf("*****        2. 功能2->链表约瑟夫问题     *****\n");
	printf("*****        3. 功能3->约瑟夫“密码问题” *****\n");
	printf("*****        4.  返回上一级菜单           *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}
void JosephProblem1(char ary[][LEN], int k)
{
	//普通约瑟夫
	int out = 0;//第几个人出局
	int couter = 0;//数到conter==n时退出
	int idx = -1;
	while (out < N)
	{
		idx++;
		if (idx == N)
			idx = 0;
		if (strcmp(ary[idx], "\0") == 0)
			continue;
		else
		{
			couter++;
			if (couter == k)
			{
				out++;
				printf("第个%d人退出：%s\n", out, ary[idx]);
				strcpy(ary[idx], "\0");
				couter = 0;
			}
		}
	}
}
void JosephProblem2()
{
		char k;
		int num = 0;
		struct List *p = NULL;
		struct List *q = NULL;
		struct List *head = NULL;
		do
		{
			if (head == NULL)
			{
				num++;
				head = (struct List*)malloc(sizeof(struct List));//初始化链表				
				printf("请输入人名：");
				fflush(stdin);
				scanf("%s", head->name);
				head->next = NULL;
				q = head;
			}
			else
			{
				num++;
				p= (struct List*)malloc(sizeof(struct List));
				p->next = NULL;
				q->next= p;//上一个节点连接到这个节点				
				printf("\n请输入人名：");
				fflush(stdin);
				scanf("%s", p->name);
				q = p;
			}
			printf("添加成功，现在有%d个人。按y/Y继续添加，按其他键完成:",num);
			k = getch();
		} while (k=='y'||k=='Y');
		q->next = head;
		struct List *star;
		star = head;
		int key = 0;
		printf("\n游戏开始：\n");
		while (num!=0)
		{
			if (star->name != "\0")
			{
				key++;
				if (key == 3)
				{
					num--;
					printf("\n%s被杀死了", star->name);
					strcpy(star->name, "\0");
					key = 0;
				}
				star = star->next;
			}
			else
				star = star->next;				
		}
}

void JosephProblem3()
{
	char k;
	int num = 0;
	struct List2 *p = NULL;
	struct List2 *q = NULL;
	struct List2 *head = NULL;
	do
	{
		if (head == NULL)
		{
			num++;
			head = (struct List2*)malloc(sizeof(struct List2));//初始化链表				
			printf("请输入数字：");
			fflush(stdin);
			scanf("%d", &head->num);
			head->next = NULL;
			q = head;
		}
		else
		{
			num++;
			p = (struct List2*)malloc(sizeof(struct List2));
			p->next = NULL;
			q->next = p;//上一个节点连接到这个节点				
			printf("\n请输入数字：");
			fflush(stdin);
			scanf("%d", &p->num);
			q = p;
		}
		printf("添加成功，现在有%d个数字。按y/Y继续添加，按其他键完成:", num);
		k = getch();
	} while (k == 'y' || k == 'Y');

	q->next = head;//循环链表
	struct List2 *star;
	star = head;
	int key = 0;
	int target = star->num;


	printf("\n密码是：\n");
	while (num != 0)
	{
		if (star->num !=-1)
		{
			key++;
			if (key == target)
			{
				num--;
				printf("%d  ", star->num);
				target = star->num;
				key = 0;
				star->num = -1;
				
			}
			star = star->next;
		}
		else
			star = star->next;
	}
}







