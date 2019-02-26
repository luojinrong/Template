#include<stdio.h>
#include<stdlib.h>
struct shu {
	int x;
	int flag;
	struct shu *next;
};
void Eratosthenes(int n)
{
	int i, count = 0;
	struct shu *head = NULL, *p, *q;
	for (i = n; i > 1; i--)
	{
		p = (struct shu *)malloc(sizeof(struct shu));
		p->x = i;
		p->flag = 1;
		p->next = head;
		head = p;
	}
	for (q = head; q != NULL; q = q->next)
		if (q->flag == 0)
			continue;
		else
			for (p = q->next; p != NULL; p = p->next)
				if (p->x % q->x == 0)
					p->flag = 0;
	for (p = head; p != NULL; p = p->next)
		if (p->flag == 1)
		{
			printf("%d ", p->x);
			count++;
			if (count == 10)
			{
				count = 0;
				printf("\n");
			}
		}
}
int main()
{
	int n;
	scanf_s("%d", &n);
	Eratosthenes(n);
}