#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int S, E;
	int cnt = 0;

	scanf("%d %d", &S, &E);
	for (int i = S; i <= E; i++) {
		int now_num = i;
		while (now_num != 0) {
			int temp = now_num % 10; //자리수 하나하나로 쪼개봐서
			if (temp == 3 || temp == 6 || temp == 9) { //3 or 6 or 9면 카운트 늘려주고 break로 탈출
				cnt++;
				break;
			}
			now_num /= 10;
		}
	}
	printf("%d", cnt);
}