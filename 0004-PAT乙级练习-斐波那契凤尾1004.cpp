#include<iostream>
#define MAX 100001
using namespace std;

int main()
{
	int A[MAX] = {0};
	int i, n;
	A[1] = 1;
	A[2] = 2;
	for(i = 3; i < MAX; i++)
	{
		A[i] = A[i-1] + A[i-2]; //只需要加后六位；
		A[i] %= 1000000;
	}	
	
	while(cin >> n)
	{
		if(n < 25) printf("%d\n", A[n]);
		else printf("%06d\n", A[n]);	
	}
	
	return 0;
}
