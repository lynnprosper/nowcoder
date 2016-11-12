#include<iostream>
using namespace std;

//通过函数求结果的方法会超时，只能列举前几个数找规律；
//8个一个循环，第2和第6个可以；
int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n % 4 == 2)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
