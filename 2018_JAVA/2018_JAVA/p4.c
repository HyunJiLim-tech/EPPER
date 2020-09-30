#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	int empty, star;

	scanf("%d", &n);
	empty = n / 2;
	star = 1;
	for (int i = 0; i < n / 2 + 1; i++) { //À­ºÎºÐ
		for (int j = 0; j < empty; j++)
			printf(" ");
		for (int j = 0; j < star; j++)
			printf("*");
		printf("\n");
		empty--;
		star += 2;
	}
	empty += 2;
	star -= 4;
	for (int i = 0; i < n / 2; i++) { //¾Æ·§ºÎºÐ
		for (int j = 0; j < empty; j++)
			printf(" ");
		for (int j = 0; j < star; j++)
			printf("*");
		printf("\n");
		empty++;
		star -= 2;
	}
}