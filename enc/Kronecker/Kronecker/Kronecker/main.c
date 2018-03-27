#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

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
/* Print Matrix */
void printMatrix(char**a, int m, int n) {
    int i,j;
	for (i = 0; i < m; i++) {
        for (j = 0; j < n ; j++) {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void main() {
    char **matrix;
    matrix = (char**) malloc(sizeof(char*) * 2);
    matrix[0] = (char*) malloc(sizeof(char) * 2);
    matrix[1] = (char*) malloc(sizeof(char) * 2);
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[1][0] = 1;
    matrix[1][1] = 1;
	matrix = kronPow(matrix, 2, 2, 10);
	printMatrix(matrix,64,64);
	free(matrix);
	system("pause");
}