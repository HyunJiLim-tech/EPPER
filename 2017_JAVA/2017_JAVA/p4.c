#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int coins[6] = { 500,100,50,10,5,1 };
	int C, M, remain, sum = 0;

	scanf("%d %d", &C, &M);
	remain = C - M; //°Å½º¸§µ·
	for (int i = 0; i < 6 && remain != 0; i++) {
		if (remain >= coins[i]) {
			sum += remain / coins[i];
			remain %= coins[i];
		}
	}
	printf("%d\n", sum);
}