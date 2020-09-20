#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int matrix[10][10];
	int m, n;
	int i, j;

	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	for (i = 0; i < n; i++) { //출력만 하라고 해서 그냥 뒤집어서 바로 출력함
		for (j = 0; j < m; j++)
			printf("%d ", matrix[j][i]);
		printf("\n");
	}
}