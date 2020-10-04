#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char key[31];
int key_cnt = 0;

typedef struct menu { //각 단어, key의 위치, 공백 여부를 구조체에 저장
	char name[21];
	int key_pos;
	bool space;
}menu;

bool isSpace(char c[21]) { //공백이 있는지 확인
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == ' ')
			return true;
	}
	return false;
}

bool isKey(char c) { //해당 문자가 key가 될 수 있는지 확인
	for (int i = 0; i < key_cnt; i++) {
		if (c == key[i])
			return false;
	}
	return true;
}

int main() {
	menu menus[31];
	char empty;
	int n;
	bool check;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) //key_pos 초기화
		menus[i].key_pos = 1000;
	scanf("%c", &empty);
	for (int i = 0; i < n; i++) {
		gets(menus[i].name); //공백 포함 입력
		if (isSpace(menus[i].name)) //공백 여부 확인
			menus[i].space = true;
		else
			menus[i].space = false;
	}
	for (int i = 0; i < n; i++) {
		check = false;
		if (isKey(menus[i].name[0])) { //첫번째 문자가 key가 될 수 있는지 확인
			key[key_cnt++] = menus[i].name[0];
			menus[i].key_pos = 0;
			check = true;
		}
		else if (menus[i].space) { //공백이 있다면
			for (int j = 0; j < strlen(menus[i].name); j++) {
				if (menus[i].name[j] == ' ' && isKey(menus[i].name[j + 1])) { //공백 다음 문자가 key가 될 수 있는지 확인
					key[key_cnt++]=menus[i].name[j+1];
					menus[i].key_pos = j + 1;
					check = true;
				}
			}
		}
		if (!check) { //위 두 과정에서 key를 찾지 못했다면
			for (int j = 0; j < strlen(menus[i].name); j++) {
				if (menus[i].name[j] != ' ' && isKey(menus[i].name[j])) { //공백이 아닌 문자에 대해 key가 될 수 있는지 확인
					key[key_cnt++] = menus[i].name[j];
					menus[i].key_pos = j;
					break; //찾은 즉시 break
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strlen(menus[i].name); j++) { //key에 해당하는 문자면 좌우에 괄호를 씌워줌
			if (j == menus[i].key_pos)
				printf("[");
			printf("%c", menus[i].name[j]);
			if (j== menus[i].key_pos)
				printf("]");
		}
		printf("\n");
	}
}