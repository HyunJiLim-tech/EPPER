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
	for (i = 0; i < n; i++) { //��¸� �϶�� �ؼ� �׳� ����� �ٷ� �����
		for (j = 0; j < m; j++)
			printf("%d ", matrix[j][i]);
		printf("\n");
	}
}