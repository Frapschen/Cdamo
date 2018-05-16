#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define LEN 100
int lc = 0,uc = 0,d = 0, s = 0, o = 0;
void count(char ary[]);
//字符串统计
void practice4project3()
{
	char ary[LEN + 1];
	printf("请输入100个以内的任意字符\n");
	printf("程序将按大小写字母、数字、空格和其他字符进行统计。\n");
	printf("如果超出100个字符，程序将只对前100个字符进行统计：\n");
	char ch;
	while ((ch = getchar()) != EOF && ch != '\n')
	{
		;
	}
	gets_s(ary);
	puts(ary);
	count(ary);
	printf("小写字母：%d\n", lc);
	printf("大写字母：%d\n", uc);
	printf("0－9数字：%d\n", d);
	printf("空格：%d\n", s);
	printf("其他字符：%d\n", o);
	printf("按任意键退出...");
	getchar();

}
void count(char ary[])
{
	int i = 0;
	char c;
	while (ary[i])
	{
		c = ary[i];
		if (c >= '0'&& c <= '9')
			d++;
		else if (c >= 'a' && c <= 'z')
			lc++;
		else if (c >= 'A' &&c <= 'Z')
			uc++;
		else if (c == ' ')
			s++;
		else
			o++;
		i++;
	}
}