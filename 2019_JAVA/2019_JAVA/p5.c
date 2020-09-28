#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word {
	char w[22];
	int cnt;
}word;

void sorting(word* words, int length) { //���������� ����
	char temp[22];
	for (int i = 1; i < length; i++) {
		strcpy(temp, words[i].w);
		int j = i - 1;
		while (j >= 0 && strcmp(temp, words[j].w) < 0) {
			strcpy(words[j + 1].w, words[j].w);
			j--;
		}
		strcpy(words[j + 1].w, temp);
	}
}

void printWord(char* first, word* words, int w_length, int f_length) {
	int* flag = (int*)malloc(sizeof(int) * f_length);
	int cnt;

	for (int i = 0; i < f_length; i++) {
		cnt = 0;
		for (int j = 0; j < w_length; j++) { //��ġ�ϸ� �ĺ� �迭�� ����
			if (first[i] == words[j].w[0])
				flag[cnt++] = j;
		}
		if (cnt == 1) { //�ĺ� �迭�� ���� �ϳ��� �ٷ� ����ϰ� ���� Ƚ�� ����
			printf("%s\n", words[flag[0]].w);
			words[flag[0]].cnt++;
		}
		else { //�������� ���� ���� ������ �ܾ� ã��. ���� ��� ���ٸ� ���������� ��µ� ��(���� ������ �־����ϱ�)
			int min = words[flag[0]].cnt;
			int pos = flag[0];
			for (int k = 1; k < cnt; k++) {
				if (min > words[flag[k]].cnt) {
					min = words[flag[k]].cnt;
					pos = flag[k];
				}
			}
			printf("%s\n", words[pos].w);
			words[pos].cnt++;
		}
	}
}

int main() {
	int K, N;
	char input;
	char empty;

	scanf("%d %d", &K, &N);
	word* words = (word*)malloc(sizeof(word) * K);
	char* first = (char*)malloc(sizeof(char) * (N + 1));
	for (int i = 0; i < K; i++) {
		scanf("%s", &words[i].w);
		words[i].cnt = 0;
	}
	for (int i = 0; i < N; i++) {
		scanf("%c", &empty);
		scanf("%c", &input);
		first[i] = input;
	}
	sorting(words, K);
	printWord(first, words, K, N);
}