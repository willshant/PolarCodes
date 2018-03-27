#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define CodeLen 1024
#define InfoLen 512
#define RandLen 488
#define CRCLen 24
#define frame 20

char crc[CRCLen+1] = {1,1,0,0,0,0,1,1,0,0,1,0,0,1,1,0,0,1,1,1,1,1,0,1,1};
char position[CodeLen] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
/////////////////////////
////   Add CRC Bit   ////
/////////////////////////
void attachCRC(char *oriCode, char *crcBit){
	int i,j;
	char code_temp[InfoLen] = {0};
	for(i=0;i<RandLen;i++){
		code_temp[i] = oriCode[i];
	}//若使用strcpy函数，0将被当作字符串结束符'\0'处理，错误

	for(i=0;i<RandLen;i++){
		if(code_temp[i])
			for(j=0;j<CRCLen+1;j++){
				code_temp[i+j] = code_temp[i+j] ^ crcBit[j];
			}
	}
	for(i=0;i<CRCLen;i++){
		oriCode[RandLen+i] = code_temp[RandLen+i];
	}
}
///////////////////////
////   Kronecker   ////
///////////////////////
/* A(m*n) * B(p*q) */
char** kron(char **a, int m, int n, char **b, int p, int q) {
    char **matrix;
    int i,j;
	matrix = (char**) malloc(sizeof(char*) * m * p);
    for (i = 0; i < m * p; i++) {
        matrix[i] = (char*) malloc(sizeof(char) * n * q);
        for (j = 0; j < n * q; j++) {
            matrix[i][j] = a[i / p][j / q] * b[i % p][j % q];
        }
    }
    return matrix;
}
/* A^(x) Kronecker */
char** kronPow(char **a, int m, int n, int x) {
    if (x == 1)
        return a;
    else
        return kron(a, m, n, kronPow(a, m, n, x - 1), m * pow((float)2,(x - 2)), n * pow((float)2,(x - 2)));
}
/* Array Multiplication */
void arymul(char *a, char **b, char *c)  
{  
    int j, k;   
	short temp[CodeLen] = {0};
    for(j = 0; j < CodeLen; j++){
        for(k = 0; k < CodeLen; k++){  
            temp[k] += a[j] * b[j][k];  
        }  
    }
	for(k = 0; k < CodeLen; k++){
		if(temp[k] % 2)
			c[k] = 1;
		else
			c[k] = 0;
	}
}
/* Bit Reverse */
unsigned short
reverse(register unsigned short x){
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    return(((x >> 8) | (x << 8))>>6);
}
void bitReverse(char *code){
	short i;
	unsigned short bit[CodeLen];
	char temp[CodeLen];
	for(i=0;i<CodeLen;i++){
		temp[i] = code[i];
	}
	for(i=0;i<CodeLen;i++){
		bit[i] = reverse(i); 
	}
	for(i=0;i<CodeLen;i++){
		code[i] = temp[bit[i]];
	}
}
void polarEncode(char *code, char *encode, int length, char *pos){
	int i,j;
	char encodeIn[CodeLen];
	char **matrix;
    matrix = (char**) malloc(sizeof(char*) * 2);
    matrix[0] = (char*) malloc(sizeof(char) * 2);
	matrix[1] = (char*) malloc(sizeof(char) * 2);
    matrix[0][0] = 1;    matrix[0][1] = 0;    
	matrix[1][0] = 1;    matrix[1][1] = 1;
	j=0;
	for(i=0;i<length;i++){
		if(pos[i]){
			encodeIn[i] = code[j];
			j += 1;
		}
		else
			encodeIn[i] = 0;
	}
	
	matrix = kronPow(matrix, 2, 2, 10);
	arymul(encodeIn,matrix,encode);
	bitReverse(encode);
	free(matrix);
}
char char2num(char ch){
	if(ch==48)
		ch = 0;
	else
		ch = 1;
	return ch;
}
char num2char(char ch){
	if(ch)
		ch = 49;
	else
		ch = 48;
	return ch;
}
void main()
{
	FILE *rFile, *wFile;
	char *rBuf, space, enter;
	int len;
	short i,j,f;
	char *code, *encode;
	space = 32; enter = 10;
	code = (char*)malloc(sizeof(char)*InfoLen);
	encode = (char*)malloc(sizeof(char)*CodeLen);
	rFile = fopen("dataout.dat","r");
	wFile = fopen("PCencode.dat","wb");
	if(rFile == NULL)
		puts("read file fail");
	len = 977;//488x2+1
	rBuf = (char*)malloc(sizeof(char)*len);
	
	for(f=0;f<frame;f++){
		fread(rBuf,len,1,rFile);
		j=0;
		for(i=0;i<len;i++){
			if(rBuf[i]==48||rBuf[i]==49){
				code[j] = char2num(rBuf[i]);
				j++;
			}
		}
		/* Add CRC bits Length 512 */
		attachCRC(code,crc);
		/*
		for(i=0;i<InfoLen;i++){
			printf("%d\t%d\n",i,code[i]);
		}*/
		polarEncode(code,encode,CodeLen,position);
		/*
		for(i=0;i<CodeLen;i++){
			printf("%d",encode[i]);
		}
		puts("\n");*/
		for(i=0;i<CodeLen;i++){
			encode[i] = num2char(encode[i]);
			fwrite(encode+i,1,1,wFile);
			fwrite(&space,1,1,wFile);
		}
		if((f+1)!=frame)
			fwrite(&enter,1,1,wFile);
	}

	free(code);
	free(encode);
	fclose(rFile);
	fclose(wFile);
	system("pause");
}