/*
 * https://www.acmicpc.net/problem/2747
 */

#include <stdio.h>

static unsigned long long fibonacci(int n)
{
#define MAX_CACHE 101
	static unsigned long long cache[MAX_CACHE] = { 0, 1, 1, };

	if (n == 0)
		return 0;
	if (cache[n] != 0)
		return cache[n];

	return cache[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%llu\n", fibonacci(n));

	return 0;
}
