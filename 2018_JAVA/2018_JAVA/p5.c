#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool isAsc(int* arr) { //오름차순
	int num = 1;
	for (int i = 0; i < 8; i++) {
		if (arr[i] != num)
			return false;
		num++;
	}
	return true;
}

bool isDes(int* arr) { //내림차순
	int num = 8;
	bool flag = true;
	for (int i = 0; i < 8; i++) {
		if (arr[i] != num)
			return false;
		num--;
	}
	return true;
}

int main() {
	int arr[8];

	for (int i = 0; i < 8; i++)
		scanf("%d", &arr[i]);
	if (isAsc(arr))
		printf("ascending\n");
	else if (isDes(arr))
		printf("descending\n");
	else //오름차순도 내림차순도 아니면 섞인 것
		printf("mixed\n");
}