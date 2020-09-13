#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char input, none;
	int m;
	int num[2];

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%c", &none);
		scanf("%c", &input);
		if (i == 0)
			num[0] = input - '0';
		else {
			switch (input) {
			case '+':
				num[0] = num[0] + num[1];
				break;
			case '-':
				num[0] = num[0] - num[1];
				break;
			case '*':
				num[0] = num[0] * num[1];
				break;
			case '/':
				num[0] = num[0] / num[1];
				break;
			default:
				num[1] = input - '0';
				break;
			}
		}
	}
	printf("%d", num[0]);
}