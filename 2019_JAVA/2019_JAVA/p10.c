#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char keypad[5][9] = { {'*', '*', '*', 'A', 'B', 'C', 'D', 'E'}, {'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'}, {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'}, {'V', 'W', 'X', 'Y', 'Z', '*', '*', '*'} };
char pos[51][21];

void changePad(char* arr, int length) {
	bool check[5][9];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			check[i][j] = false;
		}
	}
	for (int i = 0; i < 4; i++) { //입력할 수 있는거라면 체크
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < length; k++) {
				if (keypad[i][j] == arr[k])
					check[i][j] = true;
			}
		}
	}
	for (int i = 0; i < 4; i++) { //체크안된 것들 별로 바꿈
		for (int j = 0; j < 8; j++) {
			if (!check[i][j])
				keypad[i][j] = '*';
		}
	}
}

void compareStr(char* input, int length, int num) {
	char arr[51];
	int cnt = 0;

	for (int i = 0; i < num; i++) {
		bool isSame = true;
		for (int j = 0; j < length; j++) { //문자열 비교해서 같은지 확인
			if (pos[i][j] != input[j])
				isSame = false;
		}
		if (isSame) { //같다면 그 다음 문자 배열에 투입
			arr[cnt++] = pos[i][length];
		}
	}
	changePad(arr, cnt);
}

int main() {
	char input[21];
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", &pos[i]);
	scanf("%s", &input);
	compareStr(input, strlen(input), N);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++)
			printf("%c", keypad[i][j]);
		printf("\n");
	}
}