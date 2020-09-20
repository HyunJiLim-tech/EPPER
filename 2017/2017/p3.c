#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char name[50][51];
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", &name[i]);
	for(int i=0;i<n;i++)
		printf("Hello, %s!\n", name[i]);
}