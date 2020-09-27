#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void sortString(char* s, int length) {
	char temp;

	for (int i = 0; i < length; i++) { //전부 소문자로
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
	for (int i = 1; i < length; i++) { //오름차순 정렬
		temp = s[i];
		int j = i - 1;
		while (j >= 0 && temp < s[j]) {
			s[j + 1] = s[j];
			j--;
		}
		s[j + 1] = temp;
	}
}

int main() {
	char a[21];
	char b[21];

	scanf("%s %s", &a, &b);
	int a_length = strlen(a);
	int b_length = strlen(b);
	sortString(a, a_length);
	sortString(b, b_length);
	if (strcmp(a, b) == 0) //정렬한 결과 같은지
		printf("T\n");
	else
		printf("F\n");
}