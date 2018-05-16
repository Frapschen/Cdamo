#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"


//猴子吃桃
void practice1project3()
{
	int mun=1;
	int day;
	printf("请输入第几天剩下一个桃子：");
	scanf("%d", &day);
	day--;
	for (; day > 0; day--)
	{
		mun = (mun + 1) * 2;
		printf("第%d天剩下%d个桃子\n", day, mun);
	}
	getch();
}