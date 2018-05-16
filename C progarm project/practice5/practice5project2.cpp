#include "practice5project2\\ticket.h";

void init(Station &station, Ticket &ticket, Book &book);//初始化第个一站台

void practice5project2()
{
	Station station;
	Ticket ticket;
	Book book;
	//初始化票务信息
	init(station, ticket, book);
	int key;
	while (true)
	{
		system("cls");
		printf("\t\t***************************************\n");
		printf("\t\t\t售票系统-------------1\n");
		printf("\t\t\t系统管理-------------2\n");
		printf("\t\t\t退出系统-------------0\n");
		printf("\t\t**************************************\n");
		printf("\t\t请选择：");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			ticketServices(station,ticket,book);
			break;
		case 2:
			systemManage(station, ticket, book);
			break;
		case 0:
			break;
		default:
			printf("输入错误！按任意键继续...");
			getch();
			break;
		}
		if (key == 0)
			break;
	}

}
//初始化第个一站台
void init(Station &station, Ticket &ticket, Book &book)
{
	station.count = 0;
	ticket.count = 0;
	book.count = 0;
	station.ticketnum = 0;
	printf("------------------------------------------------------------------------\n");
	printf("欢迎进入系统！请添加第一个站点：\n");
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
	printf("**第一个车站信息添加成功！\n");
	printf("------------------------------------------------------------------------\n");
	getch();
}


