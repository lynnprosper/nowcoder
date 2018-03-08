#include<iostream>
#include<string>
using namespace std;

string sa, sb("120");

bool is_sum(); //***数位和判断
bool is_sqr();//***数位平方和判断

/*
思路：
比较简单，直接判断就好了。
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> sa;
	if (sa == sb || is_sum() || is_sqr())
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}

bool is_sum()
{
	int x = 0;
	for (int i = 0; i < sa.size(); i++)
	{
		x += (sa[i] - '0');
		if (x > 120)
			return false;
	}
	if (x == 120)
		return true;
	else
		return false;
}

bool is_sqr()
{
	int x = 0;
	for (int i = 0; i < sa.size(); i++)
	{
		x += (sa[i] - '0')*(sa[i] - '0');
		if (x > 120)
			return false;
	}
	if (x == 120)
		return true;
	else
		return false;
}
