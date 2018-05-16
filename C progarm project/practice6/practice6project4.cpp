#include "stdio.h"
#include "stdlib.h"
#define N 10
struct cust
{
	char id[N + 1];
	struct cust *next;
};
void practice6project4()
{
	char c;
	struct cust customer;
	cust *p = NULL, *tmp = NULL, *head = NULL;
	do
	{
		printf("请输入客户ID：");
		tmp = (cust*)malloc(sizeof(struct cust));
		tmp->next = NULL;
		scanf("%s", tmp->id);
		if (p == NULL)
		{
			p = tmp;
			head = p;
		}
		else
		{
			p->next = tmp;
			p = tmp;
		}
		printf("\n输入Q退出，按任意键继续:");
		char ch;
		while ((ch = getchar()) != EOF && ch != '\n')
		{
			;
		}
		c = getchar();
	} while (c != 'q'&&c != 'Q');
	p = head;
	do
	{
		printf("%s\n", p->id);
		p = p->next;
	} while (p != NULL);
}