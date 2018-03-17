#include<iostream>
#include<cstdint>
using namespace std;

const uint64_t Mod = 1000000007;
int N, M, L, K, ss, dd, num;
uint64_t G[30][30] = { 0 }; //**原始矩阵
uint64_t res[30][30] = { 0 };//**结果矩阵
uint64_t tp[30][30] = { 0 };//**计算结果咱村

void calc();
/*
题意：求两点路径长度L的路径条数。
思路：
这里用到了图论的一个知识点，
即矩阵A^n中的元素aij, 表示从i到j长度为n的路径条数。
所以这题本质上计算矩阵了。
如果不知道这个，递归处理，会超时，复杂度太高了。
已AC.
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &L);
	int ca, cb;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &ca, &cb);
		G[ca][cb] = 1;
	}
	for (int i = 0; i < N; i++) //**置为单位矩阵
		res[i][i] = 1;
	calc();
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &ss, &dd);
		printf("%llu\n", res[ss][dd]);
	}

	return 0;
}
void calc()
{
	//**矩阵三次乘法
	for (int k = 0; k < L; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				tp[i][j] = 0;
				for (int m = 0; m < N; m++)
					tp[i][j] = (tp[i][j] + (res[i][m] * G[m][j]) % Mod) % Mod;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				res[i][j] = tp[i][j];
			}
		}
	}
}
