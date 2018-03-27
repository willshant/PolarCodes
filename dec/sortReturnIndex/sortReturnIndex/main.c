#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define List 8
typedef struct
{
	int cj;//数值
	int px;//下标
}PAIR;
//qsort的辅助比较函数
int compare(const void *p, const void *q)
{
	PAIR t1= *(PAIR* )p;
	PAIR t2= *(PAIR* )q;
	return(t1.cj<t2.cj);
}
int main()
{
	PAIR a[List];
	int cj[List];
	int px[List];
	int i;
	printf("请输入%d个整数：", List);
	for (i=0;i<List;i++)
	{
		scanf("%d",&(a[i].cj));
		a[i].px=i+1;
		//数组
		cj[i] = a[i].cj;
		px[i] = a[i].px;
	}
	qsort((void *)a,List, sizeof(PAIR), compare);
	printf("\n排好序的整数为：");
	for (i=0;i<List;i++)
	{
		printf("%d ",a[i].cj);
		cj[i]=a[i].cj;
	}
	printf("\n对应原来的下标：");
	for (i=0;i<List;i++)
	{
		printf("%d ",a[i].px);
		px[i] = a[i].px;
	}
	putchar('\n');
	return 0;
}