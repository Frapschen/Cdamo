#include "stdio.h"
#include "stdlib.h"
#include "conio.h"



int Practice3DisplayMenu();
void practice3()
{
	int key;
	for (;;)
	{
		key = Practice3DisplayMenu();//打开实战1的额功能菜单
		switch (key)
		{
		case 1:
			
			break;
		case 2:
			break;
		case 3:

			break;
		case 4:

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
int Practice3DisplayMenu()
{
	system("cls");
	int key;
	printf("***********************************************\n");
	printf("*****        1. 项目1->约瑟夫问题         *****\n");
	printf("*****        2. 项目2->简单四则运算       *****\n");
	printf("*****        3. 项目3->猴子吃桃           *****\n");
	printf("*****        4. 项目4->其他拓展项目       *****\n");
	printf("*****        5.  返回上一级菜单           *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}