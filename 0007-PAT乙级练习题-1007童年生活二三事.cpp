#include<iostream>
#define ulong unsigned long long
#define MAX 8
using namespace std;

//斐波那契数列；
int main()
{
	ulong a[MAX] = { 0 };
	a[0] = a[1] = 1;
	for (int i = 2; i < MAX; i++)
		a[i] = a[i - 1] + a[i - 2];
	int N;
	while(cin >> N)
		printf("%llu\n", a[N]);

	return 0;
}
