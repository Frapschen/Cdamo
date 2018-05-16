#include "ticket.h"
void systemManage(Station &station, Ticket &ticket, Book &book)
{
	int key;
	while (true)
	{
		system("cls");
		printf("\t\t***************************************\n");
		printf("\t\t\t车站操作-------------1\n");
		printf("\t\t\t票务操作-------------2\n");
		printf("\t\t\t返回上一级菜单-------0\n");
		printf("\t\t**************************************\n");
		printf("\t\t请选择：");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			stationManage(station, ticket, book);
			break;
		case 2:
			ticketManage(station, ticket, book);
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