#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool digit[10] = { 0, }; //�� �ڸ����� ���� ���Դ��� üũ�ϴ� bool �迭

bool isAll() { //��� �ڸ����� ���Դ��� Ȯ���ϴ� �Լ�
	for (int i = 0; i < 10; i++) {
		if (!digit[i])
			return false;
	}
	return true;
}

int main() {
	int A, i = 1;

	scanf("%d", &A);
	while (!isAll()) { //��� �ڸ����� ������ loop ���
		int tmp = A * i;
		while (tmp != 0) { //���� �ɰ��� Ȯ��
			digit[tmp % 10] = true;
			tmp /= 10;
		}
		i++;
	}
	printf("%d\n", i - 1); //�������� i�� ���������״� �ϳ� ���ִ� ��
}