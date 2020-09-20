#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bracket(int left, int right) {
	if (left == 0 && right == 0) //�� �� ���� ���Ÿ� 1 ��ȯ
		return 1;
	else {
		if (left == 0) //���� ��ȣ �پ��� �����ʸ� ���
			return bracket(left, right - 1);
		else if (left <= (right - 1)) //��� ��Ȳ���� ������ ��ȣ�� ���� ��ȣ���� ���ų� ���ƾ� ¦ ����
			return bracket(left - 1, right) + bracket(left, right - 1);
		else //���� ��ȣ�� ������ ��ȣ�� ���� ���� ���. ������ ���� ������ ���� ������ ������ ��Ȳ
			return bracket(left - 1, right);
	}
}

int main() {
	int n, cnt = 0;

	scanf("%d", &n);
	printf("%d", bracket(n, n));
}