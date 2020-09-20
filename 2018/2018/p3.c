#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main() {
	int n;
	bool isPrime = true;

	scanf("%d", &n);
	for (int i = 2; i < n; i++) {
		if (n % i == 0) { //±×³É ´Ù ³ª´²º½
			isPrime = false;
			break;
		}
	}
	if (isPrime)
		printf("1");
	else
		printf("0");
}