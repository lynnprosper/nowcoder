#include<iostream>
#define MAX 10001
using namespace std;

/*
枚举一下，其实就是斐波那契数列，哈哈
*/
int main()
{
	int a[MAX] = { 0 };
	a[0] = a[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		a[i] = a[i] % 10000;
	}

	int n, i, t;
	while (cin >> n)
	{
		for (i = 0; i < n; i++)
		{
			cin >> t;
			printf("%04d", a[t]);
		}
		printf("\n");
	}

	return 0;
}
