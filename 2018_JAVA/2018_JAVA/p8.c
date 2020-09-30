#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//판을 만들었음
int board[5][5] = { {25, 24, 23, 22, 21},
	{10, 11, 12, 13, 20},
	{9, 8, 7, 14, 19},
	{2, 3, 6, 15, 18},
	{1, 4, 5, 16, 17} };

int main() {
	int n;

	scanf("%d", &n);
	int* chess = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &chess[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (chess[i] == board[j][k]) //비교해서 계산
					printf("%d %d\n", k + 1, 5 - j);
			}
		}
	}
}