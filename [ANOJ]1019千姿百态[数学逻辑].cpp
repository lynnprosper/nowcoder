#include<iostream>
#include<cstdint>
using namespace std;

int F, N, M;
const int Max = 10;
const uint64_t Mod = 1000000007;
uint64_t res[Max] = { 0 }; //**存储结果
uint64_t C(int n);//计算

/*
题意：数学逻辑题
思路：
二叉树与二叉查找树的形态数是相同的。
对一棵有N个结点的二叉树来说，假设其形态数为F[N]。由于根节点会占用一
个结点，所以左子树和右子树的结点个数之和是N-1。如果左子树有a个结点，
右子树有N-1-a个结点，那么左子树的形态数为F[a]，右子树的形态数为F[N-1-a]，那么对整体二叉树来说形
态数为F[a]*F[N-1-a]。于是我们可以遍历0<=a<=N-1，将F[a]*F[N-1-a]累加起来，就可以得
到F[N]，而计算F[a]与F[N-1-a]则可以递归得到。注意计算过程中要取模。
另外可以用求卡特兰数的方法， C2n n / (n+1)。
已AC.
*/

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d%d", &F, &N);
	printf("%llu\n", C(N));

	return 0;
}

uint64_t C(int n)
{
	if (n == 1 || n == 0)
		return res[n] = 1;
	if (res[n] > 0)
		return res[n];
	else
	{
		for (int i = 0; i < n; i++)
			res[n] = (res[n] + (C(i)*C(n - i - 1) % Mod)) % Mod;
		return res[n];
	}
}
