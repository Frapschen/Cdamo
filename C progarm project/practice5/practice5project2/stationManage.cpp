#include "ticket.h"


//站点管理
int  stmDisplay();//显示菜单
void foundstation(Station &station, Ticket &ticket, Book &book);//查询站点
void addstation(Station &station, Ticket &ticket, Book &book);//增加站点
void changestation(Station &station, Ticket &ticket, Book &book);//修改站点
void delatestation(Station &station, Ticket &ticket, Book &book);//删除站点			

void stationManage(Station &station, Ticket &ticket, Book &book)
{
	int key;//显示菜单;
	while (true)
	{
		system("cls");
		key = stmDisplay();
		switch (key)
		{
		case 1:
			foundstation(station, ticket, book);//查询站点
			break;
		case 2:
			addstation(station, ticket, book);//增加站点
			break;
		case 3:
			changestation(station, ticket, book);//修改站点
			break;
		case 4:
			delatestation(station, ticket, book);//删除站点
			break;
		case 0:
			//返回上一级菜单
			break;
		}
		if (key == 0)
			break;
	}
}

//显示菜单
int stmDisplay()
{
	int key;
	printf("\t\t******************************\n");
	printf("\t\t\t查询站点----------------1\n");
	printf("\t\t\t增加站点----------------2\n");
	printf("\t\t\t修改站点----------------3\n");
	printf("\t\t\t删除站点----------------4\n");
	printf("\t\t\t返回上一级菜单----------0\n");
	printf("\t\t******************************\n");
	printf("\t\t请选择：");
	scanf("%d", &key);
	return key;
}

//查询站点
void foundstation(Station &station, Ticket &ticket, Book &book)
{
	printf("车站号\t起点\t终点\t车次\t    日期\t时间\t 票数\t 价格\n");
	for (int i = 0; i < station.count; i++)
	{
		printf("%-4d\t%-4s\t%-4s\t %-4s\t %-8s\t%-4s\t  %-4d\t %-4d\n",station.station[i].stationId, station.station[i].from, station.station[i].to, station.station[i].trainId, station.station[i].data, station.station[i].time, station.station[i].numbers, station.station[i].money);
	}
	getch();
}

//增加站点
void addstation(Station &station, Ticket &ticket, Book &book)
{
	printf("------------------------------------------------------------------------\n");
	printf("请添加站点：\n");
	printf("------------------------------------------------------------------------\n");
	printf("请输入站点号：");
	scanf("%d", &station.station[station.count].stationId);
	printf("请输入起始站台：");
	scanf("%s", &station.station[station.count].from);
	printf("请输入终点站台：");
	scanf("%s", &station.station[station.count].to);
	printf("请输入车费：");
	scanf("%d", &station.station[station.count].money);
	printf("请输入票数：");
	scanf("%d", &station.station[station.count].numbers);
	printf("请添加票务信息：\n");
	printf("列车车次(整型)：");
	scanf("%s", &station.station[station.count].trainId);
	printf("列车出发日期：");
	scanf("%s", &station.station[station.count].data);
	printf("请输入时间：");
	scanf("%s", &station.station[station.count].time);
	station.count++;
	printf("**车站信息添加成功！\n");
	printf("------------------------------------------------------------------------\n");
	getch();
}

//修改站点
void changestation(Station &station, Ticket &ticket, Book &book)
{
	int key;
	printf("请输入你要修改的站点号：");
	scanf("%d", &key);
	for(int i=0;i<station.count;i++)
		if (key == station.station[i].stationId)
		{
			printf("------------------------------------------------------------------------\n");
			printf("请重新输入此站点的内容：\n");
			printf("------------------------------------------------------------------------\n");
			printf("请输入站点号：");
			scanf("%d", &station.station[i].stationId);
			printf("请输入起始站台：");
			scanf("%s", &station.station[i].from);
			printf("请输入终点站台：");
			scanf("%s", &station.station[i].to);
			printf("请输入车费：");
			scanf("%d", &station.station[i].money);
			printf("请输入票数：");
			scanf("%d", &station.station[i].numbers);
			printf("请添加票务信息：\n");
			printf("列车车次(整型)：");
			scanf("%s", &station.station[i].trainId);
			printf("列车出发日期：");
			scanf("%s", &station.station[i].data);
			printf("请输入时间：");
			scanf("%s", &station.station[i].time);
			printf("**车站信息更新成功！\n");
			printf("------------------------------------------------------------------------\n");
			key = -1;
			break;
		}
	if (key != -1)
		printf("没这个车站！");
	getch();
}

//删除站点	
void delatestation(Station &station, Ticket &ticket, Book &book)
{
	int key;
	printf("请输入你要修改的站点号：");
	scanf("%d", &key);
	for (int i = 0; i<station.count; i++)
		if (key == station.station[i].stationId)
		{
			for (int j = i; j < station.count-1; j++)
				station.station[i] = station.station[i + 1];
			key = -1;
			printf("删除成功！");
		}
	station.count--;
	if (key != -1)
		printf("没有这个站点!");
	getch();
}