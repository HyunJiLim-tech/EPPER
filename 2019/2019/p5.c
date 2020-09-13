#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() { //5¹ø
	char input;
	int y[2], m[2], d[2];
	int index = 0, back;
	char s;

	while (true) {
		scanf("%c", &input);
		if (index <= 1)
			y[index % 2] = input - '0';
		else if(index<=3)
			m[index % 2] = input - '0';
		else if(index<=5)
			d[index % 2] = input - '0';
		else {
			scanf("%c", &input);
			back = input - '0';
			if (back % 2 == 0)
				s = 'F';
			else
				s = 'M';
			if (back <= 2)
				printf("19%d%d-%d%d-%d%d %c", y[0], y[1], m[0], m[1], d[0], d[1], s);
			else
				printf("20%d%d-%d%d-%d%d %c", y[0], y[1], m[0], m[1], d[0], d[1], s);
			break;
		}
		index++;
	}
}