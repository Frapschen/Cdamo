#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice1project1.h"
#include "practice1project2.h"
#include "practice1project3.h"
#include "practice1project4.h"




int Practice1DisplayMenu();
void practice1()
{
	int key;
	for (;;)
	{
		key = Practice1DisplayMenu();//打开实战1的功能菜单
		switch (key)
		{
		case 1:
			practice1project1();
			break;
		case 2:
			practice1project2();
			break;
		case 3:
			practice1project3();
			break;
		case 4:
			practice1project4();
			break;
		case 5:
			key = 0;
			break;
		default:
			printf("输入错误！请按任意键继续.....");
			getch();
			break;
		}
		if (key == 0)
			break;
	}
		
}
int Practice1DisplayMenu()
{
	system("cls");
	int key;
	printf("******************实战1功能菜单****************\n");
	printf("*****        1. 项目1->三角形相关判断     *****\n");
	printf("*****        2. 项目2->简单四则运算       *****\n");
	printf("*****        3. 项目3->猴子吃桃           *****\n");
	printf("*****        4. 项目4->其他拓展项目       *****\n");
	printf("*****        5.  返回上一级菜单           *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}