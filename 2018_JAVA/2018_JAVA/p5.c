#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool isAsc(int* arr) { //��������
	int num = 1;
	for (int i = 0; i < 8; i++) {
		if (arr[i] != num)
			return false;
		num++;
	}
	return true;
}

bool isDes(int* arr) { //��������
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
	else //���������� ���������� �ƴϸ� ���� ��
		printf("mixed\n");
}