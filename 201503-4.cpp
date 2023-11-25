#include<stdio.h>
struct Exchange
{
	int num;
	int* pre;
	int* next;
};
struct End
{
	int num;
	int* pre;
};
int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	struct Exchange exchange[10001];
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			exchange[i].num = 1;
			exchange[i].pre = NULL;
		}
		else
		{
			int q = 0;
			scanf("%d", &q);
			exchange[i].num = i + 1;
			for (int j = 0; j < i; j++)
			{
				if (q == exchange[j].num)
				{
					exchange[i].pre = &exchange[j].num;
					exchange[j].next = &exchange[i].num;
					exchange[i].next=NULL;
				}
			}
		}
	}
	struct End end[10001];
	for (int i = 0; i < m; i++)
	{
		int q = 0;
		scanf("%d", &q);
		end[i].num = i + 1;
		for (int j = 0; j < n; j++)
		{
			if (q == exchange[j].num)
			{
				end[i].pre = &exchange[j].num;
				exchange[j].next=&end[i].num;
			}
		}
	}
	int time = 0;
	int k = 0;
	struct Exchange p;
	for (int i = 0; i < m - 1; i++)
	{
		p.num = end[i].num;
		p.pre = end[i].pre;
		p.next = NULL;
		for (int j = i + 1; j < m; j++)
		{
			int flag=1;
			while (flag)
			{
				if (p.next == NULL)
				{
					int o = *end[i].pre;
					p.num = o;
					p.pre = exchange[o - 1].pre;
					p.next = exchange[o - 1].next;
					k++;
				}
				else
				{
					if (*p.next != end[j].num)
					{
						if (*p.pre < *p.next)
						{
							p.num = exchange[*p.next - 1].num;
							p.pre = exchange[*p.next - 1].pre;
							p.next = exchange[*p.next - 1].next;
						}
						else
						{
							p.num = exchange[*p.pre - 1].num;
							p.next = exchange[*p.pre - 1].next;
							p.pre = exchange[*p.pre - 1].pre;
						}
						k++;
					}
					else
					{
						k++;
						if (k > time)
						{
							time = k;
						}
						flag=0;
					}
				}
			}
		}
	}
	printf("%d\n", time);

	return 0;
}
