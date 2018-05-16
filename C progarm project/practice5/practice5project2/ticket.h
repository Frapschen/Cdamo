#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define STATION_NUM 100
#define TICKET_NUM 1000
#define STR_LEN 15

typedef struct {
	int stationId;//车站号
	char from[STR_LEN];//车票起点
	char to[STR_LEN];//车站终点
	char trainId[STR_LEN];//火车车次
	char data[STR_LEN];
	char time[STR_LEN];
	int money;//票价
	int numbers;//票数
}StationInfo;//车站票务信息

typedef struct {
	StationInfo station[STATION_NUM];
	int count;
	int ticketnum;
}Station;//站票务信息计数器

typedef struct {
	int stationId;//车站号
	int seatId;//座位号
	char trainId[STR_LEN];//火车车次  （随机）
	char time[STR_LEN];//出发时间
	char data[STR_LEN];
	char from[STR_LEN];//车票起点
	char to[STR_LEN];//车站终点
}TicketInfo;//车票信息


typedef struct
{
	TicketInfo ticket;
	int count;
}Ticket;//车票信息

typedef struct {
	int autId;
	char name[STR_LEN];
	TicketInfo ticketINfo;
}BookInfo;//订票信息

typedef struct {
	BookInfo book[TICKET_NUM];
	int count;
}Book;//订票信息计数器

void systemManage(Station &station, Ticket &ticket, Book &book);
void stationManage(Station &station, Ticket &ticket, Book &book);
void ticketManage(Station &station, Ticket &ticket, Book &book);
void ticketServices(Station &station, Ticket &ticket, Book &book);

