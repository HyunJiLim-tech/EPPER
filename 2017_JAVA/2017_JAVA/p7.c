#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char matrix[101][101];
int m, n;

int findZ(int x, int y) { //���� ���� ã�� �Լ�
	int sum = 0;
	
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if ((i != x || j != y) && (matrix[i][j] == '*'))
				sum++;
		}
	}
	return sum;
}

int main() {
	char empty, input;

	scanf("%d %d", &m, &n);
	for (int i = 0; i < m + 2; i++) { //���ϰ� �ϱ� ���� �׵θ��� �ϳ� �� �ѷ���
		for (int j = 0; j < n + 2; j++) {
			matrix[i][j] = '-';
		}
	}
	scanf("%c", &empty);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%c", &input);
			matrix[i][j] = input;
		}
		scanf("%c", &empty);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (matrix[i][j] == '*')
				printf("*");
			else
				printf("%d", findZ(i, j));
		}
		printf("\n");
	}
}