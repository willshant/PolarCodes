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
    if(L < R){//递归的边界条件，当 L == R时数组的元素个数为1个
        int pivot = A[L].cj;//最左边的元素作为中轴，L表示left, R表示right
        int i = L+1, j = R;
        //当i == j时，i和j同时指向的元素还没有与中轴元素判断，
        //小于等于中轴元素，i++,大于中轴元素j--,
        //当循环结束时，一定有i = j+1, 且i指向的元素大于中轴，j指向的元素小于等于中轴
        while(i <= j){
            while(i <= j && A[i].cj >= pivot){
                i++;
            }
            while(i <= j && A[j].cj < pivot){
                j--;
            }
            //当 i > j 时整个切分过程就应该停止了，不能进行交换操作
            //这个可以改成 i < j， 这里 i 永远不会等于j， 因为有上述两个循环的作用
            if(i <= j){
                Swap(A, i, j);
                i++;
                j--;
            }
        }
        //当循环结束时，j指向的元素是最后一个（从左边算起）小于等于中轴的元素
        Swap(A, L, j);//将中轴元素和j所指的元素互换
        QuickSort(A, L, j-1);//递归左半部分
        QuickSort(A, j+1, R);//递归右半部分
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