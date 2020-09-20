#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int find_unique(int a, int b, int c) { //짝 없는 하나가 정답
	if (a == b)
		return c;
	else if (a == c)
		return b;
	else
		return a;
}

int main() {
	int x[3], y[3];

	for (int i = 0; i < 3; i++)
		scanf("%d %d", &x[i], &y[i]);
	printf("%d %d", find_unique(x[0], x[1], x[2]), find_unique(y[0], y[1], y[2]));
}