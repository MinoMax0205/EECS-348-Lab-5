#include <stdio.h>

#define SIZE 5

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int Sum[SIZE][SIZE]) {
	//Function ends prematurely if one or both input matrices are empty
	if (m1 == NULL || m2 == NULL) {
		printf("Error: One or both input matrices are empty.\n");
		return; }

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			Sum[i][j] = m1[i][j] + m2[i][j];}
	}
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int Multiply[SIZE][SIZE]) {
	//Checks if one or both input matrices are empty
	if (m1 == NULL || m2 == NULL) {
		printf("Error: One or both input matrices are empty.\n");
		return; }
	
	//This intializes the Multiply Matrices output as 0 to not have junk/garbage values
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			Multiply[i][j] = 0; }
	}
	//This does the computations
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				Multiply[i][j] += m1[i][k] *m2[k][j];}
		}
	}
}
	
void transposeMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int tm1[SIZE][SIZE], int tm2[SIZE][SIZE]) {
	if (m1 == NULL || m2 == NULL) {
		printf("Error: One or both input matrices are empty.\n");
		return; }
	
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			tm1[j][i] = m1[i][j];
			tm2[j][i] = m2[i][j]; }
	}
}
	

void printMatrix(int m[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", m[i][j]);}
					
	printf("\n"); }
}
					
					

	
int main() {
	int Sum[SIZE][SIZE];
	int Multiply[SIZE][SIZE];
	int tm1[SIZE][SIZE];
	int tm2[SIZE][SIZE];

	int m1[SIZE][SIZE] = {
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15},
	{16,17,18,19,20},
	{21,22,23,24,25} };

	int m2[SIZE][SIZE] = {
	{25,24,23,22,21},
	{20,19,18,17,16},
	{15,14,13,12,11},
	{10,9,8,7,6},
	{5,4,3,2,1} };


	addMatrices(m1, m2, Sum);
	multiplyMatrices(m1, m2, Multiply);
	transposeMatrices(m1, m2, tm1, tm2);
	
	printf("Sum Matrix:\n");
	printMatrix(Sum);

	printf("\nProduct Matrix:\n");
	printMatrix(Multiply);

	printf("\nTranspose of Matrix 1:\n");
	printMatrix(tm1);

	printf("\nTranpsose of Matrix 2:\n");
	printMatrix(tm2);

	return 0;
}
