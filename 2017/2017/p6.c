#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int dist(int ax, int ay, int bx, int by) { //���� ����. ��Ʈ ����� ���� �޶����ϱ� �׳� �������� ������
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
		if (dist(cx, cy, ex[i], ey[i]) <= (r * r)) //���� �ȿ� ������ ī��Ʈ ����
			cnt++;
	}
	printf("%d", cnt);
}