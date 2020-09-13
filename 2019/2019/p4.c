#include <stdio.h>

int main() { 
	int n;
	int arr[100];

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		int temp_arr = arr[i] % 100;
		arr[i] = arr[i] - temp_arr;
		if ((temp_arr / 10) > 4)
			printf("%d %d\n", arr[i] + 100, arr[i]);
		else
			printf("%d %d\n", arr[i], arr[i]);
	}
}