#include<iostream>
#include<cmath>
using namespace std;
 
 //不用求素数，直接从2开始除，相当于筛法求素数的逆过程； 
int main()
{
	int tn, flag, i;
	while(scanf("%d", &tn) != EOF)
	{
		i = 2;
		flag = 1;
		int mx = (int)sqrt(tn);	//最多根号n； 
		printf("%d = ", tn);
		while(i <= mx && tn > 1)
		{
			if(tn % i == 0)
			{
				tn /= i;
				if(flag)
				{
					printf("%d", i);
					flag = 0;
				}	
				else 	printf(" * %d", i);
			}
			else i++;
		}
		if(tn > 1)
		{
			if(flag)
				printf("%d", tn);
			else printf(" * %d", tn);
		}
		printf("\n");
	}
	
	return 0;
}
