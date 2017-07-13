/*
 * https://www.acmicpc.net/submit/11726
 */

#include <stdio.h>

#define MAX 1001
#define MOD 10007

int data[MAX] = { 0, };

int main()
{
	int i;
	int N;
	scanf("%d", &N);

	data[1] = 1;
	data[2] = 2;
	for (i = 3; i <= N; i++)
		data[i] = (data[i-1] + data[i-2]) % MOD;

	printf("%d\n", data[N]);

	return 0;
}
