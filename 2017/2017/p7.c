#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num1 = 0, num2 = 0;
	char input, empty;
	int m;

	scanf("%d", &m);
	scanf("%c", &empty); //���� ����
	scanf("%c", &input);
	num1 = input - '0'; //ù ���� ����
	for (int i = 1; i < m; i++) {
		scanf("%c", &empty); //���� ����
		scanf("%c", &input);
		switch (input) { //op�� ����ؼ� num1�� �����ϰ� ���ڸ� num2�� ����
		case '+':
			num1 += num2;
			break;
		case '-':
			num1 -= num2;
			break;
		case '*':
			num1 *= num2;
			break;
		case '/':
			num1 /= num2;
			break;
		default:
			num2 = input - '0';
			break;
		}
	}
	printf("%d", num1);
}