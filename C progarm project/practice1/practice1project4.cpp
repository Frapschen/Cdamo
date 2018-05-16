#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"

int mc(long n, long i)
{
	if (n == i)
		return 1;
	else
		return (mc(n + 1, i) + 1)*(mc(n + 1, i) + 1);
}

void practice1project4()
{
	int i;
	printf("请输入吃完的时间：");
	scanf("%ld", &i);
	printf("猴子摘了%d个", mc(0, i));
	getch();
}

