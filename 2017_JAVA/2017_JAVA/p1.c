#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;

	scanf("%d %d", &a, &b);
	if (a > b) { //a�� �� �۵���
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b % a == 0) //a�� �ִ��������� Ȯ���غ���
		printf("%d\n", a);
	else {
		for (int i = a / 2; i >= 1; i--) { //a ������ 2 ���� �˻�
			if (b % i == 0 && a % i == 0) {
				printf("%d\n", i);
				break;
			}
		}
	}
}