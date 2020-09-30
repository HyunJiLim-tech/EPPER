#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct factory{ //�ҿ�ð�, �������, �۾��ߴ��� Ȯ��
	int dur;
	int b_num;
	int before[101];
	bool isDone;
}factory;
factory task[101];

bool isPos(factory t) {
	bool allDone = true;
	if (t.isDone) //�̹� �� ���̸� �� �� ������ ����
		return false;
	if (t.b_num == 0) //����Ǿ�� �ϴ� ���� ������ �ٷ� �� �� ����
		return true;
	for (int i = 0; i < t.b_num; i++) { //����Ǿ�� �ϴ� ��� �ϵ��� �̹� �ߴٸ� �ٷ� �� �� ����
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
	for (int i = 1; i <= N; i++) { //����ü�� �� ä��
		scanf("%d", &task[i].dur);
		task[i].b_num = 0;
		task[i].isDone = false;
	}
	for (int i = 0; i < R; i++) {
		scanf("%d %d", &temp_b, &temp_a);
		task[temp_a].before[task[temp_a].b_num++] = temp_b; //����Ǿ�� �ϴ� ������ �Է�
	}
	scanf("%d", &obj_t); //������ ����
	while (true) {
		int arr_cnt = 0;
		if (task[obj_t].isDone==true) //������ �������� ������ �ݺ��� ��������
			break;
		for (int i = 1; i <= N; i++) { //��� ������ ���� �̹��� �� �� �ִ� ������ Ȯ��
			if (isPos(task[i])) {
				check_arr[arr_cnt] = i; //���߿� isDone�� �ѹ��� true�� �ٲٱ� ���� �迭�� �־��
				temp_arr[arr_cnt++] = task[i].dur; //�ɸ��� �ð��� �����ϴ� �迭
			}
		}
		int max_task = temp_arr[0];
		for (int i = 1; i < arr_cnt; i++) { //���� ���� �ɸ��� ���� üũ
			if (max_task < temp_arr[i])
				max_task = temp_arr[i];
		}
		sum += max_task; //sum�� ���� ���� �ɸ��� �ϸ� ������
		for (int i = 0; i < arr_cnt; i++) //���� �� �����Ƿ� isDone�� true�� �ٲ���
			task[check_arr[i]].isDone = true;
	}
	printf("%d", sum);
}