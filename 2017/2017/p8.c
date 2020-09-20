#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int weight[100];
bool isTeam[100] = { 0, };
int n, min = 1000000;
int team1_min, team2_min;

void make_team(int now, int cnt) {
	if (cnt == n / 2) { //���� �ɰ��� ���
		int team1_w = 0, team2_w = 0;

		for (int i = 0; i < n; i++) {
			if (isTeam[i]) //isTeam üũ������ team1 �̶�� ��
				team1_w += weight[i];
			else
				team2_w += weight[i];
		}
		if (team1_w > team2_w) { //���� ������ ����ؾ� �ϴϱ� Ȯ��
			int temp = team1_w;
			team1_w = team2_w;
			team2_w = temp;
		}
		if (team2_w - team1_w < min) { //�ּҰ����� ������
			min = team2_w - team1_w;
			team1_min = team1_w;
			team2_min = team2_w;
		}
	}
	else { //��Ʈ��ŷ���� �� �ɰ���
		for (int i = now; i < n; i++) {
			isTeam[i] = true;
			make_team(i + 1, cnt + 1);
			isTeam[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &weight[i]);
	make_team(0, 0);
	printf("%d %d", team1_min, team2_min);
}