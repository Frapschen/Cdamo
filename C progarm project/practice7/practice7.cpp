#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice7project1.h"
#include "practice7project2.h"
#include "practice7project3.h"

int Practice7DisplayMenu();
void practice7()
{
	int key;
	for (;;)
	{
		key = Practice7DisplayMenu();//打开实战1的额功能菜单
		switch (key)
		{
		case 1:
			practice7project1();
			break;
		case 2:
			practice7project2();
			break;
		case 3:
			practice7project3();
			break;
		case 4:
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
int Practice7DisplayMenu()
{
	system("cls");
	int key;
	printf("******************实战七功能菜单****************\n");
	printf("*****        1. 项目1->计数器实现          *****\n");
	printf("*****        2. 项目2->学生学籍管理        *****\n");
	printf("*****        3. 项目3->其他拓展项目        *****\n");
	printf("*****        4.  返回上一级菜单            *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}