#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i % 6 == 0) //2�� 3�� ������� �� 6���� �������°� ã�°� �ƴѰ�
			printf("%d ", i);
	}
}