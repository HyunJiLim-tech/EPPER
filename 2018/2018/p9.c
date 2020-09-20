#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bracket(int left, int right) {
	if (left == 0 && right == 0) //둘 다 전부 쓴거면 1 반환
		return 1;
	else {
		if (left == 0) //왼쪽 괄호 다쓰면 오른쪽만 사용
			return bracket(left, right - 1);
		else if (left <= (right - 1)) //모든 상황에서 오른쪽 괄호가 왼쪽 괄호보다 많거나 같아야 짝 성립
			return bracket(left - 1, right) + bracket(left, right - 1);
		else //왼쪽 괄호와 오른쪽 괄호의 수가 같은 경우. 왼쪽을 쓰면 위에서 말한 균형이 깨지는 상황
			return bracket(left - 1, right);
	}
}

int main() {
	int n, cnt = 0;

	scanf("%d", &n);
	printf("%d", bracket(n, n));
}