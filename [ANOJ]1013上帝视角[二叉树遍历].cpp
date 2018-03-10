#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

/* 表示结点总数， 最小x坐标值，最大x坐标值， 最大y坐标值*/
int N, minx = 100, mx = -100, my = -1;
set<int> lrt;	//**用来存储x+y的和
vector<int> lv, nv, pv, tv;//**层序，中序，先序和后序的容器

void dfs(vector<int> v, int nl, int nr, int x, int y); //**递归处理
void my_print(vector<int> &v);

/*
题意：二叉树遍历题。
思路：
这题有点难。
首先要实现层序和中序生成先序和后序。
层序第一个根结点，在中序里分成左树和右树两部分。
然而根的左树在层序里是分散开的，该如何递归处理呢？
于是我们可以把层序中属于左树的元素找出来，右树同理。
后面就可以递归处理了。
关于视角个数，我用的坐标处理。
根标记为原点，往左走x-1，y+1；
往右走，x+1, y+1;
显然从右看，y的最大值+1即为个数；
从上往下，x的最大和最小值差+1即为个数；
从右上，x+y和的不同个数。
已AC.
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	lv.resize(N);
	nv.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &lv[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &nv[i]);
	dfs(lv, 0, N - 1, 0, 0);
	my_print(pv);
	my_print(tv);
	printf("%d\n%d\n%d\n", my + 1, lrt.size(), mx - minx + 1);

	return 0;
}

/* 参数分别为当前层序， 中序的左侧，右侧，当前结点的x, y坐标*/
void dfs(vector<int> v, int nl, int nr, int x, int y)
{
	if (nl > nr)
		return;

	int pos = 0, H[33] = { 0 }, S[33] = { 0 };
	vector<int> left, right;
	for (int i = nl; i <= nr; i++)
	{

		if (nv[i] == v[0])
		{
			pos = i;
			break;
		}
		else
		{
			H[nv[i]] = 1;//标记为左树的层序
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (H[v[i]] == 1)
			left.push_back(v[i]);//保存左树层序
	}
	for (int i = pos + 1; i <= nr; i++)
	{
		S[nv[i]] = 1;	//标记为右树的层序
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (S[v[i]] == 1)
			right.push_back(v[i]);	//保存右树层序
	}

	/*更新坐标值*/
	lrt.insert(x + y);
	minx = min(minx, x);
	mx = max(x, mx);
	my = max(y, my);

	pv.push_back(v[0]);
	dfs(left, nl, pos - 1, x - 1, y + 1);//递归左树
	dfs(right, pos + 1, nr, x + 1, y + 1);//递归右树
	tv.push_back(v[0]);

	return;
}

void my_print(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", v[i]);
	}
	printf("\n");
}
