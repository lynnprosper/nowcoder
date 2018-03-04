#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

struct Node
{
	Node() :ra(0){}
	int x, y, ra;
};

int N;
const int Max = 1002;
const double INF = 9e20; //**要足够大， 小的话，后两个点过不去
vector<Node> mv;
double G[Max][Max];//**存储两点间距离
double dis[Max];//**起点到某点距离
int vis[Max] = { 0 };

void dijk();//***经典的dijkstra算法
double get_dist(int aa, int bb);//**计算两点暴露的距离
int find_min();

/*
题意：最短路问题
思路：
难点在于把题意抽象成图，
即表示成传统的图的矩阵。
那么，我们可以在读取所有圆点信息后，
依次计算出每两点的暴露距离，存储到矩阵里。
然后，用传统的dijkstra算法求就可以了。
已AC
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	mv.resize(N + 2);//**存储所有圆点
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &mv[i].x, &mv[i].y, &mv[i].ra);
	}
	scanf("%d %d", &mv[N].x, &mv[N].y);
	scanf("%d %d", &mv[N+1].x, &mv[N+1].y);
	N += 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
			G[i][j] = G[j][i] = get_dist(i, j);//**计算距离
	}
	dijk();
	printf("%.2f\n", dis[N - 1]);

	return 0;
}

double get_dist(int aa, int bb)//**计算两点暴露的距离
{
	double re = sqrt(pow(mv[aa].x - mv[bb].x, 2) + pow(mv[aa].y - mv[bb].y, 2))
		- mv[aa].ra - mv[bb].ra;
	return (max(re, 0.0));
}
void dijk()//***经典的dijkstra算法
{
	for (int i = 0; i < N; i++)
	{
		dis[i] = G[N - 2][i];
	}
	dis[N - 2] = 0;
	vis[N - 2] = 1;

	while (1)
	{
		int v = find_min();
		if (v < 0)
			break;
		vis[v] = 1;

		for (int w = 0; w < N; w++)
		{
			if (vis[w] == 0 && (G[v][w] + dis[v] < dis[w]))
			{
				dis[w] = G[v][w] + dis[v];
			}
		}
	}
}

int find_min()
{
	int mid = -1;
	double md = INF;
	for (int i = 0; i < N; i++)
	{
		if (vis[i] == 0 && dis[i] < md)
		{
			mid = i;
			md = dis[i];
		}
	}

	return mid;
}
