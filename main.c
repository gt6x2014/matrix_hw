#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 2

void print_matrix(int matrix[SIZE][SIZE]) {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void add_matrix(int result[SIZE][SIZE], int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			result[i][j] = a[i][j] + b[i][j];
		}
	}
}

void sub_matrix(int result[SIZE][SIZE], int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			result[i][j] = a[i][j] - b[i][j];
		}
	}
}

void mul_matrix(int result[SIZE][SIZE], int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	int i, j, k;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			result[i][j] = 0;

			for (k = 0; k < SIZE; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

int main() {
	int a[SIZE][SIZE];
	int b[SIZE][SIZE];
	int result[SIZE][SIZE];
	int i, j;

	srand((unsigned)time(NULL));

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			a[i][j] = rand() % 10;
			b[i][j] = rand() % 10;
		}
	}

	printf("행렬 A\n");
	print_matrix(a);
	printf("\n행렬 B\n");
	print_matrix(b);

	printf("\n행렬 A + B\n");
	add_matrix(result, a, b);
	print_matrix(result);

	printf("\n행렬 A - B\n");
	sub_matrix(result, a, b);
	print_matrix(result);

	printf("\n행렬 A * B\n");
	mul_matrix(result, a, b);
	print_matrix(result);

	return 0;
}