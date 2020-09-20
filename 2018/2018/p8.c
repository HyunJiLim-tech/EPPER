#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char m_arr[102]; //암호화할 배열
	char n_arr[102]; //암호화한 배열
	int key_arr[7]; //key값 저장할 배열
	int key;

	scanf("%s", &m_arr);
	scanf("%d", &key);
	int length = strlen(m_arr);
	if (length % 7 != 0) { //7로 안나눠 떨어지면 뒤에 더 붙여야 함
		int concat_cnt = 7 - (length % 7); //몇 개나 붙여야?
		for (int i = 0; i < concat_cnt; i++) {
			switch (i) { //그냥 6개니까 노가다로 스위치 돌림
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
	for (int i = 6; i >= 0; i--) { //키 값 분리해서 저장하는데 순서 반대로 안되도록 뒤부터 넣음
		key_arr[i] = key % 10;
		key /= 10;
	}
	for (int i = 0; i < length; i++) { //i=3 이고, key=7654321 이면 n_arr[i] = m_arr[3]. 0부터 저장해서 그런 것.
		n_arr[i] = m_arr[key_arr[i % 7] + (i / 7) * 7 - 1];
		printf("%c", n_arr[i]);
	}
}