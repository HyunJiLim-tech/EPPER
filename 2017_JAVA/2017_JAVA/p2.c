#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char score[1001];
	int tmp_score = 0, sum = 0;

	scanf("%s", &score);
	for (int i = 0; i < strlen(score); i++) {
		if (score[i] == 'O') { //O�� ���� ���ھ �����ϰ� sum�� ��ħ
			tmp_score++;
			sum += tmp_score;
		}
		else if (score[i] == 'X') //X�� ���� ���ھ� 0���� �ʱ�ȭ
			tmp_score = 0;
	}
	printf("%d\n", sum);
}