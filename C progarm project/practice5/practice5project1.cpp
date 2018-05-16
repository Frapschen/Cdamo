#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define N 3

typedef struct Subject
{
	float C_langeuage;
	float Engelish;
	float Math;

};

typedef struct Student
{
	int id;
	char name[10];
	char sex[4];
	int age;
	Subject subject;
	float averagescore;

};

int DisplayMenu(int n);
void InputStudent(Student stu[], Student stucpy[]);
void SortStudnet(Student stu[], Student stucpy[],int k ,int n);//k是按什么排序,n=1升序，n=0降序
void OutputStudent(Student stu[]);
void copy(Student *stu, Student *stucpy,int c,int num);
//子入口
void practice5project1()
{
	Student stu[N],stucpy[N];
	InputStudent(stu, stucpy);
	int key;
	int key2;
	while (true)
	{
		key = DisplayMenu(1);//那种排序
		if(key!=0&&key!=9)
		   key2 = DisplayMenu(2);//怎么排序
		switch (key)
		{
		case 1://学号
			Student temp;
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 2://姓名
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 3://性别
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 4://年龄
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 5://C语言
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 6://英语
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 7://高数
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 8://平均分
			break;
		case 9:
			OutputStudent(stu);
		case 0:
			break;
		default:
				printf("输入错误！");
		}
		if (key == 0)
			break;
	}
}

//显示菜单
int DisplayMenu(int n)
{
	system("cls");
	switch (n)
	{
	case 1:
		printf("-----------------------------------------------------------------\n");
		printf("请选择排序字段：\n");
		printf("1.学号             2.姓名                3.性别              4年龄\n");
		printf("5.C语言            6.英语                7.高数              8.平均分\n");
		printf("9.显示全部原始信息                       0.退出程序\n");
		printf("-----------------------------------------------------------------\n");
		break;
	case 2:
		printf("-----------------------------------------------------------------\n");
		printf("1.升序                   2.降序                     0.退出程序   \n");
		printf("-----------------------------------------------------------------\n");
		break;
	default:
		printf("输入错误！\n");
		break;
	}
	int k;
	scanf("%d", &k);
	return k;
}
//输入学生的信息
void InputStudent(Student stu[], Student stucpy[]){
	for (int i = 0; i < N; i++)
	{
		printf("请输入第%d/%d个学生信息：\n",i+1,N);
		printf("------------------------------------------------------------\n");
		printf("学号：");
		scanf("%d", &stu[i].id);
		printf("姓名（10个字符内）：");
		scanf("%s", &stu[i].name);
		printf("性别(四个字符内)：");
		scanf("%s",&stu[i].sex);
		printf("年龄(整数)：");
		scanf("%d", &stu[i].age);
		printf("《C语言》成绩(整数)：");
		scanf("%f", &stu[i].subject.C_langeuage);
		printf("《英语》成绩(整数)：");
		scanf("%f", &stu[i].subject.Engelish);
		printf("《高数》成绩(整数)：");
		scanf("%f", &stu[i].subject.Math);
		printf("------------------------------------------------------------\n");
		stu[i].averagescore = (stu[i].subject.C_langeuage + stu[i].subject.Engelish + stu[i].subject.Math) / 2;
	}
	stucpy = stu;
}
//输出学生的信息
void OutputStudent(Student stu[])
{
	printf("====================================================================================\n");
	printf("学生全部信息：\n");
	printf("学号      姓名    性别       年龄       C语言     英语      数学      平均分\n");
	for (int i = 0; i < N; i++)
	{
		printf("%-10d", stu[i].id);
		printf("%-10s", stu[i].name);
		printf("%-10s",stu[i].sex);
		printf("%-10d", stu[i].age);
		printf("%-10.2f", stu[i].subject.C_langeuage);
		printf("%-10.2f", stu[i].subject.Engelish);
		printf("%-10.2f", stu[i].subject.Math);
		printf("%-10.2f", stu[i].averagescore);
		putchar('\n');
	}
	getch();
}
//两个结构体复制
void copy(Student *stu, Student *stucpy,int c,int num)
{
	/*int id;
	char name[10];
	char sex[4];
	int age;
	Subject subject;
	float averagescore;*/

	stucpy[c].id = stucpy[num].id;
	stucpy[c].age = stu[num].age;
	stucpy[c].averagescore = stu[num].averagescore;
	
	stucpy[c].subject.C_langeuage = stu[num].subject.C_langeuage;
	stucpy[c].subject.Engelish = stu[num].subject.Engelish;
	stucpy[c].subject.Math = stu[num].subject.Math;
	
	strcpy(stucpy[c].name, stu[num].name);
	strcpy(stucpy[c].sex, stu[num].sex);

}
//根据选择排序
void SortStudnet(Student stu[], Student stucpy[],int k,int n)
{
	//注意排序方式n==1是升序，==0是降序
	Student temp;
	switch (k)
	{
	case 1://学号
	{
		//冒泡排序
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].id > stu[j + 1].id)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else//降序
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].id < stu[j + 1].id)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//显示排序结果：
		OutputStudent(stu);
		break;
	}
	case 2://姓名
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (strcmp(stu[j].name,stu[j+1].name)>0)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else

		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (strcmp(stu[j].name, stu[j + 1].name)<0)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//显示排序结果：
		OutputStudent(stu);
		break;
	case 3://性别
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (strcmp(stu[j].sex, stu[j + 1].sex)>0)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else

		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (strcmp(stu[j].sex, stu[j + 1].sex)<0)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//显示排序结果：
		OutputStudent(stu);
		break;
	case 4://年龄
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].age > stu[j + 1].age)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else

		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].age < stu[j + 1].age)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//显示排序结果：
		OutputStudent(stu);
		break;
	case 5://C语言
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.C_langeuage > stu[j + 1].subject.C_langeuage)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.C_langeuage < stu[j + 1].subject.C_langeuage)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//显示排序结果：
		OutputStudent(stu);
		break;
	case 6://英语
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.Engelish > stu[j + 1].subject.Engelish)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.Engelish < stu[j + 1].subject.Engelish)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//显示排序结果：
		OutputStudent(stu);
		break;
	case 7://数学
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.Engelish > stu[j + 1].subject.Engelish)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.Math < stu[j + 1].subject.Math)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//显示排序结果：
		OutputStudent(stu);
		break;
	case 8://平均分
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].averagescore > stu[j + 1].averagescore)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].averagescore < stu[j + 1].averagescore)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//显示排序结果：
		OutputStudent(stu);
		break;
	default:
		break;
	}
}