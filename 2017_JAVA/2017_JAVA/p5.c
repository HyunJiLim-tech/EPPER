#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, c;
	int sum = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n - 2; i++) { //i<=j<=c�� �ǵ���, c�� ���� �� ��
		for (int j = i; j <= n - 2; j++) {
			c = n - i - j;
			if (c < j)
				break;
			else if (c < n - c) //c�� ������ �� ���� �պ��� �۴ٸ� �ﰢ����
				sum++;
		}
	}
	printf("%d\n", sum);
}