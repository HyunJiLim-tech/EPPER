#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int tomato[1002][1002];
bool checked[1002][1002];

bool isAll(int M, int N) { //전부 익었는지 확인하는 함수
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
		if (isAll(M, N)) //전부 익었는지 확인
			break;
		for (int i = 1; i < M + 1; i++) {
			for (int j = 1; j < N + 1; j++) { //익은 토마토인데 상하좌우가 안익은 토마토이면 체크해둠
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
		for (int i = 1; i < M + 1; i++) { //체크했던 토마토 한번에 익게 함
			for (int j = 1; j < N + 1; j++)
				if (checked[i][j])
					tomato[i][j] = 1;
		}
		daycnt++; //하루가 지남
	}
	return daycnt;
}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M + 2; i++) { //익을 수 있는지 확인하기 쉽게 하려고 상하좌우 한줄씩 추가함
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
		for (int j = 1; j < N + 1; j++) { //익게 하는게 불가능한지 확인
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