#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt = 0;
int arr[10];

void pal(int start, int end) {
	if (start == end || start > end)
		return;
	else if (arr[start] == arr[end])
		pal(start + 1, end - 1);
	else if (arr[start] < arr[end]) {
		arr[start + 1] += arr[start];
		pal(start + 1, end);
		cnt++;
	}
	else {
		arr[end - 1] += arr[end];
		pal(start, end - 1);
		cnt++;
	}
}

int main() { 
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	pal(0, n - 1);
	printf("%d", cnt);
}