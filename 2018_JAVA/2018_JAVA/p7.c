#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[9];
	int obj_num = 0;
	int x, y;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		obj_num += arr[i];
	}
	obj_num -= 100; //��ü �տ��� 100�� ���� ��ǥ�ϴ� ���� ����
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == obj_num) { //2�� �̾Ƽ� ��ǥ ���ڿ� ������ Ȯ��
				x = i;
				y = j;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) { //���� �� �����ϰ� ���
		if (i != x && i != y)
			printf("%d ", arr[i]);
	}
}