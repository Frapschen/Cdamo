#include "ticket.h"

int  timDisplay();//显示菜单
void foundsellticket(Station &station, Ticket &ticket, Book &book);//查已售票
void foundremainticket(Station &station, Ticket &ticket, Book &book);//查待销售

void ticketManage(Station &station, Ticket &ticket, Book &book)
{
	int key;//显示菜单;
	while (true)
	{
		system("cls");
		key = timDisplay();
		switch (key)
		{
		case 1:
			//查已售票
			foundsellticket(station, ticket, book);
			break;
		case 2:
			//查待销售
			foundremainticket(station, ticket, book);
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
int  timDisplay()
{
	int key;
	printf("\t\t******************************\n");
	printf("\t\t\t查已售票----------------1\n");
	printf("\t\t\t查待销售----------------2\n");
	printf("\t\t\t返回上一级菜单----------0\n");
	printf("\t\t******************************\n");
	printf("\t\t请选择：");
	scanf("%d", &key);
	return key;
}

//查已售票
void foundsellticket(Station &station, Ticket &ticket, Book &book)
{
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("编号\t姓名\t座位号\t车站号\t起点\t终点\t车次\t    时间\t日期\n");
	for (int i = 0; i < book.count; i++)
		printf("%-4d\t%-4s\t %-4d\t %-4d\t%-4s\t%-4s\t%-4s\t\t%-4s\t %-4s\n",book.book[i].autId,
			book.book[i].name, book.book[i].ticketINfo.seatId, book.book[i].ticketINfo.stationId,
			book.book[i].ticketINfo.from, book.book[i].ticketINfo.to, book.book[i].ticketINfo.trainId,
			book.book[i].ticketINfo.time, book.book[i].ticketINfo.data);
	getch();
}

//查待销售
void foundremainticket(Station &station, Ticket &ticket, Book &book)
{
	printf("车站号\t起点\t终点\t车次\t    日期\t时间\t 待售票数\n");
	for(int i=0;i<station.count;i++)
		if(station.station[i].numbers!=0)
			printf("%-4d\t%-4s\t%-4s\t %-4s\t %-8s\t%-4s\t  %-4d\n", station.station[i].stationId, station.station[i].from, station.station[i].to, station.station[i].trainId, station.station[i].data, station.station[i].time, station.station[i].numbers);
		else
		{
			printf("全部销空！");
		}
	getch();
}