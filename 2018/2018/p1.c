#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[10001] = { 0, };
	int n, i, j;
	int sum = 0;

	scanf("%d %d %d", &n, &i, &j);
	for (int k = 1; k <= n; k++)
		scanf("%d", &arr[k]);
	for (int k = i; k <= j; k++)
		sum += arr[k];
	printf("%d", sum);
}