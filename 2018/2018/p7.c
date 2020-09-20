#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertion_sort(int arr[], int length) { //�������� ��������
	for (int i = 1; i < length; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

double avg(int arr[], int length) {
	if (length == 1) //1���� ���� ���� �����ϱ�
		return arr[0];
	double avg = (arr[0] + arr[1]) / 2.0; //ó�� 2�� ���� ���
	for (int i = 2; i < length; i++)
		avg = (avg + arr[i]) / 2.0;
	return avg;
}

int main() { //������ ����� ����
	int n;
	int num_arr[20];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num_arr[i]);
	insertion_sort(num_arr, n);
	printf("%.6f", avg(num_arr, n));
}