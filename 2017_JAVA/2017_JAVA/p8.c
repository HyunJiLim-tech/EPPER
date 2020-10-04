#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char key[31];
int key_cnt = 0;

typedef struct menu { //�� �ܾ�, key�� ��ġ, ���� ���θ� ����ü�� ����
	char name[21];
	int key_pos;
	bool space;
}menu;

bool isSpace(char c[21]) { //������ �ִ��� Ȯ��
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == ' ')
			return true;
	}
	return false;
}

bool isKey(char c) { //�ش� ���ڰ� key�� �� �� �ִ��� Ȯ��
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
	for (int i = 0; i < n; i++) //key_pos �ʱ�ȭ
		menus[i].key_pos = 1000;
	scanf("%c", &empty);
	for (int i = 0; i < n; i++) {
		gets(menus[i].name); //���� ���� �Է�
		if (isSpace(menus[i].name)) //���� ���� Ȯ��
			menus[i].space = true;
		else
			menus[i].space = false;
	}
	for (int i = 0; i < n; i++) {
		check = false;
		if (isKey(menus[i].name[0])) { //ù��° ���ڰ� key�� �� �� �ִ��� Ȯ��
			key[key_cnt++] = menus[i].name[0];
			menus[i].key_pos = 0;
			check = true;
		}
		else if (menus[i].space) { //������ �ִٸ�
			for (int j = 0; j < strlen(menus[i].name); j++) {
				if (menus[i].name[j] == ' ' && isKey(menus[i].name[j + 1])) { //���� ���� ���ڰ� key�� �� �� �ִ��� Ȯ��
					key[key_cnt++]=menus[i].name[j+1];
					menus[i].key_pos = j + 1;
					check = true;
				}
			}
		}
		if (!check) { //�� �� �������� key�� ã�� ���ߴٸ�
			for (int j = 0; j < strlen(menus[i].name); j++) {
				if (menus[i].name[j] != ' ' && isKey(menus[i].name[j])) { //������ �ƴ� ���ڿ� ���� key�� �� �� �ִ��� Ȯ��
					key[key_cnt++] = menus[i].name[j];
					menus[i].key_pos = j;
					break; //ã�� ��� break
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strlen(menus[i].name); j++) { //key�� �ش��ϴ� ���ڸ� �¿쿡 ��ȣ�� ������
			if (j == menus[i].key_pos)
				printf("[");
			printf("%c", menus[i].name[j]);
			if (j== menus[i].key_pos)
				printf("]");
		}
		printf("\n");
	}
}