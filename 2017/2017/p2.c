#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int m, d;

	scanf("%d %d", &m, &d);
	int sum = 0; //1�� 1�Ϻ��� �� ���� ������ �ش� ��¥�� �ɱ�
	int start = 1; //1������ ����
	while (1) {
		if (start == m) { //�ش� ������ ���� day���� 1����
			sum += (d - 1);
			break;
		}
		if ((start <= 7 && start % 2 == 1) || (start > 7 && start % 2 == 0)) //7������ Ȧ�� ��, 8������ ¦�� ���� 31����
			sum += 31;
		else if (start == 2) //2���� 28�ϱ���
			sum += 28;
		else //�� �ܴ� ���� 30�ϱ���
			sum += 30;
		start++;
	}
	sum %= 7; //�������� 7��
	switch (sum) { //1�� 1���� �Ͽ��̴ϱ� ������ �������� �Ͽ��ΰŰ� �ƴϸ� �� �ں��� ��ȭ~
	case 0:
		printf("�Ͽ���");
		break;
	case 1:
		printf("������");
		break;
	case 2:
		printf("ȭ����");
		break;
	case 3:
		printf("������");
		break;
	case 4:
		printf("�����");
		break;
	case 5:
		printf("�ݿ���");
		break;
	case 6:
		printf("�����");
		break;
	}
}