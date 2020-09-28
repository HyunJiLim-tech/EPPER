#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x1, y1;
	double temp, x2, y2;

	scanf("%d %d", &x1, &y1);
	if (x1 == 0) { //s1ÀÌ »ï°¢Çü
		temp = 250.00 - y1;
		x2 = 250 * 125 / temp;
		y2 = 250.00 - x2;
	}
	else if (y1 == 0) { //s2°¡ »ï°¢Çü
		temp = 250.00 - x1;
		y2 = 250 * 125 / temp;
		x2 = 250.00 - y2;
	}
	else {
		if (x1 > 125) { //s1ÀÌ »ï°¢Çü
			x2 = 0;
			y2 = 250.00 - 250.00 * 125 / x1;
		}
		else { //s2°¡ »ï°¢Çü
			y2 = 0;
			x2 = 250.00 - 250.00 * 125 / y1;
		}
	}
	printf("%.2f %.2f", x2, y2);
}