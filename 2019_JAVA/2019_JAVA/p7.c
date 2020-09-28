#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char matrix[50][50];
char scan_matrix[250][250];

int main() {
	int R, C, ZR, ZC;
	char empty;

	scanf("%d %d %d %d", &R, &C, &ZR, &ZC);
	for (int i = 0; i < R; i++) {
		scanf("%c", &empty);
		for (int j = 0; j < C; j++) {
			scanf("%c", &matrix[i][j]);
		}
	}
	for (int i = 0; i < R * ZR; i++) {
		for (int j = 0; j < C * ZC; j++) {
			scan_matrix[i][j] = matrix[i / ZR][j / ZC]; //¹è¿­ ÂÉ°³±â
			printf("%c", scan_matrix[i][j]);
		}
		printf("\n");
	}
}