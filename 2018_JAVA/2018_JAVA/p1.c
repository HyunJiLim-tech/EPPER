#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i, j, sum = 0;
	int arr[101];

	scanf("%d", &n);
	for (int k = 1; k <= n; k++)
		scanf("%d", &arr[k]);
	scanf("%d %d", &i, &j);
	for (int k = i; k <= j; k++)
		sum += arr[k];
	printf("%d\n", sum);
}