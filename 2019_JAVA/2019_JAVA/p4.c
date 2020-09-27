#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() { //그냥 수학
	int N, M;

	scanf("%d %d", &N, &M);
	if (N > M)
		printf("%d\n", (M - 1) * 2);
	else
		printf("%d\n", (N- 1) * 2);
}