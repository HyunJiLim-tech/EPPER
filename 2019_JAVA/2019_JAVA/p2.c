#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	double median, sum = 0.0, cnt = 0.0;
	
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	median = sum / N;
	for (int i = 0; i < N; i++) {
		if (arr[i] > median)
			cnt++;
	}
	printf("%.3f%%", cnt / N * 100.000);
}