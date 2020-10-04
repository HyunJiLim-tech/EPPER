#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	char num[101];
	bool isPal = true;

	scanf("%s", &num);
	int length = strlen(num);
	for (int i = 0; i < length / 2; i++) { //숫자를 배열로 받아서 앞 뒤 일치하는지 확인
		if (num[i] != num[length - i - 1]) {
			isPal = false;
			break;
		}
	}
	if (isPal)
		printf("yes\n");
	else
		printf("no\n");
}