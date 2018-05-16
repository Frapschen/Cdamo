#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice8project1.h"
#include "practice8project2.h"

#include "practice7project3.h"

int Practice8DisplayMenu();
void practice8()
{
	int key;
	for (;;)
	{
		key = Practice8DisplayMenu();//打开实战1的额功能菜单
		switch (key)
		{
		case 1:
			practice8project1();
			break;
		case 2:
			practice8project2();
			break;
		case 3:
			practice7project3();
			break;
		default:
			printf("输入错误！请按任意键继续.....");
			getch();
			break;
		}
		if (key == 4)
			break;
	}

}
int Practice8DisplayMenu()
{
	system("cls");
	int key;
	printf("******************实战8功能菜单****************\n");
	printf("*****        1. 项目1->程序运行次数       *****\n");
	printf("*****        2. 项目2->学生管理系统       *****\n");
	printf("*****        3. 项目3->图书管理系统       *****\n");
	printf("*****        4.  返回上一级菜单           *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}