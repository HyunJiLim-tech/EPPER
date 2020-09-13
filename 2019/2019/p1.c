#include <stdio.h>

int main() { //1¹ø
	int n, sum = 0;
	int arr[100];

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1)
			sum += arr[i];
	}
	printf("%d\n", sum);
}