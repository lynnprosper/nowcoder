#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define eps 1e-8 //**定义精度，用来比较浮点数

double a, x, y, b, h;
double k, xc, yc; //分别为抛物线方程系数，顶点坐标

double getH(); //计算某点x对应的y值
/*
题意： 数学逻辑题。
思路：
求出抛物线方程，判断y值就可以了。
这里抛物线方程设为 y = k*(x-xc)^2 + yc.
注意：
有几个点涉及到精度问题，不能用默认的double比较。
这里只要两数a, b差的绝对值小于eps, 即判断小于成立
已AC.
*/

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%lf %lf %lf %lf %lf", &a, &x, &y, &b, &h);
	xc = a + x / 2;
	yc = y;
	k = -yc / pow(a - xc, 2.0);
	if (b - a < -eps || b - (a+x) > eps) //仙人掌不在起跳范围，所以不会碰到
		printf("YES\n");
	else
	{
		if (h - getH() < -eps)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

double getH()
{
	return (pow(b - xc, 2.0)*k + yc);
}
