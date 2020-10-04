#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, c;
	int sum = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n - 2; i++) { //i<=j<=c가 되도록, c가 가장 긴 변
		for (int j = i; j <= n - 2; j++) {
			c = n - i - j;
			if (c < j)
				break;
			else if (c < n - c) //c가 나머지 두 변의 합보다 작다면 삼각형임
				sum++;
		}
	}
	printf("%d\n", sum);
}