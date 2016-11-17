#include<iostream>
#define llong long long
using namespace std;

//fn = f(n-1)+f(n-3);
int main()
{
	llong a[55] = { 0 };
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	for (int i = 4; i < 55; i++)
		a[i] = a[i - 1] + a[i - 3];
	
	int n;
	while (scanf("%d", &n) != EOF)
		printf("%lld\n", a[n]);

	return 0;
}
