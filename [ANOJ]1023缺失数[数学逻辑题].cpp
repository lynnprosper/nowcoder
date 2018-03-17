#include<iostream>
#include<algorithm>
#include<cstdint> //**使用int64_t
using namespace std;

int N;
const int Max = 1e7+2;
int limit = Max - 1; //极限值
int H[Max] = { 0 };

/*
题意： 数学逻辑题。
思路：
普通方法，利用set的话，最后一个测试点还是会超时。/摊手
这题复杂度必须O(n)才不会超时。
仔细想一想，N最大值10^7, 那么结果最大值是1e7+1.
于是，我们新建一个Max大小的数组H，这里Max最小1e7+2，
为了保证H[1e7+1] = 0。
读入数据时，超过limit的忽略，范围内的保存下来。
然后遍历一遍，查找H[i] = 0 的即可。
已AC
*/

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	int64_t tin;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &tin);
		if (tin > 0 && tin < limit)
			H[tin] = 1;
	}
	
	for (int i = 1; i < Max; i++)
	{
		if (H[i] == 0)
		{
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
