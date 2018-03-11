#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

const int Max = 1000;
int G[Max][Max] = { 0 }; //**图的邻接矩阵表示
int indeg[Max] = { 0 }; //**每个点的入度
vector<int> re;	//**存储结果
priority_queue<int, vector<int>, greater<int> > Q; 
int N, M;

bool toporder(); //**拓扑排序

/*
题意：拓扑排序题。
思路：
有一点要注意的是用优先队列，id小的优先输出。
已AC.
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	int ca, cb;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &ca, &cb);
		G[ca][cb] = 1;
		indeg[cb]++; //**统计入度
	}
	if (toporder())
	{
		printf("YES\n");
		for (int i = 0; i < N; i++)
		{
			if (i != 0)
				printf(" ");
			printf("%d", re[i]);
		}
	}
	else
		printf("NO\n%d\n", N - re.size());


	return 0;
}

bool toporder()
{
	for (int i = 0; i < N; i++)
	{
		if (indeg[i] < 1)
			Q.push(i);
	}

	while (!Q.empty())
	{
		int w = Q.top();
		Q.pop();
		re.push_back(w); //**保存结果
		for (int i = 0; i < N; i++)
		{
			if (G[w][i] > 0)
			{
				if (--indeg[i] == 0) //入度减为0可以入队
					Q.push(i);
			}
		}
	}

	if (re.size() == N)
		return true;
	else
		return false;
}
