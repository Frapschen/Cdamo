#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <mysql.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")
MYSQL MYDATE;


//图书管理系统
/*
*实现系统增删改查
*/
typedef struct Bookinfo//图书信息
{
	int bnumber;//书号
	int ISBN;//INSBN码
	char bname[20];//书名
	char writer[20];//作者
	char book_concern[20];//出版社
	int collection;//馆藏量
};

typedef struct	Userinfo
{
	int userid;//借书证号
	char name[20];//姓名
	char sex[4];//性别
	char major[20];//专业
};

typedef struct Lendinfo
{
	int bnumber;//s书号
	int ISBN;//INSBN码
	int userid;//借书证号
	char lendtime[10];//借书时间
};

int initMYSQL();//连接数据库
int display(int n);//菜单
void bookinfo();//图书管理
void userinfo();//用户管理
void rentinfo();//借阅管理 

//入口
void practice7project3()
{
	if (!initMYSQL())
	{
		printf("数据库连接失败！");
		getch();
	}
	else
	{
		int key;
		while (true)
		{
			key = display(1);
			switch (key)
			{
			case 1:
				bookinfo();
				break;
			case 2:
				userinfo();
				break;
			case 3:
				rentinfo();
				break;
			case 4:
				break;
			default:
				printf("输入错误！");
				break;
			}
			if (key == 4)
				break;
		}
	}
	mysql_close(&MYDATE);
}

//连接数据库
int initMYSQL()
{

	int k = 0;
	mysql_init(&MYDATE);
	mysql_options(&MYDATE, MYSQL_SET_CHARSET_NAME, "gbk");
	if (NULL != mysql_real_connect(&MYDATE, "localhost", "root", "123456", "test", 3306, NULL, 0))
	{
		Sleep(1000);
		printf("数据库连接成功...");
		Sleep(500);
		k = 1;
	}
	return k;
}

//菜单
int display(int n)
{
	system("cls");
	int key;
	if (n == 1)
	{
		printf("***********欢迎进入图书管理系统***********\n");
		printf("*              1 图书管理                *\n");
		printf("*              2 用户管理                *\n");
		printf("*              3 借阅管理                *\n");
		printf("*              4 返    回                *\n");
		printf("******************************************\n");
		printf("请选择：");
		scanf("%d", &key);
		return key;
	}
	if (n == 2)
	{
		printf("******************************\n");
		printf("**********1增加信息***********\n");
		printf("**********2删除信息***********\n");
		printf("**********3查询信息***********\n");
		printf("**********4修改信息***********\n");
		printf("**********5返    回***********\n");
		printf("******************************\n");
		printf("请选择：");
		scanf("%d", &key);
		return key;
	}
}

//图书管理
void bookinfo()
{
	Bookinfo bookinfo;
	MYSQL_RES *res_set = NULL;
	MYSQL_ROW row = NULL;
	int key;
	char temp[200];
	system("cls");
	printf("***********图书管理***********\n");
	while (true)
	{
		key = display(2);
		switch (key)
		{
		case 1://增加图书
		{
			printf("请输入书号：");
			scanf("%d", &bookinfo.bnumber);
			printf("请输入ISNB码：");
			scanf("%d", &bookinfo.ISBN);
			printf("请输入书名：");
			scanf("%s", &bookinfo.bname);
			printf("请输入作者：");
			scanf("%s", &bookinfo.writer);
			printf("请输入出版社：");
			scanf("%s", &bookinfo.book_concern);
			printf("请输入馆藏量：");
			scanf("%d", &bookinfo.collection);
			sprintf(temp, 
				"INSERT p7p3Bookinfo VALUE ( '%d','%d','%s','%s','%s','%d')"
				,bookinfo.bnumber, bookinfo.ISBN, bookinfo.bname, bookinfo.writer, bookinfo.book_concern, bookinfo.collection);
			if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
				printf("添加成功！");
			else
				printf("添加失败，错误信息：%s", mysql_error(&MYDATE));
			getch();
			break;
		}
		case 2://删除图书
		{
			printf("请输入你要删除的图书编号：");
			scanf("%d", &bookinfo.bnumber);
			sprintf(temp, "DELETE FROM p7p3Bookinfo WHERE id=%d", bookinfo.bnumber);
			puts(temp);
			if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
			{
				if (mysql_affected_rows(&MYDATE))
					printf("删除成功！");
				else
					printf("没有这个数据！");
			}
			else
				printf("删除失败，错误信息：%s", mysql_error(&MYDATE));
				getch();
			break;
		}
		case 3://查询图书
		{
			mysql_query(&MYDATE, "SELECT *FROM p7p3Bookinfo");
			res_set = mysql_store_result(&MYDATE);
			if (res_set == NULL)
				printf("mysql_store_result error or Empty set\n");
			else
			{
				if (!(row = mysql_fetch_row(res_set)))
					printf("没有数据！");
				else
				{
					printf("书号\tISBN\t书名\t作者\t出版社\t馆藏量\n");
					printf("%-s\t%-s\t%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
					while (row = mysql_fetch_row(res_set))
					{
						printf("%-s\t%-s\t%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
					}
					printf("-------------------------------------------------------------\n");
				}
			}
			mysql_free_result(res_set);
			getch();
			break;
		}
		case 4://修改图书
		{
			printf("请输入你要修改图书的编号：");
			scanf("%d", &key);
			printf("请输入新的书籍信息：\n");
			printf("请输入书号：");
			scanf("%d", &bookinfo.bnumber);
			printf("请输入ISNB码：");
			scanf("%d", &bookinfo.ISBN);
			printf("请输入书名：");
			scanf("%s", &bookinfo.bname);
			printf("请输入作者：");
			scanf("%s", &bookinfo.writer);
			printf("请输入出版社：");
			scanf("%s", &bookinfo.book_concern);
			printf("请输入馆藏量：");
			scanf("%d", &bookinfo.collection);
			sprintf(temp,
				"UPDATE p7p3Bookinfo SET id='%d',ISBN='%d',name='%s',writer='%s',book_concern='%s',collection='%d' WHERE id=%d"
				, bookinfo.bnumber, bookinfo.ISBN, bookinfo.bname, bookinfo.writer, bookinfo.book_concern, bookinfo.collection,key);
			puts(temp);
			if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
			{
				if(mysql_affected_rows(&MYDATE))
					printf("修改成功！\n");
				else
					printf("修改失败，请检查你的输入！\n");
					
			}
			else
				printf("修改失败，错误信息：%s", mysql_error(&MYDATE));
			getch();
			break;
		}
		case 5:
			break;
		default:
			printf("输入错误！");
			break;
		}
		if (key == 5)
			break;
	}
}

////用户管理
void userinfo()
{
	Userinfo userinfo;
	MYSQL_RES *res_set = NULL;
	MYSQL_ROW row = NULL;
	char temp[200];
	system("cls");
	printf("***********图书管理***********\n");
	int key;
	while (true)
	{
		key = display(2);
		switch (key)
		{
		case 1://增加用户
			{
				printf("请输入借阅证：");
				scanf("%d", &userinfo.userid);
				printf("请输入姓名：");
				scanf("%s", &userinfo.name);
				printf("请输入性别：");
				scanf("%s", &userinfo.sex);
				printf("请输入专业：");
				scanf("%s", &userinfo.major);
				sprintf(temp, "INSERT p7p3userinfo VALUE('%d','%s','%s','%s')",
					 userinfo.userid,userinfo.name,userinfo.sex,userinfo.major);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
					printf("添加成功！");
			  	else
					printf("添加失败，错误信息：%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 2://删除用户
			{
				printf("请输入你要删除的用户ID：");
				scanf("%d", &userinfo.userid);
				sprintf(temp, "DELETE FROM p7p3Userinfo WHERE userid=%d", userinfo.userid);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
				{
					if (mysql_affected_rows(&MYDATE))
						printf("删除成功！");
					else
						printf("没有这个数据！");
				}
				else
					printf("删除失败，错误信息：%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 3://查询用户
			{
				mysql_query(&MYDATE, "SELECT *FROM p7p3Userinfo");
				res_set = mysql_store_result(&MYDATE);
				if (res_set == NULL)
					printf("mysql_store_result error or Empty set\n");
				else
				{
					if (!(row = mysql_fetch_row(res_set)))
						printf("没有数据！");
					else
					{
						printf("借书证\t姓名\t性别\t专业\n");
						printf("%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3]);
						while (row = mysql_fetch_row(res_set))
							printf("%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3]);
						printf("-------------------------------------------------------------\n");
					}
				}
				mysql_free_result(res_set);
				getch();
				break;
			}
		case 4://修改用户
			{
				printf("请输入你要修改的借阅证ID：");
				scanf("%d", &key);
				printf("请输入借阅证：");
				scanf("%d", &userinfo.userid);
				printf("请输入姓名：");
				scanf("%s", &userinfo.name);
				printf("请输入性别：");
				scanf("%s", &userinfo.sex);
				printf("请输入专业：");
				scanf("%s", &userinfo.major);
				sprintf(temp, "UPDATE p7p3Userinfo SET userid='%d',name='%s',sex='%s',major='%s'WHERE userid=%d",
					userinfo.userid, userinfo.name, userinfo.sex, userinfo.major,key);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
				{
					if (mysql_affected_rows(&MYDATE))
						printf("修改成功！\n");
					else
						printf("修改失败，请检查你的输入！\n");
				}
				else
					printf("修改失败，错误信息：%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 5:
			break;
		default:
			printf("输入错误！");
			break;
		}
		if (key == 5)
			break;
	}
}

//借阅管理 
void rentinfo()
{
	Lendinfo lendinfo;
	MYSQL_RES *res_set = NULL;
	MYSQL_ROW row = NULL;
	char temp[200];
	system("cls");
	printf("***********借阅管理***********\n");
	int key,key2;
	while (true)
	{
		key = display(2);
		switch (key)
		{
		case 1://增加借阅信息
			{
				printf("请输入书号：");
				scanf("%d", &lendinfo.bnumber);
				printf("请输入ISNB：");
				scanf("%d", &lendinfo.ISBN);
				printf("请输入借书证号：");
				scanf("%d", &lendinfo.userid);
				printf("请输入借书时间：");
				scanf("%s", &lendinfo.lendtime);
				sprintf(temp, "INSERT p7p3Lendinfo VALUE(NULL,'%d','%d','%d','%s')",
					lendinfo.bnumber, lendinfo.ISBN, lendinfo.userid, lendinfo.lendtime);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
					printf("添加成功！");
				else
					printf("添加失败，错误信息：%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 2://删除借阅信息
			{
				printf("请输入你借书证：");
				scanf("%s", &lendinfo.userid);
				printf("请输入你要归还的书的ID：");
				scanf("%d",&lendinfo.bnumber);
				sprintf(temp, "DELETE FROM p7p3Lendinfo WHERE book_number='%d' AND userid='%d'", lendinfo.bnumber, lendinfo.userid);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
					if (mysql_affected_rows(&MYDATE))
						printf("归还成功！");
					else
						printf("没有这个数据！");
				else
					printf("归还失败，错误信息：%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 3://查询借阅信息
			{
				mysql_query(&MYDATE, "SELECT *FROM p7p3Lendinfo");
				res_set = mysql_store_result(&MYDATE);
				if (res_set == NULL)
					printf("mysql_store_result error or Empty set\n");
				else
				{
					if (!(row = mysql_fetch_row(res_set)))
						printf("没有数据！");
					else
					{
						printf("图书ID\t\t图书ISBN\t用户ID\t\t借书时间\n");
						printf("%-8s\t%-8s\t%-8s\t%-8s\n", row[1], row[2], row[3], row[4]);
						while (row = mysql_fetch_row(res_set))
							printf("%-s\t\t%-s\t\t%-s\t\t%-s\n", row[1], row[2], row[3], row[4]);
						printf("-------------------------------------------------------------\n");
					}
				}
				mysql_free_result(res_set);
				getch();
				break;
			}
		case 4://修改借阅信息
			{
				printf("请输入你借书证：");
				scanf("%d", &key);
				printf("请输入你所借书的ID：");
				scanf("%d", &key2);
				printf("开始修改：\n");
				printf("请输入书号：");
				scanf("%d", &lendinfo.bnumber);
				printf("请输入ISNB：");
				scanf("%d", &lendinfo.ISBN);
				printf("请输入借书证号：");
				scanf("%d", &lendinfo.userid);
				printf("请输入借书时间：");
				scanf("%s", &lendinfo.lendtime);
				sprintf(temp, "UPDATE p7p3Lendinfo SET book_number='%d',ISBN='%d',userid='%d',lendtime='%s' WHERE userid='%d' AND book_number='%d'",
					lendinfo.bnumber, lendinfo.ISBN, lendinfo.userid, lendinfo.lendtime, key,key2);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
				{
					if (mysql_affected_rows(&MYDATE))
						printf("修改成功！\n");
					else
						printf("修改失败，请检查你的输入！\n");
				}
				else
					printf("修改失败，错误信息：%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 5:
			break;
		default:
			printf("输入错误！");
			break;
		}
		if (key == 5)
			break;
	}
}
