#include <stdlib.h>
#include <stdio.h>

#define CodeLen 1024

unsigned short
reverse(register unsigned short x){
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    return(((x >> 8) | (x << 8))>>6);
}

void main(){
	short i;
	unsigned short bit[CodeLen];
	for(i=0;i<CodeLen;i++){
		bit[i] = reverse(i); 
		printf("%d\t%d\n",i,bit[i]);
	}
	system("pause");
}
