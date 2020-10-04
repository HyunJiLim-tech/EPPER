#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char score[1001];
	int tmp_score = 0, sum = 0;

	scanf("%s", &score);
	for (int i = 0; i < strlen(score); i++) {
		if (score[i] == 'O') { //O면 현재 스코어를 증가하고 sum에 합침
			tmp_score++;
			sum += tmp_score;
		}
		else if (score[i] == 'X') //X면 현재 스코어 0으로 초기화
			tmp_score = 0;
	}
	printf("%d\n", sum);
}