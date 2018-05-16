#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice4project1.h"
#include "practice4project2.h"
#include "practice4project3.h"
#include "practice4project4.h"
int Practice4DisplayMenu();
void practice4()
{
	int key;
	for (;;)
	{
		key = Practice4DisplayMenu();//打开实战4的额功能菜单
		switch (key)
		{
		case 1:
			practice4project1();
			break;
		case 2:
			practice4project2();
			break;
		case 3:
			practice4project3();
			break;
		case 4:
			practice4project4();
			getch();
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
int Practice4DisplayMenu()
{
	system("cls");
	int key;
	printf("******************实战4功能菜单****************\n");
	printf("*****        1. 项目1->约瑟夫问题         *****\n");
	printf("*****        2. 项目2->字符串排序问题     *****\n");
	printf("*****        3. 项目3->字符串分类统计     *****\n");
	printf("*****        4. 项目4->拓展项目           *****\n");
	printf("*****        5.  返回上一级菜单           *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}