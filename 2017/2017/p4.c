#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int S, E;
	int cnt = 0;

	scanf("%d %d", &S, &E);
	for (int i = S; i <= E; i++) {
		int now_num = i;
		while (now_num != 0) {
			int temp = now_num % 10; //�ڸ��� �ϳ��ϳ��� �ɰ�����
			if (temp == 3 || temp == 6 || temp == 9) { //3 or 6 or 9�� ī��Ʈ �÷��ְ� break�� Ż��
				cnt++;
				break;
			}
			now_num /= 10;
		}
	}
	printf("%d", cnt);
}