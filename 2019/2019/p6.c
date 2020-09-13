#include <stdio.h>

int main() { 
	int arr[3];
	int k, cnt = 0;

	for (int i = 0; i < 3; i++)
		scanf_s("%d", &arr[i]);
	scanf_s("%d", &k);
	for (int i = 0; i < 3; i++) {
		if (arr[i] == k)
			cnt++;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if ((arr[i] + arr[j]) == k)
				cnt++;
		}
	}
	if ((arr[0] + arr[1] + arr[2]) == k)
		cnt++;
	printf("%d", cnt);
}