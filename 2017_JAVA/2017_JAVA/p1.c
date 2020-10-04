#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;

	scanf("%d %d", &a, &b);
	if (a > b) { //a가 더 작도록
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b % a == 0) //a가 최대공약수인지 확인해보고
		printf("%d\n", a);
	else {
		for (int i = a / 2; i >= 1; i--) { //a 나누기 2 부터 검사
			if (b % i == 0 && a % i == 0) {
				printf("%d\n", i);
				break;
			}
		}
	}
}