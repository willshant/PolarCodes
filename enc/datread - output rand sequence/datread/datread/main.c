#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CodeLen 1024
#define InfoLen 512
#define RandLen 488
#define CRCLen 24
#define frame 100
char transchar(char ch){
	if(ch)
		ch = 49;
	else
		ch = 48;
	return ch;
}

void main()
{
	FILE *wFile;
	short i,j;
	char *code, space, enter;
	code = (char*)malloc(sizeof(char)*RandLen);
	space = 32; enter = 10;
	
	wFile = fopen("dataoutf100.dat","w");
	
	srand((unsigned)time(NULL));
	for(j=0;j<frame;j++){
		for(i=0;i<RandLen;i++){
			code[i] = transchar(rand() % 2);
			fwrite(code+i,1,1,wFile);
			fwrite(&space,1,1,wFile);
		}
		fwrite(&enter,1,1,wFile);
	}

	free(code);
	fclose(wFile);
	system("pause");
}

