#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <mysql.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")

void practice8project1()
{
	//连接数据库
	MYSQL mydata;
	mysql_init(&mydata);
	if (NULL != mysql_real_connect(&mydata, "localhost", "root", "123456", "test", 3306, NULL, 0))
		//这里的地址，用户名，密码，端口可以根据自己本地的情况更改
	{
		printf("数据库连接成功！\n");
	}
	else 
	{
		printf("数据库连接失败！\n");
		system("pause");
	}
	MYSQL_RES *res_set;
	if (mysql_real_query(&mydata, "UPDATE p8_p1 SET times=times+1", strlen("UPDATE p8_p1 SET times=times+1")))
		printf("mysql_query1  error!\n");
	else
	{
		if (mysql_real_query(&mydata, "select * from p8_p1", strlen("select * from p8_p1")))
			printf("mysql_query2  error!\n");
		else
		{
			res_set = mysql_store_result(&mydata);
			if (res_set == NULL)
				printf("mysql_store_result error\n");
			else
			{
				MYSQL_ROW row;
				while (row = mysql_fetch_row(res_set))
				{
					printf("程序运行了%s次。\n", row[0]);
				}
			}
			mysql_free_result(res_set);
		}
	}
	mysql_close(&mydata);
	system("pause");
}