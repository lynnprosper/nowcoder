#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int isp[128] = { 0 }; //**存储栈中运算符的优先级
int icp[128] = { 0 }; //**存储栈外运算符的优先级
string ss; //**读入的字符串
stack<int> oper; //**操作符栈
vector<double> post;//存储后缀表达式

void ino2post(); //中缀转后缀，并计算

/*
题意：给出中缀表达式，计算结果。
思路：
栈的应用，有点麻烦。
只有转换为后缀表达式，才好计算。
转换过程大概是：
中缀中的运算数直接存入post里，
运算符要和oper的栈顶比较优先级，
大的话，压入oper
小的话，弹出，并计算，再把结果存入post里，
循环处理，即可。
已AC.
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> ss;
	isp['('] = icp[')'] = 1;
	isp[')'] = icp['('] = 6;
	isp['+'] = isp['-'] = 3;
	icp['+'] = icp['-'] = 2;
	isp['/'] = isp['*'] = 5;
	icp['/'] = icp['*'] = 4;
	
	oper.push('#'); //表示结束
	ss.push_back('#');//表示结束
	ino2post();	

	return 0;
}

void ino2post()
{
	int pos = 0;
	while (pos < ss.size())
	{
		int num = 0;
		int firstpos = pos;
		if (isdigit(ss[pos])) //运算数，存入post
		{
			while (isdigit(ss[pos]))//**判断是数字
			{
				pos++;
			}
			double x = stod(ss.substr(firstpos, pos));
			post.push_back(x);
		}
		else
		{
			while (icp[ss[pos]] < isp[oper.top()])//出栈并计算
			{
				double a, b;
				b = post.back(); //a, b不要搞反了
				post.pop_back();
				a = post.back();
				post.pop_back();
				switch (oper.top())
				{
				case '+':
					post.push_back(a + b);
					break;
				case '-':
					post.push_back(a - b);
					break;
				case '*':
					post.push_back(a * b);
					break;
				case '/':
					post.push_back(a / b);
					break;
				}

				oper.pop();
			}
			if (icp[ss[pos]] == isp[oper.top()])
			{
				if (ss[pos] == ')')
				{
					oper.pop();
					pos++;
				}
				else	//**‘#’号，可以结束了
					break;
			}
			else
			{ //**运算符优先级大， 入栈
				oper.push(ss[pos]);
				pos++;
			}
		}
	}

	printf("%.2f\n", post[0]);
}
