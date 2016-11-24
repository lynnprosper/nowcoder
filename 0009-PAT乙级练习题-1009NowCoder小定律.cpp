#include<iostream>
#include<algorithm>
#include<cmath>
#define MAX 90
using namespace std;

//先把是否素数保存起来； 
int IsPrime(int k);
int main()
{
	int a[MAX];
	int i, j = 0;
	for(i = -39; i < 50; i++)
		a[j++] = IsPrime(i*i+i+41);
	int x, y, flag = 1;
	scanf("%d %d", &x, &y);
	while(x || y)
	{
		if(x < y)
		{
			flag = 1;
			for(i = x; i <= y; i++)
			{
				if(a[i+39] == 0)
				{
					flag = 0;
					break;
				}
			}
			if(flag) printf("OK\n");
			else printf("Sorry\n");
		}
		
		scanf("%d %d", &x, &y);
	}

	return 0;
}
int IsPrime(int k)
{
	if(k == 0 || k == 1)
		return 0;
	if(k == 2)
		return 1;
	for(int i = (int)sqrt(k); i >= 2; i--)	
	{
		if(k%i == 0) return 0;
	}
	return 1;
}
