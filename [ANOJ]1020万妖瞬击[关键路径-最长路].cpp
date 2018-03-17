#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int Max = 1002;
int N, M;
int G[Max][Max] = { 0 }; //**存储DAG（有向无环图）
int dg[Max] = { 0 };//**记录点的入度
int ds[Max] = { 0 };//**记录某点出发的最长路,即关键路径长度
int cnt = 0;
vector<int> pt[Max], tp;//某点的后继，存储的打印路径

bool toporder(); //经典的拓扑排序
int dfs(int x);//递归获取最长路
void dfs_pt(int x);//递归打印路径

/*
题意：关键路径题。
思路：
显然这题可以采用经典的关键路径算法。
我觉得麻烦，类比dijkstra求最短路，用的递归求最长路。
注意，存在多个源点，所以这里添加一个
超级总源点N。
对于存在环的情况，还是用了拓扑排序判断的。
已AC.
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	int ca, cb, ct;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &ca, &cb, &ct);
		G[ca][cb] = ct;
		dg[cb]++; //记录入度
	}
	if (!toporder()) //存在环
		printf("NO %d\n", N - cnt);
	else
	{
		dfs(N);
		printf("YES %d\n", ds[N]-1);
		dfs_pt(N);
	}

	return 0;
}

bool toporder()
{
	queue<int> Q;
	
	for (int i = 0; i < N; i++)
	{
		if (dg[i] == 0)
		{
			Q.push(i);
			G[N][i] = 1; //在这里，把N记为总源点，到初始源点长度1.
		}
	}
	while (!Q.empty())
	{
		int ft = Q.front();
		Q.pop();
		cnt++;
		for (int i = 0; i < N; i++)
		{
			if (G[ft][i] > 0)
			{
				if (--dg[i] == 0)
					Q.push(i);
			}
		}
	}

	if (cnt == N)
		return true;
	else
		return false;
}
int dfs(int x)
{
	if (ds[x] > 0) //**递归边界，注意不是0
		return ds[x];

	for (int i = 0; i < N; i++)
	{
		if (G[x][i] > 0)
		{
			int tmp = dfs(i) + G[x][i];
			if (tmp > ds[x]) //更新最长距离
			{
				ds[x] = tmp;
				pt[x].clear();
				pt[x].push_back(i);
			}
			else if (tmp == ds[x])
			{
				pt[x].push_back(i); //存在多个后继点
			}
		}
	}

	return ds[x];
}
void dfs_pt(int x) //**递归打印
{
	if (pt[x].size() < 1) //**边界
	{
		for (int i = 0; i < tp.size(); i++)
		{	//**tp数组里没有保存总源点
			if (i != 0)
				printf("->");
			printf("%d", tp[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < pt[x].size(); i++)
	{
		tp.push_back(pt[x][i]);
		dfs_pt(pt[x][i]);
		tp.pop_back();
	}

	return;
}
