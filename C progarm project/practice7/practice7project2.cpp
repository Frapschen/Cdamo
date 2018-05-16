#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
typedef struct Student

{
	int id;
	char name[9];
	char sex[3];
	int old;
	float C_language;
	float Engkish;
	float Math;
	float average;
	Student *next;
};
int number;
//studentInfo.dat
//增加 删除 修改，查；
int  p72Display();
int input(Student* &head);//输入数据
int output(Student* head);//输出数据到文件
int  read(Student* &head);//从文件读取数据

void show(Student* head);//浏览数据
void addstudent(Student* &head);//添加元素
void delatestudent(Student* &head);//删除元素
void changestudent(Student* &head);//修改数据

//入口
void practice7project2()
{
	Student *head;
	head = NULL;
	int key;
	FILE *fp;
	printf("是否是第一次运行本程序：1.是\t2.不是\t3.不清楚\n");
	scanf("%d", &key);

	//原始提取
	while (true)
	{
		switch (key)
		{
		case 1://输入数据原始数据并写入文件
		{
			number = input(head);
			if (output(head))
				printf("写入文件成功！\n");
			else
				printf("写入文件失败");
			getch();
			break;
		}
		case 2://读取数据
			number= read(head);
			break;
		case 3://检查是否有数据，根据结果选择操作
		{
			if ((fp = fopen("practice7project2.dat", "r")) == NULL)
			{
				printf("检查到没有这个文件，现在请输入信息：\n");
				number = input(head);
				if (output(head))//将数据写入文件
					printf("写入文件成功！\n");
				else
					printf("写入文件失败");
				getch();
			}
			else
			{
				printf("检查到文件\n");
				number = read(head);
				if (number != 0)
					printf("文件读取成功！\n");
				else
					printf("文件读取失败！\n");
			}
			getch();
			break;
		}
		default:
			printf("输入错误");
			break;
		}
		if (key == 1 || key == 2 || key == 3)
			break;
	}
	//数据处理
	while (true)
	{
		system("cls");
		key = p72Display();
		switch (key)
		{
		case 1://查询数据
			show(head);
			break;
		case 2://添加数据
			addstudent(head);
			break;
		case 3://删除数据
			delatestudent(head);
			break;
		case 4://修改数据
			changestudent(head);
			break;
		case 5:
			break;
		default:
			printf("输入错误1");
			break;
		}
		if (key == 5)
			break;
	}
}

int p72Display()
{
	int key;
	printf("============================================================\n");
	printf("\t1.查询数据\n");
	printf("\t2.添加数据\n");
	printf("\t3.删除数据\n");
	printf("\t4.修改程序\n");
	printf("\t5.返回上一级菜单\n");
	printf("============================================================\n");
	scanf("%d", &key);
	return key;
}


//输入数据
int input(Student* &head)
{
	int num;
	Student *p = NULL;
	Student *q =NULL;
	printf("\n\n请输入你要输入的学生个人数：");
	scanf("%d",&num);
	for (int i = 0; i < num; i++)
	{
		if (head == NULL)
		{
			head = (Student*)malloc(sizeof(Student));
			head->next = NULL;
			printf("==========================================================================\n");
			printf("请输入学号：");
			scanf("%d", &head->id);
			printf("请输入姓名：");
			scanf("%s", &head->name);
			printf("请输入性别：");
			scanf("%s", &head->sex);
			printf("请输入年龄：");
			scanf("%d", &head->old);
			printf("请输入C语言：");
			scanf("%f", &head->C_language);
			printf("请输入英语：");
			scanf("%f", &head->Engkish);
			printf("请输入数学：");
			scanf("%f", &head->Math);
			head->average = (head->Math + head->C_language + head->Engkish) / 3;
			q = head;
		}
		else
		{
			p = (Student*)malloc(sizeof(Student));
			p->next = NULL;
			q->next = p;
			printf("==========================================================================\n");
			printf("请输入学号：");
			scanf("%d", &p->id);
			printf("请输入姓名：");
			scanf("%s", &p->name);
			printf("请输入性别：");
			scanf("%s", &p->sex);
			printf("请输入年龄：");
			scanf("%d", &p->old);
			printf("请输入C语言：");
			scanf("%f", &p->C_language);
			printf("请输入英语：");
			scanf("%f", &p->Engkish);
			printf("请输入数学：");
			scanf("%f", &p->Math);
			p->average = (p->Math + p->C_language + p->Engkish) / 3;
			q = p;
		}
	}
	printf("输入结束，按任意键继续...");
	getch();
	return num;
}

//输出数据到文件
int output(Student* head)
{
	int num=0;
	FILE *ff;
	if ((ff = fopen("practice7project2.dat", "w")) == NULL)
		printf("文件打开失败！\n");
	else
	{
		while (head != NULL)
		{
			num += fwrite(head, sizeof(Student), 1, ff);
			head = head->next;
		}
	}
	fclose(ff);
	return num;
}
//从文件读取数据
int  read(Student* &head)
{
	int num=0;
	FILE *ff;
	if ((ff = fopen("practice7project2.dat", "r")) == NULL)
		printf("文件打开失败！");
	else
	{
		Student *p = NULL;
		Student *q = NULL;
		while (!feof(ff))
		{
			if (head == NULL)
			{
				head = (Student*)malloc(sizeof(Student));
				fread(head, 1, sizeof(Student), ff);
				num++;
				q = head;
			}
			else
			{
				p = (Student*)malloc(sizeof(Student));
				if (fread(p, 1, sizeof(Student), ff) > 2)
				{
					num++;
					p->next = NULL;
					q->next = p;
					q = p;
				}
				else
				{
					free(p);
				}
			}
		}
	}
	return num;
}

//浏览数据
void show(Student* head)
{
	printf("学号\t姓名\t性别\t年龄\tC语言\t英语\t数学\t平均分\n");
	while (head!=NULL)
	{
		printf("%-4d\t%-4s\t%-4s\t%-4d\t%-4.2f\t%-4.2f\t%-4.2f\t%-4.2f\n",head->id, head->name, head->sex, head->old,head->C_language,head->Engkish,head->Math,head->average );
		head = head->next;
	}
	getch();
}

//添加元素
void addstudent(Student* &head)
{
	Student *oldhead=head;
	int num;
	printf("请输入你要添加的学生个数：");
	scanf("%d", &num);
	number += num;
	while (head->next!=NULL)
	{
		head = head->next;
	}
	Student *p = NULL;
	Student *q = NULL;

	q = head;
	for (int i = 0; i < num; i++)
	{
		p = (Student*)malloc(sizeof(Student));
		p->next = NULL;
		q->next = p;
		printf("==========================================================================\n");
		printf("请输入学号：");
		scanf("%d", &p->id);
		printf("请输入姓名：");
		scanf("%s", &p->name);
		printf("请输入性别：");
		scanf("%s", &p->sex);
		printf("请输入年龄：");
		scanf("%d", &p->old);
		printf("请输入C语言：");
		scanf("%f", &p->C_language);
		printf("请输入英语：");
		scanf("%f", &p->Engkish);
		printf("请输入数学：");
		scanf("%f", &p->Math);
		p->average = (p->Math + p->C_language + p->Engkish) / 3;
		q = p;
	}
	printf("输入结束，按任意键继续...");
	getch();
	head = oldhead;
	if (output(head) > 1)
		printf("写入文件成功！\n");
	else
		printf("写入文件失败！\n");
	getch();

}

//删除元素
void delatestudent(Student* &head)
{
	int num;
	Student *cp, *star = head;
	printf("请输入你想删除学生的学号：");
	scanf("%d", &num);
	while (star!=NULL)
	{
		if (star->id == num)
			break;
		cp = star;
		star = star->next;
	}
	if (cp==NULL)//删除第一个节点
	{
		cp = head;
		 head= head->next;
		free(cp);
	}
	else
		cp->next = star->next;

	//在把修改后的数据写入文件
	if (output(head) > 1)
		printf("删除成功!\n");
	else
		printf("删除失败！\n");
	number--;
	getch();
}

//修改数据
void changestudent(Student* &head)
{
	int num;
	Student *star = head;
	printf("请输入你想修改学生的学号：");
	scanf("%d", &num);
	while (star != NULL)
	{
		if (star->id == num)
			break;
		star = star->next;
	}
	printf("请输入修改的内容：\n");
	printf("==========================================================================\n");
	printf("请输入学号：");
	scanf("%d", &star->id);
	printf("请输入姓名：");
	scanf("%s", &star->name);
	printf("请输入性别：");
	scanf("%s", &star->sex);
	printf("请输入年龄：");
	scanf("%d", &star->old);
	printf("请输入C语言：");
	scanf("%f", &star->C_language);
	printf("请输入英语：");
	scanf("%f", &star->Engkish);
	printf("请输入数学：");
	scanf("%f", &star->Math);
	star->average = (star->Math + star->C_language + star->Engkish) / 3;

	//写入到文件
	if (output(head) > 1)
		printf("修改成功!\n");
	else
		printf("修改失败！\n");
	getch();
}