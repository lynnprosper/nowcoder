#include<iostream>
#include<algorithm>
#define ulong unsigned long long
using namespace std;

//就是斐波那契数列，数据要用长整型；
ulong func(int n);
int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	ulong cnt;

	while (scanf("%d", &n) != EOF)
	{
		cnt = func(n);
		printf("%llu\n", cnt);
	}

	return 0;
}

ulong func(int n)
{
	ulong f1 = 1, f2 = 2;
	ulong fn = f2;
	if (n == 1)
		return 1;
	else
	{
		while (n > 2)
		{
			n--;
			fn = f2 + f1;
			f1 = f2;
			f2 = fn;
		}
		return fn;
	}
}
