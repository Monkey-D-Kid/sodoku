#include <stdio.h>
#include <stdlib.h>

#define SIZE 4
#define SUBSIZE 2

void importMatrix(int *matrix[SIZE][SIZE]){
    FILE *f;
    int c0,c1,c2,c3;
    f = fopen("input.txt","r");
    if ( f != NULL ){
	while(!feof(f)) {
	    if( fscanf(f,"%d %d %d %d",&c0,&c1,&c2,&c3) != 4)
		break;
	    printf("%d %d %d %d\n",c0,c1,c2,c3);
	}	
    }
    fclose(f);
}

void pMatrix(int matrix[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
	    printf("%d\t",matrix[i][j]);
	}
	printf("\n");
    }
}

void psubMatrix2(int matrix[SUBSIZE][SUBSIZE], int r, int c) {
    int rsubMatrix = r / SUBSIZE;
    int csubMatrix = c / SUBSIZE;
    int i, j;
    for (i = rsubMatrix * SUBSIZE; i < (rsubMatrix * SUBSIZE + SUBSIZE); i++) {
	for (j =  csubMatrix * SUBSIZE; j < (csubMatrix * SUBSIZE + SUBSIZE); j++) {
	    printf("%d\t",matrix[i][j]);
	}
	printf("\n");
    }
}

void getAllValueInSubMatrix(int matrix[SIZE][SIZE], int r, int c, int* oBuf) {
    int rsubMatrix = r / SUBSIZE;
    int csubMatrix = c / SUBSIZE;
    int i, j, k = 0;
    for (i = rsubMatrix * SUBSIZE; i < (rsubMatrix * SUBSIZE + SUBSIZE); i++) {
        for (j =  csubMatrix * SUBSIZE; j < (csubMatrix * SUBSIZE + SUBSIZE); j++) {
		*oBuf = matrix[i][j];
		oBuf++;
        }
    }
}

void psubMatrix(int matrix[SIZE][SIZE], int r, int c) {
    int *oBuf = malloc(SIZE * sizeof(int));
    int i = 0;
    getAllValueInSubMatrix(matrix,r,c,oBuf);
    for (i = 0; i < SIZE; i++)
	printf("%d\t", oBuf[i]);
    printf("\n");
}

void main() {
    int matrix[SIZE][SIZE] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    importMatrix(matrix);
    pMatrix(matrix);
    int r,c;
    do {
    	scanf("%d %d", &r, &c);
    	psubMatrix(matrix,r,c);
    } while (r != 9);
}
