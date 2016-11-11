#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Node
{
	int wt;
	int x, y;
};

/*
思路：建一个动态数组，读入非0数据，同时存储坐标。然后对花生数排序。
2.跳之前，先试探性地分配，即两点距离+摘花生+跳回路边，若符合要求，则循环下一个；
*/
bool cmp(const Node &a, const Node &b);	//比较函数，由小到大；
void CalWt(vector<Node> &p, int K);	//处理符合要求的花生；
int main()
{
	//freopen("in.txt", "r", stdin);
	vector<Node> p;
	int i, j, M, N, K;
	Node t;
	while (cin >> M >> N >> K){	//因有多组数据，记得用循环；
		for (i = 1; i <= M; i++)
		{
			for (j = 1; j <= N; j++)
			{
				cin >> t.wt;
				if (t.wt)
				{
					t.x = i;
					t.y = j;
					p.push_back(t);
				}
			}
		}
		sort(p.begin(), p.end(), cmp);	//排序；
		CalWt(p, K);	//处理数据；
	}

	return 0;
}

bool cmp(const Node &a, const Node &b)
{
	return a.wt < b.wt;
}

void CalWt(vector<Node> &p, int K)
{
	int sum = 0, time, tryone;
	Node t, collect;
	collect = p.back();
	if (collect.x * 2 + 1 <= K)	//单独处理第一个花生位置；
	{
		time = collect.x + 1;
		sum += collect.wt;
		p.pop_back();
		while (!p.empty())
		{
			t = p.back();
			tryone = time + abs(t.x - collect.x) + abs(t.y - collect.y) + 1 + t.x;
			if (tryone <= K)
			{
				time = tryone - t.x;
				sum += t.wt;
				collect = t;	//分配成功，把结点t收录到collect里，作为当前位置。
				p.pop_back();
			}
			else
				break;

		}

	}
	while (!p.empty())
		p.pop_back();
	
	cout << sum << endl;
	return;
}
