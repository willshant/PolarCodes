#include <stdio.h>
#include <mat.h>
#define row 20
#define column 488
void main()
{
	FILE *rFile;
	MATFile *pmatFile = NULL;
	mxArray *pMxArray = NULL; 
	int i, j;
	char *in;
	double *out;
	
	if((rFile = fopen("decDSPL=32v7.dat","r")) == NULL)
		printf("read fail !");
	in = (char*)mxMalloc(sizeof(char) * row * column); 
	out = (double*)mxMalloc(sizeof(double) * row * column);
	fread(in, 1, row * column, rFile);

	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			out[i+j*row] = in[j+i*column];
		}
		printf("\n");
	}

    pmatFile = matOpen("decDSPL=32.mat","w"); 
	pMxArray = mxCreateNumericMatrix (row, column, mxDOUBLE_CLASS, mxREAL);  
    mxSetData(pMxArray, out);    
    matPutVariable(pmatFile, "decDSPL32", pMxArray);    

	matClose(pmatFile);   
	mxFree(out);
	mxFree(in);
}