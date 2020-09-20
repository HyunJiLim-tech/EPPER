#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void insertion_sort(int arr[], int point) { //���� ����(�������� ����)
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

int merge(int arr[], int length) { //�迭�� �ɰ����� ���� �ٽ� ��ġ��. �ٵ� �����غ��� �׳� ����̴ϱ� �� ����ص� ������
	int mul = 1;
	int sum = 0;
	
	for (int i = 0; i < length; i++) {
		sum = sum + (arr[i] * mul);
		mul *= 10;
	}
	return sum;
}

/*313220 �̶�� 022313���� ����Ǿ����� ����.
�� ������ 3���� 0���� ���ϸ鼭 �� ���ʿ� �ִ� �� �߿� ������ ū ���� �ִ��� üũ��
������ ã���Ŵϱ� findPoint true�� �ٲٰ� �ش� ���� �����ϰ�, ���� ������ ū �ָ� �ٲ�. ���⼱ 1�� 2
�� ���Ҵµ� findPoint�� ������ false��� ���������̶�� ����(ex. 330) �̷� �갡 ���� ū�Ŵϱ� 0 ���
�׷��� ���� point �������� ���ʿ� �ִ� �迭�� �������� ������. �������� �����ָ� ��*/
int main() {
	int num_arr[6];
	int num;

	scanf("%d", &num);
	int cnt = 0;
	while (num != 0) { //���� �ɰ�����
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