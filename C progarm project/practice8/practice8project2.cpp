#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <mysql.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")
MYSQL mydata;

int initmysql();//连接数据库
int display_p8p2();//显示菜单
void adddata();//增加学生
void delatedata();//删除学生
void showtable();//显示菜单
void updata();//修改数据

//入口
void practice8project2()
{
	int key;
	if (!initmysql())
	{
		printf("数据库连接失败！");
		getch();
	}
	else
	{
		while (true)
		{
			key = display_p8p2();
			switch (key)
			{
			case 1:
				adddata();
				break;
			case 2:
				delatedata();
				break;
			case 3:
				updata();
				break;
			case 4:
				showtable();
				getch();
				break;
			case 5:
				break;
			default:
				printf("输入错误,按任意键重新输入！");
				getch();
				break;
			}
			if (key == 5)
				break;
		}
		mysql_close(&mydata);
	}
}

//连接数据库
int initmysql()
{

	int k = 0;
	mysql_init(&mydata);
	mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk");
	if (NULL != mysql_real_connect(&mydata, "localhost", "root", "123456", "test", 3306, NULL, 0))
	{
		Sleep(1000);
		printf("数据库连接成功...");
		Sleep(500);
		k = 1;
	}
	return k;
}

//显示菜单
int display_p8p2()
{
	system("cls");
	int key;
	printf("******************欢迎进入学生管理系统******************\n");
	printf("*****        1. 添加学生                           *****\n");
	printf("*****        2. 删除学生                           *****\n");
	printf("*****        3. 修改学生                           *****\n");
	printf("*****        4. 查询数据                           *****\n");
	printf("*****        5.  返回上一级菜单                    *****\n");
	printf("请输入功能号：");
	scanf("%d", &key);
	return key;
}

//增加学生
void adddata()
{
	char id[15];
	char name[15];
	char sex[8];
	char age[3];
	char score_cp[3], score_en[3], score_math[3];
	printf("请输入学号（字符）：");
	scanf("%s", &id);
	printf("请输入姓名（字符）：");
	scanf("%s", &name);
	printf("请输入性别（字符）：");
	scanf("%s", &sex);
	printf("请输入年龄（整型）：");
	scanf("%s", &age);
	printf("请输入C语言的分数（整型）：");
	scanf("%s", &score_cp);
	printf("请输入英语的分数（整型）：");
	scanf("%s", &score_en);
	printf("请输入数学的分数（整型）：");
	scanf("%s", &score_math);

	char temp[200];
	strcpy(temp, "INSERT student_tbl VALUE(");
	strcat(temp, id);
	strcat(temp, ",'");
	strcat(temp, name);
	strcat(temp, "','");
	strcat(temp, sex);
	strcat(temp, "',");
	strcat(temp, age);
	strcat(temp, ",");
	strcat(temp, score_cp);
	strcat(temp, ",");
	strcat(temp, score_en);
	strcat(temp, ",");
	strcat(temp, score_math);
	strcat(temp, ",");
	strcat(temp, "(score_cp+score_en+score_math)/3)");

	if (!mysql_real_query(&mydata, temp, strlen(temp)))
	{
		printf("添加成功！");
		getch();
	}
	else
	{
		printf("添加失败！错误信息：\s", mysql_error(&mydata));
		
		getch();
	}
}

//删除学生
void delatedata()
{
	showtable();
	char temp[200];
	char id[15];
	printf("\n------------------------------------------------------------\n");
	printf("请输入你要删除学生的学号：");
	scanf("%s", &id);
	strcpy(temp, "DELETE FROM student_tbl WHERE id=");
	strcat(temp, id);
	if (!mysql_real_query(&mydata, temp, strlen(temp)))
	{
		printf("删除成功！");
		getch();
	}
	else
	{
		printf("删除失败！错误信息：%s", mysql_error(&mydata));
		getch();
	}
}

//显示数据
void showtable()
{
	MYSQL_RES *res_set=NULL;
	MYSQL_ROW row=NULL;
	if (mysql_query(&mydata,
		"SELECT *FROM student_tbl"
	))
	{
		printf("失败！错误信息：\s\n", mysql_error(&mydata));
		getch();
	}
	else
	{
		res_set = mysql_store_result(&mydata);
		if (res_set == NULL)
			printf("mysql_store_result error or Empty set\n");
		else
		{
			if (!(row = mysql_fetch_row(res_set)))
			{
				printf("没有数据！");
				getch();
			}
			else
			{
				printf("学号\t\t姓名\t性别\t年龄\tC语言\t英语\t数学\t平均分\n");
				printf("%-s\t%-s\t%-s\t%-s\t%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
				while (row = mysql_fetch_row(res_set))
				{
					printf("%-s\t%-s\t%-s\t%-s\t%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
				}
			}	
		}
	}
	//释放结果集
	mysql_free_result(res_set);
}

//修改数据
void updata()
{
	showtable();
	char oldid[15];
	printf("\n------------------------------------------------------------\n");
	printf("请输入你要修改学生的学号：");
	scanf("%s", &oldid);
	printf("请重新输入信息：");
	char id[15];
	char name[15];
	char sex[8];
	char age[3];
	char score_cp[3], score_en[3], score_math[3];
	printf("请输入学号（字符）：");
	scanf("%s", &id);
	printf("请输入姓名（字符）：");
	scanf("%s", &name);
	printf("请输入性别（字符）：");
	scanf("%s", &sex);
	printf("请输入年龄（整型）：");
	scanf("%s", &age);
	printf("请输入C语言的分数（整型）：");
	scanf("%s", &score_cp);
	printf("请输入英语的分数（整型）：");
	scanf("%s", &score_en);
	printf("请输入数学的分数（整型）：");
	scanf("%s", &score_math);
	char temp[200];
	strcpy(temp, "UPDATE student_tbl SET ");
	strcat(temp, "id="); strcat(temp, id); strcat(temp, ",");
	strcat(temp, "name="); strcat(temp, "'"); strcat(temp, name); strcat(temp, "'"); strcat(temp, ",");
	strcat(temp, "sex=");  strcat(temp, "'");  strcat(temp, sex); strcat(temp, "'"); strcat(temp, ",");
	strcat(temp, "age="); strcat(temp, age); strcat(temp, ",");
	strcat(temp, "score_cp="); strcat(temp, score_cp); strcat(temp, ",");
	strcat(temp, "score_en="); strcat(temp, score_en); strcat(temp, ",");
	strcat(temp, "score_math="); strcat(temp, score_math); strcat(temp, ",");
	strcat(temp, "score_averge=(score_cp+score_en+score_math)/3 ");
	strcat(temp, "WHERE id=");
	strcat(temp, oldid); 
	if (!mysql_real_query(&mydata, temp, strlen(temp)))
	{
		printf("修改成功！\n");
		getch();
	}
	else
	{
		printf("修改失败，错误信息：%s", mysql_error(&mydata));
		getch();
	}
}
