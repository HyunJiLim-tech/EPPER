#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void sort_arr(char* str, int length) {
	for (int i = 0; i < length; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
	for (int i = 1; i < length; i++) {
		char temp = str[i];
		int j = i - 1;
		while (j >= 0 && str[j] > temp) {
			str[j + 1] = str[j];
			j--;
		}
		str[j + 1] = temp;
	}
}

int main() {
	char source[101];
	char dest[101];

	scanf("%s %s", &source, &dest);
	int s_length = strlen(source);
	int d_length = strlen(dest);
	sort_arr(source, s_length);
	sort_arr(dest, d_length);
	if (strcmp(source, dest) == 0) //문자열 일치하는지 확인
		printf("Yes\n");
	else
		printf("No\n");
}
