#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() { //그냥 수학
	int n;

	scanf("%d", &n);
	n--;
	printf("%d %d\n", n / 15 + 1, n % 15 + 1);
}
