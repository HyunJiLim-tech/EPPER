#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void insertion_sort(int arr[], int point) { //삽입 정렬(내림차순 정렬)
	int temp = 0;
	
	for (int i = 1; i < point; i++) {
		temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] < temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

int merge(int arr[], int length) { //배열로 쪼개놓은 숫자 다시 합치기. 근데 생각해보니 그냥 출력이니까 걍 출력해도 됐을듯
	int mul = 1;
	int sum = 0;
	
	for (int i = 0; i < length; i++) {
		sum = sum + (arr[i] * mul);
		mul *= 10;
	}
	return sum;
}

/*313220 이라면 022313으로 저장되어있을 것임.
맨 오른쪽 3부터 0으로 향하면서 내 왼쪽에 있는 수 중에 나보다 큰 수가 있는지 체크함
있으면 찾은거니까 findPoint true로 바꾸고 해당 지점 저장하고, 나랑 나보다 큰 애를 바꿈. 여기선 1과 2
다 돌았는데 findPoint가 여전히 false라면 오름차순이라는 것임(ex. 330) 이럼 얘가 제일 큰거니까 0 출력
그러고 나서 point 기준으로 왼쪽에 있는 배열을 내림차순 정렬함. 마지막에 합쳐주면 끝*/
int main() {
	int num_arr[6];
	int num;

	scanf("%d", &num);
	int cnt = 0;
	while (num != 0) { //문자 쪼개놓음
		num_arr[cnt++] = num % 10;
		num /= 10;
	}

	int point;
	bool findPoint = false;
	for (int i = 1; i < cnt; i++) {
		if (findPoint)
			break;
		for (int j = 0; j < i; j++) {
			if (num_arr[i] < num_arr[j]) {
				int temp = num_arr[i]; //swap
				num_arr[i] = num_arr[j];
				num_arr[j] = temp;
				point = i;
				findPoint = true;
				break;
			}
		}
	}
	if (!findPoint)
		printf("0");
	else {
		insertion_sort(num_arr, point);
		printf("%d", merge(num_arr, cnt));
	}
}