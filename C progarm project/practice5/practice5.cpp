#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice5project1.h"
#include "practice5project2.h"
#include "practice5project3.h"
int Practice5DisplayMenu();
void practice5()
{
	int key;
	for (;;)
	{
		key = Practice5DisplayMenu();//打开实战5的额功能菜单
		switch (key)
		{
		case 1:
			practice5project1();
			break;
		case 2:
			practice5project2();
			break;
		case 3:
			practice5project3();
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
int Practice5DisplayMenu()
{
	system("cls");
	int key;
	printf("******************实战5功能菜单****************\n");
	printf("*****        1. 项目1->学生信息登记管理   *****\n");
	printf("*****        2. 项目2->火车票系统         *****\n");
	printf("*****        3. 项目3->其他拓展项目       *****\n");
	printf("*****        5.  返回上一级菜单           *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}