#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char input[101];
	char arr[101];
	int cnt = 0;

	scanf("%s", &input);
	int length = strlen(input);
	arr[cnt++] = input[0]; //ù �ܾ� �ְ�
	for (int i = 1; i < length; i++) {
		if (input[i] == '-') //������ ������ ���� �ܾ� ����
			arr[cnt++] = input[i + 1];
	}
	for (int i = 0; i < cnt; i++)
		printf("%c", arr[i]);
	printf("\n");
}