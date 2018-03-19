#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdint>
#include<cstring>
#include<functional>
using namespace std;

struct Node
{
	Node(){}
	Node(int64_t w, int d) :wt(w), id(d){}
	int64_t wt; //**边的消耗时间
	int id; 
};

typedef pair<int64_t, int> mypair; //**对应距离， id号
int N, M, P, K;
const int Max = 10;
const int64_t INF = 0X3fffffffffffffff;
vector<Node> G[Max], R[Max]; //正向图，反向图
vector<int> ept; //存储终点
int64_t ds[Max], rds[Max];//正向图和反向图的最短距离

void dijk(vector<Node> G[], int64_t ds[]); //**经典的dijkstra算法

/*
题意：最短路问题。
思路：
本质上是给出多个源点， 多个终点，求到所有终点以及反过来的最短距离和。
对于多个源点，可以借鉴关键路径的思路，添加一个超级源点，路权置为0。
另一个问题，终点到源点的最短路如何求呢？
其实，我们把正向图反过来，正向图的终点就可以当源点了，同样用dijk算法。
已AC.
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d %d %d", &N, &M, &P, &K);

	for (int i = 0; i < P; i++)
	{
		int nid;
		scanf("%d", &nid);
		G[0].push_back(Node(0, nid));
		G[nid].push_back(Node(0, 0));
		R[nid].push_back(Node(0, 0)); //构造反向图
		R[0].push_back(Node(0, nid));
	}
	for (int i = 0; i < K; i++)
	{
		int nid;
		scanf("%d", &nid);
		ept.push_back(nid);
	}
	for (int i = 0; i < M; i++)
	{
		int ca, cb;
		int64_t cw;
		scanf("%d %d %lld", &ca, &cb, &cw);
		G[ca].push_back(Node(cw, cb));
		R[cb].push_back(Node(cw, ca));
	}
	dijk(G, ds); //正向一遍
	dijk(R, rds); //反向一遍
	int64_t sum = 0, maxlen = 0;
	for (int i = 0; i < K; i++)
	{
		sum += (ds[ept[i]] + rds[ept[i]]); //**最后累计和
		maxlen = max(maxlen, rds[ept[i]]); //这里要减去最大的一个，因为决斗的时候不需要回去了。
	}
	sum -= maxlen;
	printf("%lld\n", sum);

	return 0;
}

void dijk(vector<Node> G[], int64_t ds[])
{ //**这里选最小距离的时候，没用传统的数组，用的优先队列，降低复杂度
	priority_queue<mypair, vector<mypair>, greater<mypair> > Q;
	Q.push(mypair(0, 0));
	fill(ds, ds + Max, INF);
	ds[0] = 0;

	while (!Q.empty())
	{
		int vid = Q.top().second;
		int64_t vt = Q.top().first;
		Q.pop();
		for (int i = 0; i < G[vid].size(); i++)
		{
			if (ds[vid] + G[vid][i].wt < ds[G[vid][i].id])
			{
				ds[G[vid][i].id] = ds[vid] + G[vid][i].wt;
				Q.push(mypair(ds[G[vid][i].id], G[vid][i].id));
			}
		}
	}
}
