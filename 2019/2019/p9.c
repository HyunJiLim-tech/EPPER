#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int m[30001];
int m_max[30001];

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void find_max(int num) {
	if (num <= 3)
		return;
	for (int i = 4; i <= num; i++) {
		m_max[i] = max(m_max[i - 1], max(m[i] + m[i - 1] + m_max[i - 3], m[i] + m_max[i - 2]));
	}
}

int main() { 
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &m[i]);
	m_max[1] = m[1];
	m_max[2] = m[2] + m[1];
	m_max[3] = max(m[1] + m[3], m[2] + m[3]);
	find_max(n);
	printf("%d", m_max[n]);
}