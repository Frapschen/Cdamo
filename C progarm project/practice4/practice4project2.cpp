#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string"

#define N 50 //单词数上限
#define M 26 //单词长度上限

int Practice4project2DisplayMenu();
void print(const char word[][M], int);
void stringsort1(char word[][M], int n);
void stringsort2(char word[][M], int n);
void stringsort3(char word[][M], int n);
void practice4project2()
{
	int key;
	for (;;)
	{
		system("cls");
		key = Practice4project2DisplayMenu();
		     
		char word[N][M];
		int m = M - 1;
		int count = N;
		int n = 0, i;
		switch (key)
		{
		case 1:
			//控制输入的单词数在1-50之间
			while (n < 1 || n>50)
			{
				printf("请输入你将要输入的单词数：(1-%d)\n", count);
				scanf("%d", &n);
			}
			printf("请输入%d个单词，以空格分开\n(单词长度不超过%d,若超出，程序会自动忽略超出部分)\n", n, m);
			for (i = 0; i < n; i++)
			{
				scanf("%s", &word[i]);
				word[i][M - 1] = '\0';
			}
			stringsort1(word, n);
			printf("排序结果为：\n");
			print(word, n);
			getch();
			break;
		case 2:
			//控制输入的单词数在1-50之间
			while (n < 1 || n>50)
			{
				printf("请输入你将要输入的单词数：(1-%d)\n", count);
				scanf("%d", &n);
			}
			printf("请输入%d个单词，以空格分开\n(单词长度不超过%d,若超出，程序会自动忽略超出部分)\n", n, m);
			for (i = 0; i < n; i++)
			{
				scanf("%s", &word[i]);
				word[i][M - 1] = '\0';
			}
			stringsort2(word, n);
			stringsort1(word, n);
			printf("排序结果为：\n");
			print(word, n);
			getch();
			break;
		case 3:
			//控制输入的单词数在1-50之间
			while (n < 1 || n>50)
			{
				printf("请输入你将要输入的单词数：(1-%d)\n", count);
				scanf("%d", &n);
			}
			printf("请输入%d个单词，以空格分开\n(单词长度不超过%d,若超出，程序会自动忽略超出部分)\n", n, m);
			for (i = 0; i < n; i++)
			{
				scanf("%s", &word[i]);
				word[i][M - 1] = '\0';
			}
			stringsort3(word, n);
			printf("排序结果为：\n");
			print(word, n);
			getch();
			break;
		case 4:
			;
		default:
			printf("输入错误！");
			break;

		}
		if (key == 4)
			break;
	}
}

int Practice4project2DisplayMenu()
{
	system("cls");
	int key;
	printf("******************实战4项目2功能菜单*************\n");
	printf("*****        1. 功能1->字符串排序问题       *****\n");
	printf("*****        2. 功能2->大小写不敏感字符排序 *****\n");
	printf("*****        3. 功能3->单词进行排序(非插入) *****\n");
	printf("*****        4.  返回上一级菜单             *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}

void stringsort1(char word[][M], int n)
{
	char key[M];
	int i, j;
	for (i = 1; i < n; i++)
	{
		strcpy(key, word[i]);
		j = i;
		while (j >= 1 && 1 == strcmp(word[j - 1], key))
		{
			strcpy(word[j], word[j - 1]);
			j--;
		}
		strcpy(word[j], key);
	}
}

void stringsort2(char word[][M],int n)
{
	char key[M];
	//大写换成小写
	for (int i = 0; i < n; i++) 
	{
		strcpy(key, word[i]);	
			for (int k = 0; word[i][k] != '\0'; k++)
				if (word[i][k] >= 'A'&&word[i][k] <= 'Z')
			                word[i][k] += 32;
	}
	int len;
	for (int i=0; i < n; i++)
	{
		len = strlen(word[i]);
		if (!(word[i][len - 1] >= 'a'&&word[i][len - 1] <= 'z'))
			word[i][len - 1] = '\0';
	}
}

void stringsort3(char word[][M], int n)
{
	char key[M];
	int i, j,c;
	for (i = 0; i < n - 1; i++)
	{
		strcpy(key, word[i]);
		for(j=i;j<n;j++)
			if (strcmp(key, word[j])>0)//key 大
			{
				c = j;
				strcpy(key, word[j]);
			}
		strcpy(word[c], word[i]);
		strcpy(word[i], key);
		
	}
}
void print(const char word[][M], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s\n", word[i]);	
}