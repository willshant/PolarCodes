#include <stdio.h>
#include <mat.h>

/**
	read a .mat file and
	creat a .dat file that DSP can read
	*/

void main()
{
	FILE *wFile;
	MATFile *pmatFile = NULL;
	mxArray *pMxArray = NULL; 

	double *initA;
	int M, N, i, j; 

	wFile = fopen("decInput.dat","wb");
	pmatFile = matOpen("E:\\1thesis\\polarC\\dec\\decInput.mat","r");  
	pMxArray = matGetVariable(pmatFile, "msg_dec"); // a matrix name in .mat file 
	initA = (double*) mxGetData(pMxArray);  

	M = mxGetM(pMxArray);  // frame number
	N = mxGetN(pMxArray);  // sequence length

    for (i=0; i<M; i++)  
	{
		for (j=0; j<N; j++)  
		{
			fwrite(initA+M*j+i, 8, 1, wFile);
		}
	}

    matClose(pmatFile);   
 	mxFree(initA);
	fclose(wFile); 
	system("pause");
}