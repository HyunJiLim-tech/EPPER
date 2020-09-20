#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i % 6 == 0) //2와 3의 공배수면 걍 6으로 나눠지는거 찾는거 아닌가
			printf("%d ", i);
	}
}