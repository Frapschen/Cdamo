#include "ticket.h"
int  tsDisplay();//显示菜单
void found(Station &station, Ticket &ticket, Book &book);
void bookticket(Station &station, Ticket &ticket, Book &book);
void delateticket(Station &station, Ticket &ticket, Book &book);
void ticketServices(Station &station, Ticket &ticket, Book &book)
{
	int key;//显示菜单;
	while (true)
	{
		system("cls");
		key = tsDisplay();
		switch (key)
		{
		case 1:
			//查询车票
			found(station, ticket, book);
			break;
		case 2:
			//预定车票
			bookticket(station, ticket, book);
			break;
		case 3:
			delateticket(station, ticket, book);
			break;
		default:
			printf("输入错误！");
		case 0:
			//返回上一级菜单
			break;
		}
		if (key == 0)
			break;		
	}
}
//显示菜单
int tsDisplay()
{
	int key;
	printf("\t\t******************************\n");
	printf("\t\t\t查询车票----------------1\n");
	printf("\t\t\t预定车票----------------2\n");
	printf("\t\t\t退票服务----------------3\n");
	printf("\t\t\t返回上一级菜单----------0\n");
	printf("\t\t******************************\n");
	printf("\t\t请选择：");
	scanf("%d", &key);
	return key;
}

//查询车票
void found(Station &station, Ticket &ticket, Book &book)
{
	char star[STR_LEN];
	char end[STR_LEN];
	printf("请输入你的起点：");
	scanf("%s", &star);
	printf("请输入你的终点：");
	scanf("%s", &end);
	printf("车站号\t起点\t终点\t车次\t    日期\t时间\t 票数\t 价格\n");
	int key=0;
	for(int i=0;i<station.count;i++)
		if (strcmp(star, station.station[i].from) == 0 && strcmp(end, station.station[i].to) == 0)
		{
			printf("%-4d\t%-4s\t%-4s\t %-4s\t %-8s\t%-4s\t  %-4d\t %-4d\n", station.station[i].stationId, station.station[i].from, station.station[i].to, station.station[i].trainId, station.station[i].data, station.station[i].time, station.station[i].numbers, station.station[i].money);
			key = -1;
		}
	if (key != -1)
		printf("没有你要找的路线！");
	getch();

}

//预定车票
void bookticket(Station &station, Ticket &ticket, Book &book)
{
	int key=0;
	char choise[STR_LEN];
	printf("请输入你要预定的车次：");
	scanf("%s", &choise);
	for (int i = 0; i<station.count; i++)
		if (strcmp(choise,station.station->trainId)==0)
			if (station.station[i].numbers > 0)
			{
				printf("%-4d\t%-4s\t%-4s\t %-4s\t %-8s\t%-4s\t  %-4d\t %-4d\n", station.station[i].stationId, station.station[i].from, station.station[i].to, station.station[i].trainId, station.station[i].data, station.station[i].time, station.station[i].numbers, station.station[i].money);
				station.station[i].numbers--;
				book.book[book.count].ticketINfo.stationId = station.station[i].stationId;
				book.book[book.count].ticketINfo.seatId = rand();//随机函数
				strcpy(book.book[book.count].ticketINfo.time, station.station[i].time);
				strcpy(book.book[book.count].ticketINfo.trainId, station.station[i].trainId);
				strcpy(book.book[book.count].ticketINfo.time, station.station[i].time);
				strcpy(book.book[book.count].ticketINfo.data, station.station[i].data);
				strcpy(book.book[book.count].ticketINfo.from, station.station[i].from);
				strcpy(book.book[book.count].ticketINfo.to, station.station[i].to);
				book.book[book.count].autId = rand();
				printf("请输入你的名字：");
				scanf("%s", &book.book[book.count].name);
				book.count++;
				break;
				key = -1;
				printf("预定成功！");
				getch();
			}
			else
			{
				printf("没有票了！");
				getch();
			}
	if (key != -1)
		printf("预定失败");
}
//删除订票
void delateticket(Station &station, Ticket &ticket, Book &book)
{
	char name[STR_LEN];
	int key = 0;
	printf("请输入你的名字：");
	scanf("%s",&name);
	for (int i = 0; i < book.count; i++)
		if (strcmp(name, book.book[i].name))
		{
			for (int k = 0; k < station.count; k++)
				if (strcmp(book.book[i].ticketINfo.trainId, station.station[k].trainId) == 0)
				{
					station.station[k].numbers++;
					break;
				}
			for (int j = i; j < book.count - 1; j++)
				book.book[j] = book.book[j + 1];
			book.count--;
			key = -1;
			break;
		}
	if (key != -1)
		printf("这个票不存在！");
}