#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct factory{ //소요시간, 선행공정, 작업했는지 확인
	int dur;
	int b_num;
	int before[101];
	bool isDone;
}factory;
factory task[101];

bool isPos(factory t) {
	bool allDone = true;
	if (t.isDone) //이미 한 일이면 또 할 이유가 없음
		return false;
	if (t.b_num == 0) //선행되어야 하는 일이 없으면 바로 할 수 있음
		return true;
	for (int i = 0; i < t.b_num; i++) { //선행되어야 하는 모든 일들을 이미 했다면 바로 할 수 있음
		if (task[t.before[i]].isDone == false)
			allDone = false;
	}
	if (allDone)
		return true;
	else
		return false;
}

int main() {
	int N, R;
	int temp_b, temp_a;
	int temp_arr[101];
	int check_arr[101];
	int sum = 0;
	int obj_t;

	scanf("%d %d", &N, &R);
	for (int i = 1; i <= N; i++) { //구조체에 값 채움
		scanf("%d", &task[i].dur);
		task[i].b_num = 0;
		task[i].isDone = false;
	}
	for (int i = 0; i < R; i++) {
		scanf("%d %d", &temp_b, &temp_a);
		task[temp_a].before[task[temp_a].b_num++] = temp_b; //선행되어야 하는 공정을 입력
	}
	scanf("%d", &obj_t); //마지막 공정
	while (true) {
		int arr_cnt = 0;
		if (task[obj_t].isDone==true) //마지막 공정까지 했으면 반복문 빠져나옴
			break;
		for (int i = 1; i <= N; i++) { //모든 공정에 대해 이번에 할 수 있는 일인지 확인
			if (isPos(task[i])) {
				check_arr[arr_cnt] = i; //나중에 isDone을 한번에 true로 바꾸기 위해 배열에 넣어둠
				temp_arr[arr_cnt++] = task[i].dur; //걸리는 시간을 저장하는 배열
			}
		}
		int max_task = temp_arr[0];
		for (int i = 1; i < arr_cnt; i++) { //가장 오래 걸리는 일을 체크
			if (max_task < temp_arr[i])
				max_task = temp_arr[i];
		}
		sum += max_task; //sum에 가장 오래 걸리는 일만 더해줌
		for (int i = 0; i < arr_cnt; i++) //일을 다 했으므로 isDone을 true로 바꿔줌
			task[check_arr[i]].isDone = true;
	}
	printf("%d", sum);
}