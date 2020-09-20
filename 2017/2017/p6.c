#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int dist(int ax, int ay, int bx, int by) { //길이 구함. 루트 씌우면 숫자 달라지니까 그냥 제곱으로 가져옴
	int dist_x = abs(ax - bx);
	int dist_y = abs(ay - by);

	return (dist_x * dist_x) + (dist_y * dist_y);
}

int main() {
	int cx, cy, r, n;
	int ex[50], ey[50];
	int cnt = 0;

	scanf("%d %d %d %d", &cx, &cy, &r, &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &ex[i], &ey[i]);
	for (int i = 0; i < n; i++) {
		if (dist(cx, cy, ex[i], ey[i]) <= (r * r)) //범위 안에 들어오면 카운트 증가
			cnt++;
	}
	printf("%d", cnt);
}