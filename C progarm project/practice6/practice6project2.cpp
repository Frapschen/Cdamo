#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
int num=0;
int key2;//怎么排序
//数据定义
typedef struct data
{
	char id[13];
	char name[11];
	char sex[5];
	int old;
	int C_Language;
	int English;
	int Math;
	float average;
};
typedef struct Student
{
	data student;
	Student *prev;
	Student *next;
};

Student *start();//初始化链表
int p6Display(int n);//菜单
void show1(Student *head);//原始数据展示
void show2(data target[]);//排序顺序显示

void sort1(Student *head);
void sort2(Student *head);
void sort3(Student *head);
void sort4(Student *head);
void sort5(Student *head);
void sort6(Student *head);
void sort7(Student *head);
void sort8(Student *head);


void practice6project2()
{
	Student  *head=start();
	int key1;//1是一级菜单  2是二级菜单
	while (true)
	{
		key1= p6Display(1);
		if(key1!=9&&key1!=0)
		    key2= p6Display(2);
		switch (key1)
		{
		case 1:
			sort1(head);
			break;
		case 2:
			sort2(head);
			break;
		case 3:
			sort3(head);
			break;
		case 4:
			sort4(head);
			getch();
			break;
		case 5:
			sort5(head);
			break;
		case 6:
			sort6(head);
			break;
		case 7:
			sort7(head);
			break;
		case 8:
			sort8(head);
			break;
		case 9:
			show1(head);
			break;
		case 0:
			break;
		default:
			printf("输入错误！");
			break;
		}
		if (key1 == 0)
			break;
	}
}

//初始化链表
Student *start()
{
	Student *head=NULL;
	Student *p = NULL;
	Student *q = NULL;
	char k;
	printf("请输入学生信息：");
	do
	{
		if (head == NULL)
		{
			num++;
			head = (Student*)malloc(sizeof(Student));
			printf("请添加一下信息：");
			printf("学号：");
			scanf("%s", &head->student.id);
			printf("姓名:");
			scanf("%s", &head->student.name);
			printf("性别:");
			scanf("%s", &head->student.sex);
			printf("年龄:");
			scanf("%d", &head->student.old);
			printf("C语言:");
			scanf("%d", &head->student.C_Language);
			printf("英语:");
			scanf("%d", &head->student.English);
			printf("数学:");
			scanf("%d", &head->student.Math);
			head->student.average = (head->student.Math + head->student.English + head->student.C_Language)/3;
			head->next = NULL;
			head->prev = NULL;
			q = head;
		}
		else
		{
			num++;
			p= (Student*)malloc(sizeof(Student));
			printf("\n请添加一下信息：");
			printf("学号：");
			scanf("%s", &p->student.id);
			printf("姓名：");
			scanf("%s", &p->student.name);
			printf("性别：");
			scanf("%s", &p->student.sex);
			printf("年龄：");
			scanf("%d", &p->student.old);
			printf("C语言：");
			scanf("%d", &p->student.C_Language);
			printf("英语：");
			scanf("%d", &p->student.English);
			printf("数学：");
			scanf("%d", &p->student.Math);
			p->student.average = (p->student.Math + p->student.English + p->student.C_Language)/3;
			//完成节点链接
			p->prev = q;//这个节点指向上个节点
			q->next = p;//上个节点指向这个节点
			q = p;
		}
		fflush(stdin);
		printf("添加成功！现在有%d个人。按y/Y继续添加，按其他键完成:",num);
		k = getch();
	} while (k == 'y' || k == 'Y');
	return head;
}

//菜单
int p6Display(int n)
{
	int key;
	system("cls");
	switch (n)
	{
	case 1:
	{
		printf("\n");
		printf("选择排序方式：\n");
		printf("-----------------------------------------------------------------\n");
		printf("1.学号\t2.姓名\t3.性别\t4.年龄\n");
		printf("5.C语言\t6.英语\t7.高数\t8.平均分\n");
		printf("9.显示原始数据\t0.返回上一级菜单\n");
		printf("-----------------------------------------------------------------\n");
		break;
	}
	case 2:
	{
		printf("\n");
		printf("-----------------------------------------------------------------\n");
		printf("1.升序\t\t2.降序\t\t0.返回上一级菜单\n");
		printf("-----------------------------------------------------------------\n");
	}
	default:
		break;
	}
	scanf("%d", &key);
	return key;
}

//显示原始数据
void show1(Student *head)
{
	Student * start = head;
	printf("学号\t姓名\t性别\t年龄\tC语言\t英语\t高数\t平均分\n");
		for (int i = 0; i <num; i++)
		{
			printf("%-8s%-8s%-8s%-8d%-8d%-8d%-8d%-8f\n", start->student.id, start->student.name,
				start->student.sex, start->student.old, start->student.C_Language,
				start->student.English, start->student.Math, start->student.average);
			start = start->next;
		}
	getch();
}

//显示排序后的数据
void show2(data target[])
{
	printf("学号\t姓名\t性别\t年龄\tC语言\t英语\t高数\t平均分\n");
	if (key2 == 1)
		for (int i = 0; i < num; i++)
		{
			printf("%-8s%-8s%-8s%-8d%-8d%-8d%-8d%-8f\n", target[i].id, target[i].name,
				target[i].sex, target[i].old, target[i].C_Language, target[i].English,
				target[i].Math, target[i].average);
		}
	else
		for (int i = num-1; i >=0; i--)
		{
			printf("%-8s%-8s%-8s%-8d%-8d%-8d%-8d%-8f\n", target[i].id, target[i].name,
				target[i].sex, target[i].old, target[i].C_Language, target[i].English,
				target[i].Math, target[i].average);
		}
	getch();
}

//学号
void sort1(Student *head)
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i < num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for(int i=0;i<num;i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].id > target[j + 1].id)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//显示数据	
	free(target);
}

//姓名
void sort2(Student *head)
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i < num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (strcmp(target[j].name,target[j + 1].name)>0)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//显示数据
	free(target);
}
void sort3(Student *head)//性别
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i < num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (strcmp(target[j].sex, target[j + 1].sex)>0)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//显示数据
	free(target);
}
void sort4(Student *head)//年龄
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i <num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].old > target[j + 1].old)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//显示数据
	free(target);
}
void sort5(Student *head)//C语言
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i <num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].C_Language> target[j + 1].C_Language)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//显示数据
	free(target);
}
void sort6(Student *head)//英语
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i <num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].C_Language > target[j + 1].C_Language)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//显示数据
	free(target);
}
void sort7(Student *head)//高数
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i <num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].Math > target[j + 1].Math)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//显示数据
	free(target);
}
void sort8(Student *head)//平均分
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i <num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].average > target[j + 1].average)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//显示数据
	free(target);
}