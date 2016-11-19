#include<iostream>
#define ulong unsigned long long

//斐波那契数列； 
int main()
{
	int n, a, b, i, j, m, di;
	ulong f[200] = {0};
	f[0] = f[1] = 1;
	m = 1;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		di = b-a;
		if(di > m)
		{
			for(j = m+1; j <= di; j++)
				f[j] = f[j-1] + f[j-2];
			m = di;
		}
		printf("%llu\n", f[di]);
	}
	
	return 0;
}
