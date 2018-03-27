#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	/* value */
	double cj;
	/* index */
	char px;
}PAIR;

void Swap(PAIR *A, int i, int j){
    double cj_tmp;
	char px_tmp;
    cj_tmp = A[i].cj;
    A[i].cj = A[j].cj;
    A[j].cj = cj_tmp;
	px_tmp = A[i].px;
    A[i].px = A[j].px;
    A[j].px = px_tmp;
}

void QuickSort(PAIR *A, int L, int R){
    if(L < R){//�ݹ�ı߽��������� L == Rʱ�����Ԫ�ظ���Ϊ1��
        int pivot = A[L].cj;//����ߵ�Ԫ����Ϊ���ᣬL��ʾleft, R��ʾright
        int i = L+1, j = R;
        //��i == jʱ��i��jͬʱָ���Ԫ�ػ�û��������Ԫ���жϣ�
        //С�ڵ�������Ԫ�أ�i++,��������Ԫ��j--,
        //��ѭ������ʱ��һ����i = j+1, ��iָ���Ԫ�ش������ᣬjָ���Ԫ��С�ڵ�������
        while(i <= j){
            while(i <= j && A[i].cj >= pivot){
                i++;
            }
            while(i <= j && A[j].cj < pivot){
                j--;
            }
            //�� i > j ʱ�����зֹ��̾�Ӧ��ֹͣ�ˣ����ܽ��н�������
            //������Ըĳ� i < j�� ���� i ��Զ�������j�� ��Ϊ����������ѭ��������
            if(i <= j){
                Swap(A, i, j);
                i++;
                j--;
            }
        }
        //��ѭ������ʱ��jָ���Ԫ�������һ�������������С�ڵ��������Ԫ��
        Swap(A, L, j);//������Ԫ�غ�j��ָ��Ԫ�ػ���
        QuickSort(A, L, j-1);//�ݹ���벿��
        QuickSort(A, j+1, R);//�ݹ��Ұ벿��
    }
}

void main() {
	PAIR a[8];
	int i;
	a[0].cj = 5;a[1].cj = 7;a[2].cj = 1;a[3].cj = 3;a[4].cj = 2;a[5].cj = 6;a[6].cj = 8;a[7].cj = 4;
	a[0].px = 1;a[1].px = 2;a[2].px = 3;a[3].px = 4;a[4].px = 5;a[5].px = 6;a[6].px = 7;a[7].px = 8;
	for(i=0;i<8;i++){
		printf("%f\t", a[i].cj);
	}
	printf("\n");
	for(i=0;i<8;i++){
		printf("%d\t", a[i].px);
	}
	printf("\n");
	QuickSort(a, 0, 7);
	for(i=0;i<8;i++){
		printf("%f\t", a[i].cj);
	}
	printf("\n");
	for(i=0;i<8;i++){
		printf("%d\t", a[i].px);
	}
	system("pause");
}