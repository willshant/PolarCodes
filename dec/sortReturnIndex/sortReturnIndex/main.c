#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define List 8
typedef struct
{
	int cj;//��ֵ
	int px;//�±�
}PAIR;
//qsort�ĸ����ȽϺ���
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
	printf("������%d��������", List);
	for (i=0;i<List;i++)
	{
		scanf("%d",&(a[i].cj));
		a[i].px=i+1;
		//����
		cj[i] = a[i].cj;
		px[i] = a[i].px;
	}
	qsort((void *)a,List, sizeof(PAIR), compare);
	printf("\n�ź��������Ϊ��");
	for (i=0;i<List;i++)
	{
		printf("%d ",a[i].cj);
		cj[i]=a[i].cj;
	}
	printf("\n��Ӧԭ�����±꣺");
	for (i=0;i<List;i++)
	{
		printf("%d ",a[i].px);
		px[i] = a[i].px;
	}
	putchar('\n');
	return 0;
}