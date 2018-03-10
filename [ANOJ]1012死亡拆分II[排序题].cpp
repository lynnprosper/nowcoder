#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<string>
using namespace std;

int N;
vector<int> mv; //存储元素
uint64_t sum = 0, leftsum = 0;

/*
题意： 排序题。
思路：由于个数很大，不能直接用sort。
这里利用快排的思想进行部分排序。
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

	int pos, low0 = 0, high0 = N - 1;
	while (1)
	{
		int low = low0;
		int high = high0;
		
		//**这里对枢轴元素做了下选择，取左中右三者中间值。
		//**如果一直左端为枢轴，还是会超时。
		int mid = (low + high) / 2;
		if (mv[mid] < mv[low])
			swap(mv[mid], mv[low]);
		if (mv[mid] > mv[high])
			swap(mv[mid], mv[high]);
		swap(mv[mid], mv[low]);
		int pivot = mv[low];

		while (low < high) //快排交换
		{
			while (low < high && mv[high] > pivot)
				--high;
			mv[low] = mv[high];
			while (low < high && mv[low] <= pivot)
				++low;
			mv[high] = mv[low];
		}
		mv[low] = pivot;

		if (low < (N / 2 - 1))
			low0 = low + 1;
		else if (low >(N / 2 - 1))
			high0 = high - 1;
		else
			break;
	}

	for (int i = 0; i < N / 2; i++)
		leftsum += mv[i];
	
	if (N % 2 == 0)
		printf("0 %llu\n", sum - leftsum * 2);
	else
	{
		if (mv[N/2] < 0) //这里要注意，奇数个的话，要确保负值的居中元素划分给左集合
			printf("1 %llu\n", sum - leftsum * 2 -mv[N/2]*2);
		else
			printf("1 %llu\n", sum - leftsum * 2);
	}

	return 0;
}
