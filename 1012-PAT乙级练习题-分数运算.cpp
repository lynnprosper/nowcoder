#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b);	//辗转相除法求最大公约数； 
void Add(int a, int b, int c, int d);
void Sub(int a, int b, int c, int d);
void Multi(int a, int b, int c, int d);
void Div(int a, int b, int c, int d);
int main()
{
	freopen("in.txt", "r", stdin);
	int a, b, c, d;
	char ch;
	while(scanf("%d/%d %d/%d %c", &a, &b, &c, &d, &ch) != EOF)
	{
		if(ch == '+')
			Add(a, b, c, d);
		else if(ch == '-')
			Sub(a, b, c, d);
		else if(ch == '*')
			Multi(a, b, c, d);
		else
			Div(a, b, c, d);
	}
	
	return 0;
}

int gcd(int a, int b)
{
	if(a == 0)
		return b;
	else
		return(gcd(b%a, a));
}
void Add(int a, int b, int c, int d)
{
	int t, m, co; 
	if(b == d)
	{
		t = a+c;
		m = b;
		co = gcd(t, m);
		printf("%d/%d\n", t/co, m/co);
		//cout << t/co << '/' << m/co << endl;
	}	
	else
	{
		m = b*d;
		t = a*d + c*b;
		co = gcd(t, m);
		printf("%d/%d\n", t/co, m/co);
	}
	return;	
}

void Sub(int a, int b, int c, int d)
{
	int t, m, co;
	t = a*d - c*b;
	m = b*d;
	co = gcd(abs(t), m);
	printf("%d/%d\n", t/co, m/co);
	
	return;
}

void Multi(int a, int b, int c, int d)
{
	int t, m, co;
	t = a*c;
	m = b*d;
	co = gcd(t, m);
	printf("%d/%d\n", t/co, m/co);
	
	return;
}
void Div(int a, int b, int c, int d)
{
	int t, m, co;
	t = a*d;
	m = b*c;
	co = gcd(t, m);
	printf("%d/%d\n", t/co, m/co);
	
	return;
}
