#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, M, cnt = 0; //**cnt记录树的个数
string sum;//**记录每棵树的类型
const int Max = 10002; //**最大结点数
vector<int> G[Max];//**树的邻接表表示
vector<string> res;//**存储所有树类型
int wt[Max] = { 0 }, vis[Max] = { 0 };//wt为初始类型

void dfs(int x, string &st);//递归获取树类型
void myadd(string b);//大整数加法

/*
题意： 树的遍历问题。
该题可以用并查集写，
我觉得麻烦，直接用的dfs来处理。
注意，类型可能为0。
已AC
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &wt[i]);
	}
	int ca, cb;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &ca, &cb);
		G[ca].push_back(cb);
	}

	for (int i = 0; i < N; i++)
	{
		if (vis[i] == 0) //访问未访问过的，这里已经默认从编号小的开始了
		{
			vis[i] = 1;
			string st;
			sum = "";
			cnt++;
			st.push_back(wt[i] + '0');
			dfs(i, st);
			res.push_back(sum);
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < res.size(); i++)
	{
		if (i != 0)
			cout << " ";
		if (res[i] != "") //这里可能是空，要输出0
			cout << res[i];
		else
			cout << 0;
	}

	return 0;
}

void dfs(int x, string &st)//递归获取树类型
{
	if (G[x].size() < 1)//边界
	{
		myadd(st);
		return;
	}

	for (int w = 0; w < G[x].size(); w++)
	{
		int v = G[x][w];
		vis[v] = 1;
		st.push_back(wt[v] + '0');
		dfs(v, st);
		st.pop_back();
	}
	return;
}

void myadd(string b)//大整数加法
{
	while (1) //**去除前导0
	{
		if (b[0] == '0')
			b.erase(0, 1);
		else
			break;
	}

	string c(sum);
	reverse(c.begin(), c.end());//反转过来便于计算
	reverse(b.begin(), b.end());
	
	int len = min(c.size(), b.size());
	int carry = 0;//记录进位
	sum = "";
	for (int i = 0; i < len; i++)
	{
		int bg = b[i] - '0' + c[i] - '0' + carry;
		sum.push_back(bg % 10 + '0');
		carry = bg / 10;
	}
	for (int i = len; i < b.size(); i++)//这两个循环只会执行一个，
	{
		int bg = b[i] - '0' + carry;
		sum.push_back(bg % 10 + '0');
		carry = bg / 10;
	}
	for (int i = len; i < c.size(); i++)
	{
		int bg = c[i] - '0' + carry;
		sum.push_back(bg % 10 + '0');
		carry = bg / 10;
	}
	if (carry > 0)
		sum.push_back('1');
	reverse(sum.begin(), sum.end());
}
