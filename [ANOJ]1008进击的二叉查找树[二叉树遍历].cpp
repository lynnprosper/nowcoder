#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
vector<int> pa, pb;

struct Node
{
	Node() :left(NULL), right(NULL){}
	int da;
	Node *left, *right;
};

Node *ta = NULL;
Node *tb = NULL;

void build(Node *&t, int x);//**递归插入建树
void post_ord(Node *t, vector<int> &v);//**后序遍历
void level_ord(); //**层序遍历

/*
题意：二叉树遍历。
思路：
先递归建树，
然后判断两树的后序是否相等即可。
已AC.
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	int tx;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tx);
		build(ta, tx);	//建树
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tx);
		build(tb, tx);
	}
	post_ord(ta, pa);
	post_ord(tb, pb);
	
	if (pa == pb) //后序相等
		printf("YES\n");
	else
		printf("NO\n");
	for (int i = 0; i < N; i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", pa[i]);
	}
	printf("\n");
	level_ord();

	return 0;
}

void build(Node *&t, int x)
{
	if (t == NULL)
	{
		t = new Node();
		t->da = x;
		return;
	}

	if (x > t->da)
		build(t->right, x);
	else
		build(t->left, x);
}

void post_ord(Node *t, vector<int> &v)
{
	if (t == NULL)
		return;
	post_ord(t->left, v);
	post_ord(t->right, v);
	v.push_back(t->da);
	return;
}

void level_ord()
{
	queue<Node *> Q;
	Q.push(ta);

	int flag = 0;
	while (!Q.empty())
	{
		Node *nx = Q.front();
		Q.pop();
		if (flag != 0)
			printf(" ");
		printf("%d", nx->da);
		flag = 1;

		if (nx->left != NULL)
			Q.push(nx->left);
		if (nx->right != NULL)
			Q.push(nx->right);
	}
}
