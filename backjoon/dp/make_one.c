/*
 * https://www.acmicpc.net/problem/1463
 */

#include <stdio.h>
#include <limits.h>

#define MAX 1000005
int data[MAX] = {0,};

int min(int a, int b)
{
	if (a>b)
		return b;
	return a;
}

int main()
{
	int N;
	int i;
	scanf("%d", &N);
	data[N] = 0;
	for (i = 1; i < N; i++)
		data[i] = INT_MAX;

	for (int i = N; i >= 1; i--)
	{
		if (i % 3 == 0) data[i/3] = min(data[i/3], data[i] + 1);
		if (i % 2 == 0) data[i/2] = min(data[i/2], data[i] + 1);
		data[i-1] = min(data[i-1], data[i] + 1);
	}

	printf("%d\n", data[1]);
	return 0;
}
