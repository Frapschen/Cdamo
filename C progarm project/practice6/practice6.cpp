#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice6project1.h"
#include "practice6project2.h"
#include "practice6project3.h"
#include "practice6project4.h"
int Practice6DisplayMenu();
void practice6()
{
	int key;
	for (;;)
	{
		key = Practice6DisplayMenu();//打开实战1的额功能菜单
		switch (key)
		{
		case 1:
			practice6project1();
			break;
		case 2:
			practice6project2();
			break;
		case 3:
			practice6project3();
			break;
		case 4:
			practice6project4();
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
int Practice6DisplayMenu()
{
	system("cls");
	int key;
	printf("******************实战6功能菜单******************\n");
	printf("*****        1. 项目1->约瑟夫问题（指针实现)*****\n");
	printf("*****        2. 项目2->学生信息登记管理     *****\n");
	printf("*****        3. 项目3->贪吃蛇               *****\n");
	printf("*****        4. 项目4->其他拓展项目         *****\n");
	printf("*****        5.  返回上一级菜单             *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}