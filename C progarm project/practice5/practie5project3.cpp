#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"


struct date {
	int year;
	int month;
	int day;
} date;


void practice5project3()
{
	int sum = 0, tag;
	printf("请输入年月日：\n");
	scanf("%d%d%d", &date.year, &date.month, &date.day);
	switch (date.month) {   //先计算月份前面的月份有多少天（不考虑闰年）
	case 1:
		sum = 0;
		break;
	case 2:
		sum = 31;
		break;
	case 3:
		sum = 59;
		break;
	case 4:
		sum = 90;
		break;
	case 5:
		sum = 120;
		break;
	case 6:
		sum = 151;
		break;
	case 7:
		sum = 181;
		break;
	case 8:
		sum = 212;
		break;
	case 9:
		sum = 243;
		break;
	case 10:
		sum = 273;
		break;
	case 11:
		sum = 304;
		break;
	case 12:
		sum = 334;
		break;
	default:
		printf("the month error");
		exit(1);
	}
	//这里可以写一些日的合法判断
	sum += date.day;  //加上本月的日期数
	if (date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 != 0))  //闰年
		tag = 1;
	else
		tag = 0;
	if (tag == 1 && date.month > 2)   //是闰年  月份大于2月   天数加一天
		sum++;
	printf("这天是当年的第 %d 天。\n", sum);
	getch();
	getch();
}