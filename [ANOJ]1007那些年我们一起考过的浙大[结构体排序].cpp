#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>
using namespace std;

struct Node
{
	Node(){}
	Node(uint64_t a, int b, int c, int d, int e, int f)
		:id(a), ga(b), gb(c), gc(d), gd(e), gt(f){}
	bool operator< (const Node &b) //**重载比较运算符
	{
		if (gt == b.gt)
			return (id < b.id);
		else
			return (gt > b.gt);
	}
	uint64_t id;
	int ga, gb, gc, gd, gt;
};
int aa, bb, cc, dd, tt, N;
vector<Node> mv; //存储结果

/*
题意：按照要求输出总分。
思路：
结构体排序，不难。
读入数据时判断条件，然后排序输出即可。
注意，id不足13位前要补0.
已AC.
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d %d %d %d", &aa, &bb, &cc, &dd, &tt);
	scanf("%d", &N);
	uint64_t tid;
	int ta, tb, tc, td, to;
	for (int i = 0; i < N; i++)
	{
		scanf("%llu %d %d %d %d", &tid, &ta, &tb, &tc, &td);
		to = ta + tb + tc + td;
		if (ta >= aa && tb >= bb && tc >= cc && td >= dd && to >= tt)
			mv.push_back(Node(tid, ta, tb, tc, td, to));
	}
	sort(mv.begin(), mv.end());
	printf("%d\n", mv.size());
	for (int i = 0; i < mv.size(); i++)
	{
		printf("%013llu %d\n", mv[i].id, mv[i].gt);
	}

	return 0;
}
