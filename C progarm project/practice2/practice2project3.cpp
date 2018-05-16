#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

//猴子分堆桃子
int mceat(int n)
{
	if (n == 5)
		return  5;
	else
		return 5 / 4 * (mceat(++n) + 1);
}
void practice2project3()
{
	printf("最少有：%d个桃子", mceat(1));
	getch();
}