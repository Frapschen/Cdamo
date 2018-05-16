#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"

int TriangleJudgmentDisplayMnue();

void practice1project1()
{
	    float a, b, c;
		printf("请输入三条边（以空格隔开）：");
		scanf("%f%f%f", &a, &b, &c);
		if ((a + b) < c || (a + c) < b || (b + c) < a)
		{
			printf("不能构成三角形,，按任意键继续...\n");
			getch();
		}
	    else
		{
			printf("能构成三角形\n");
			//让c最大
			float temp;
			if (a>b)//找到a b中最大的
			{
				temp = b;
				b = a;
				a = temp;
			}
			if (b > c)//再找到b c中最大的
			{
				temp = c;
				c = b;
				b = temp;
			}
			int key;
			for (;;)
			{
				key = TriangleJudgmentDisplayMnue();
				switch (key)
				{
				case 1:
					if ((a*a + b * b) == c * c)
						printf("直角三角形，按任意键继续...\n");
					else
						printf("不是直角三角形，按任意键继续...\n");
					getch();
					break;
				case 2:
					if (a == b)
						printf("等腰三角形，按任意键继续...\n");
					else
						printf("不是等腰三角形，按任意键继续...\n");
					getch();
					break;
				case 3:
					if (a == b && a == c && b == c)
						printf("等边三角形，按任意键继续...\n");
					else
						printf("不是等边三角形，按任意键继续...\n");
					getch();
					break;
				case 4:
					temp = (a + b + c) / 2;
					printf("面积为：%f，按任意键继续...", sqrt(temp*(temp - a)*(temp - b)*(temp - c)));
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
}
int TriangleJudgmentDisplayMnue()
{
	system("cls");
	int key;
	printf("******************实战1->项目1*****************\n");
	printf("*****        1. 判断是否是直角三角形      *****\n");
	printf("*****        2. 判断是否是等腰三角形      *****\n");
	printf("*****        3. 判断是否是等边三角形      *****\n");
	printf("*****        4. 计算三角形的面积          *****\n");
	printf("*****        5.  返回上一级菜单           *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}
