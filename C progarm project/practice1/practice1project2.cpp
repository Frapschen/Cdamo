#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"



void practice1project2()
{
	float a, b;
	char mm, y;
	printf("--------简单计算器-----------\n");
	do
	{
		setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区  
		printf("是否进行高级运算（y/n）");
		char x = getchar();
		if (x == 'n')
		{
			printf("请输入两个操作数和运算符:");
			scanf("%f%c%f", &a, &mm, &b);
			switch (mm)
			{
			case '+':
				printf("%f+%f=%.2f\n", a, b, a + b);
				break;
			case '-':
				printf("%f-%f=%.2f\n", a, b, a - b);
				break;
			case '*':
				printf("%f*%f=%.2f\n", a, b, a*b);
				break;
			case '/':
				if (b == 0)
				{
					printf("被除数不能为零\n");
					break;
				}
				printf("%f/%f=%.2f\n", a, b, a / b);
				break;
			default:
				printf("输入有错");
			}
			getchar();
			printf("按“y”继续，按其他键结束");
			scanf("%c", &y);
		}
		else
		{
			setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
			printf("请选择你要进行的运算：");
			printf("开平方根按：s ；求倒：d ；幂次方：f ；");
			char xx = getchar();

			switch (xx)
			{
			case 's':
				printf("请输入被开方数：");
				scanf("答案为：%f", &a);
				b = sqrt(a);
				printf("%.4f", b);
				break;
			case 'd':
				printf("请输入要求倒的数：");
				scanf("答案为：%f", &a);
				if (0 == a)
				{
					printf("输入错误！");
					break;
				}
				b = 1 / a;
				printf("%.4f", b);
				break;
			case 'f':
				printf("请输入底和幂：");
				scanf("%f%f", &a, &b);
				printf("答案为：%.4f", pow(a, b));
				break;
			default:
				printf("输入错误！");
			}
			setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区  
			printf("按“y”继续，按其他键结束");
			y = getch();
			//setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区  
		}
	} while (y == 'y');
}