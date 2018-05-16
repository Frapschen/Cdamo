#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice2project1.h"
#include "practice2project2.h"
#include "practice2project3.h"
int Practice2DisplayMenu();
void practice2()
{
	int key;
	for (;;)
	{
		key = Practice2DisplayMenu();//打开实战1的额功能菜单
		switch (key)
		{
		case 1:
			practice2project1();
			break;
		case 2:
			practice2project2();
			break;
		case 3:
			practice2project3();
			break;
		case 4:
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
int Practice2DisplayMenu()
{
	system("cls");
	int key;
	printf("******************实战2功能菜单****************\n");
	printf("*****        1. 项目1->猴子吃桃问题       *****\n");
	printf("*****        2. 项目2->汉诺塔问题         *****\n");
	printf("*****        3. 项目3->拓展项目猴子吃桃   *****\n");
	printf("*****        4.  返回上一级菜单           *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}