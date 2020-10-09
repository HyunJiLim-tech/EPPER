#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int matrix[100][100];

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
			scanf("%d", &matrix[i][j]);
	}
	for (int i = N - 2; i >= 0; i--) { //아래부터 위로 올라감
		for (int j = 0; j <= i; j++) {
			matrix[i][j] = matrix[i][j] + max(matrix[i + 1][j], matrix[i + 1][j + 1]);
		}
	}
	printf("%d", matrix[0][0]);
}
