#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

void practice7project1()
{
	int count = 1;
	int key = 0;
	FILE *fp;
	if ((fp = fopen("practice7project1.dat", "r")) != NULL)//文件已经存在，进行count++
	{
		//读出数据
		fscanf(fp, "%d", &count);
		fclose(fp);//关闭只读
		//启动写入数据
		fp = fopen("practice7project1.dat", "w");
		count++;
		fprintf(fp, "%d", count);
		fclose(fp);
	}
	else if ((fp = fopen("practice7project1.dat", "w+")) == NULL)//第一次打开文件
	{
		printf("程序出错");
		getch();
		key = -1;
		if (key != -1)
		{
			fprintf(fp, "%d", count);
		}
	}
	if (key !=-1)
	{
		printf("这个程序运行%d次", count);
		getch();
	}
}