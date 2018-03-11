#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
using namespace std;

int N;
uint64_t sum = 0, leftsum = 0; //**存储总和及左子集和
vector<int> mv;

/*
题意：排序题
思路：
鉴于元素规模小，可以直接用sort排序。
已AC.
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	mv.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &mv[i]);
		sum += mv[i];
	}
	sort(mv.begin(), mv.end());
	for (int i = 0; i < N / 2; i++)
		leftsum += mv[i];
	if (N % 2 == 1 && mv[N / 2] < 0) //**这里要判断中间的元素是否小于0，负数划给左子集
		leftsum += mv[N / 2];
	if (N % 2 == 0)
		printf("0 %llu\n", sum - leftsum * 2);
	else
		printf("1 %llu\n", sum - leftsum * 2);

	return 0;
}
