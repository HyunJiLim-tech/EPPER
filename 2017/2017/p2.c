#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int m, d;

	scanf("%d %d", &m, &d);
	int sum = 0; //1월 1일부터 몇 일이 지나야 해당 날짜가 될까
	int start = 1; //1월부터 시작
	while (1) {
		if (start == m) { //해당 월까지 오면 day에서 1빼기
			sum += (d - 1);
			break;
		}
		if ((start <= 7 && start % 2 == 1) || (start > 7 && start % 2 == 0)) //7월까진 홀수 월, 8월부턴 짝수 월이 31일임
			sum += 31;
		else if (start == 2) //2월은 28일까지
			sum += 28;
		else //그 외는 전부 30일까지
			sum += 30;
		start++;
	}
	sum %= 7; //일주일은 7일
	switch (sum) { //1월 1일이 일욜이니까 나누어 떨어지면 일욜인거고 아니면 그 뒤부터 월화~
	case 0:
		printf("일요일");
		break;
	case 1:
		printf("월요일");
		break;
	case 2:
		printf("화요일");
		break;
	case 3:
		printf("수요일");
		break;
	case 4:
		printf("목요일");
		break;
	case 5:
		printf("금요일");
		break;
	case 6:
		printf("토요일");
		break;
	}
}