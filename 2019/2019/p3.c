#include <stdio.h>

int main() { //3¹ø
	int n;

	scanf_s("%d", &n);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (j < i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}