//系统头文件
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

//自定义头文件
#include "HeadFile/practice1.h"
#include "HeadFile/practice2.h"
#include "HeadFile/practice3.h"
#include "HeadFile/practice4.h"
#include "HeadFile/practice5.h"
#include "HeadFile/practice6.h"
#include "HeadFile/practice7.h"
#include "HeadFile/practice8.h"

int MainDisplayMenu();//显示操作界面

int main()
{
	int key;//设置监视哨
	for (;;)
	{
		key = MainDisplayMenu();//整个项目的主流程菜单
		switch (key)
		{
		case 1:
			practice1();		
			break;
		case 2:
			practice2();
			break;
		case 3:
			practice3();
			break;
		case 4:
			practice4();
			break;
		case 5:
			practice5();
			break;
		case 6:
			practice6();
			break;
		case 7:
			practice7();
			break;
		case 8:
			practice8();
			break;
		case 9:
			printf("谢谢使用！");
			getch();
			exit(0);
		default:
			printf("输入错误！请按任意键继续.....");
			getch();
			break;
		}
	}
	return 0;
}
void MainDisplay()
{

}

int  MainDisplayMenu()
{
	int key;
	system("cls");
	printf("**********《C语言综合实战项目》主菜单**********\n");
	printf("*****        1. 进入实战1模块展示         *****\n");
	printf("*****        2. 进入实战2模块展示         *****\n");
	printf("*****        3. 进入实战3模块展示         *****\n");
	printf("*****        4. 进入实战4模块展示         *****\n");
	printf("*****        5. 进入实战5模块展示         *****\n");
	printf("*****        6. 进入实战6模块展示         *****\n");
	printf("*****        7. 进入实战7模块展示         *****\n");
	printf("*****        8. 进入实战8模块展示         *****\n");
	printf("*****        9. 退出                      *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}
