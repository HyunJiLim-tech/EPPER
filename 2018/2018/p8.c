#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char m_arr[102]; //��ȣȭ�� �迭
	char n_arr[102]; //��ȣȭ�� �迭
	int key_arr[7]; //key�� ������ �迭
	int key;

	scanf("%s", &m_arr);
	scanf("%d", &key);
	int length = strlen(m_arr);
	if (length % 7 != 0) { //7�� �ȳ��� �������� �ڿ� �� �ٿ��� ��
		int concat_cnt = 7 - (length % 7); //�� ���� �ٿ���?
		for (int i = 0; i < concat_cnt; i++) {
			switch (i) { //�׳� 6���ϱ� �밡�ٷ� ����ġ ����
			case 0:
				m_arr[length++] = 'a';
				break;
			case 1:
				m_arr[length++] = 'b';
				break;
			case 2:
				m_arr[length++] = 'c';
				break;
			case 3:
				m_arr[length++] = 'd';
				break;
			case 4:
				m_arr[length++] = 'e';
				break;
			case 5:
				m_arr[length++] = 'f';
				break;
			}
		}
	}
	for (int i = 6; i >= 0; i--) { //Ű �� �и��ؼ� �����ϴµ� ���� �ݴ�� �ȵǵ��� �ں��� ����
		key_arr[i] = key % 10;
		key /= 10;
	}
	for (int i = 0; i < length; i++) { //i=3 �̰�, key=7654321 �̸� n_arr[i] = m_arr[3]. 0���� �����ؼ� �׷� ��.
		n_arr[i] = m_arr[key_arr[i % 7] + (i / 7) * 7 - 1];
		printf("%c", n_arr[i]);
	}
}