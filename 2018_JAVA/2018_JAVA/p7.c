#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[9];
	int obj_num = 0;
	int x, y;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		obj_num += arr[i];
	}
	obj_num -= 100; //전체 합에서 100을 빼면 목표하는 수가 나옴
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == obj_num) { //2개 뽑아서 목표 숫자와 같은지 확인
				x = i;
				y = j;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) { //뽑힌 수 제외하고 출력
		if (i != x && i != y)
			printf("%d ", arr[i]);
	}
}