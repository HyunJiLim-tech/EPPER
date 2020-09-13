#include <stdio.h>

int main() { 
	int m, n, remain;
	int money_cnt = 0, tot_cnt = 0;

	scanf_s("%d %d", &m, &n);
	remain = m - n;
	int money = 100000;
	for (int i = 0; i < 8 && remain != 0; i < i++) {
		if (i % 2 == 0)
			money /= 2;
		else {
			money /= 5;
		}
		if ((remain / money) != 0) {
			money_cnt++;
			tot_cnt += (remain / money);
			remain = remain % money;
		}
	}
	printf("%d %d", money_cnt, tot_cnt);
}