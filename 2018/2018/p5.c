#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int date, s_date, n;
	int car_arr[101];
	int cnt = 0;

	scanf("%d %d", &date, &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &car_arr[i]);
	date %= 10; //���ڸ��� ������
	s_date = (date + 5) % 10; //date+5�� �����ؾ��ϴµ� 5�� ��� 10�� �Ǵϱ� 10���� ���� ������
	for (int i = 0; i < n; i++) {
		if (date == (car_arr[i] % 10)||s_date==(car_arr[i]%10))
			cnt++;
	}
	printf("%d", cnt);
}