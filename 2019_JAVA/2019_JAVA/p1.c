#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int y;

	scanf("%d", &y);
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		printf("T\n");
	else
		printf("F\n");
}