#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt = 0;

void hanoi(int n, char source, char tmp, char dest) {
	if (n == 1) {
		printf("%d: %c->%c\n", n, source, dest);
		cnt++;
	}
	else {
		hanoi(n - 1, source, dest, tmp);
		printf("%d: %c->%c\n", n, source, dest);
		cnt++;
		hanoi(n - 1, tmp, source, dest);
	}
}

int main() {
	int n;

	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	printf("%d", cnt);
}