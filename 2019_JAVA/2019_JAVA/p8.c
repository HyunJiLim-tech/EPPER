#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int tomato[1002][1002];
bool checked[1002][1002];

bool isAll(int M, int N) { //���� �;����� Ȯ���ϴ� �Լ�
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (tomato[i][j] == 0)
				return false;
		}
	}
	return true;
}

int cntDate(int M, int N) {
	int daycnt = 0;
	while (1) {
		if (isAll(M, N)) //���� �;����� Ȯ��
			break;
		for (int i = 1; i < M + 1; i++) {
			for (int j = 1; j < N + 1; j++) { //���� �丶���ε� �����¿찡 ������ �丶���̸� üũ�ص�
				if (tomato[i][j] == 1 && tomato[i - 1][j] == 0)
					checked[i - 1][j] = true;
				else if (tomato[i][j] == 1 && tomato[i + 1][j] == 0)
					checked[i + 1][j] = true;
				else if (tomato[i][j] == 1 && tomato[i][j - 1] == 0)
					checked[i][j - 1] = true;
				else if (tomato[i][j] == 1 && tomato[i][j + 1] == 0)
					checked[i][j + 1] = true;
			}
		}
		for (int i = 1; i < M + 1; i++) { //üũ�ߴ� �丶�� �ѹ��� �Ͱ� ��
			for (int j = 1; j < N + 1; j++)
				if (checked[i][j])
					tomato[i][j] = 1;
		}
		daycnt++; //�Ϸ簡 ����
	}
	return daycnt;
}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M + 2; i++) { //���� �� �ִ��� Ȯ���ϱ� ���� �Ϸ��� �����¿� ���پ� �߰���
		for (int j = 0; j < N + 2; j++)
			tomato[i][j] = -1;
	}
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &tomato[i][j]);
		}
	}
	bool isPossible = true;
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) { //�Ͱ� �ϴ°� �Ұ������� Ȯ��
			if (tomato[i][j] == 0 && tomato[i - 1][j] == -1 && tomato[i + 1][j] == -1 && tomato[i][j - 1] == -1 && tomato[i][j + 1] == -1) {
				isPossible = false;
				break;
			}
		}
	}
	if (isPossible)
		printf("%d", cntDate(M, N));
	else
		printf("-1");
}