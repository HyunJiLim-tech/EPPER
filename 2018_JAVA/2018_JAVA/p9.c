#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, M;
	int min;

	scanf("%d %d", &N, &M);
	if (N > M)
		min = M;
	else
		min = N;
	for (int i = 1; i <= min; i++) { //모든 경우의 수를 다 따져봐야함
		if (N % i == 0) {
			if ((M - 2) % i == 0)
				printf("%d ", i);
			else if ((M - 1) % i == 0 && (N - 2) % i == 0)
				printf("%d ", i);
		}
		else if (N % i == 1) {
			if ((M - 1) % i == 0)
				printf("%d ", i);
			else if ((M - 2) % i == 0 && M % i == 0)
				printf("%d ", i);
		}
		else if (M % i == 0 && (N - 2) % i == 0)
			printf("%d ", i);
	}
}