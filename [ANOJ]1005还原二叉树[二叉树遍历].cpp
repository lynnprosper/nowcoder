#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	Node() :left(NULL), right(NULL) {}
	int da;
	Node *left, *right;
};
Node *T = NULL;
vector<int> ino;
int N, flag = 0;

//**参数为当前层序序列， 中序的左、右边界。
Node *createTree(vector<int> &lo, int nl, int nr);
void pre(Node *t); //前序遍历
void post(Node *t);//后序遍历

/*
题意：由层序和中序构建二叉树。
思路：
层序第一个根结点，在中序里分成左树和右树两部分。
然而根的左树在层序里是分散开的，该如何递归处理呢？
于是我们可以把层序中属于左树的元素找出来，右树同理。
后面就可以递归处理了。
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	ino.resize(N);
	vector<int> lev(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &lev[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &ino[i]);
	T = createTree(lev, 0, N - 1); //建树
	pre(T);
	printf("\n");
	flag = 0;
	post(T);
	printf("\n");

	return 0;
}

Node *createTree(vector<int> &lo, int nl, int nr)
{
	if (lo.size() < 1)
		return NULL;

	vector<int> lv, nv; //左、右子树的层序
	int H[33] = { 0 };
	int pos;
	for (pos = nl; pos <= nr; pos++)
	{
		if (ino[pos] == lo[0])
		{
			break;
		}
		H[ino[pos]] = 1; //标记左子树元素
	}

	for (int i = 1; i < lo.size(); i++)
	{
		if (H[lo[i]] == 1)
			lv.push_back(lo[i]); //保存左子树层序
		else
			nv.push_back(lo[i]); //保存右子树层序
	}
	Node *t = new Node();
	t->da = lo[0];
	t->left = createTree(lv, nl, pos - 1);
	t->right = createTree(nv, pos + 1, nr);
	return t;
}

void pre(Node *t)
{
	if (t == NULL)
		return;

	if (flag != 0)
		printf(" ");
	printf("%d", t->da);
	flag = 1;
	pre(t->left);
	pre(t->right);
}
void post(Node *t)
{
	if (t == NULL)
		return;

	post(t->left);
	post(t->right);
	if (flag != 0)
		printf(" ");
	printf("%d", t->da);
	flag = 1;
}
