#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool digit[10] = { 0, }; //각 자릿수의 수가 나왔는지 체크하는 bool 배열

bool isAll() { //모든 자릿수가 나왔는지 확인하는 함수
	for (int i = 0; i < 10; i++) {
		if (!digit[i])
			return false;
	}
	return true;
}

int main() {
	int A, i = 1;

	scanf("%d", &A);
	while (!isAll()) { //모든 자릿수가 나오면 loop 벗어남
		int tmp = A * i;
		while (tmp != 0) { //숫자 쪼개며 확인
			digit[tmp % 10] = true;
			tmp /= 10;
		}
		i++;
	}
	printf("%d\n", i - 1); //마지막에 i가 증가됐을테니 하나 빼주는 것
}