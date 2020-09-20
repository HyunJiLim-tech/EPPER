#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num1 = 0, num2 = 0;
	char input, empty;
	int m;

	scanf("%d", &m);
	scanf("%c", &empty); //공백 빼줌
	scanf("%c", &input);
	num1 = input - '0'; //첫 숫자 저장
	for (int i = 1; i < m; i++) {
		scanf("%c", &empty); //공백 빼줌
		scanf("%c", &input);
		switch (input) { //op면 계산해서 num1에 저장하고 숫자면 num2에 저장
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