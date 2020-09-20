#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);
	int empty = n / 2;
	int star = 1;
	for (int i = 0; i <= (n / 2); i++) { //위 절반 + 가운데
		for (int j = 0; j < empty; j++)
			printf(" ");
		for (int j = 0; j < star; j++)
			printf("*");
		printf("\n");
		empty -= 1;
		star += 2;
	}
	empty += 2;
	star -= 4;
	for (int i = 0; i < (n / 2); i++) { //아래 절반
		for (int j = 0; j < empty; j++)
			printf(" ");
		for (int j = 0; j < star; j++)
			printf("*");
		printf("\n");
		empty += 1;
		star -= 2;
	}
}