/*
题目描述
你将得到一个整数n,请列出把整数n划分为若干个正整数的每一种方法.

输入格式
输入共1行;

第1行，1个正整数n;

输出格式
输出为若干行:

每行为用空格隔开的若干个正整数,为一种n划分为若干个正整数的方法,每组数按从小到大输出.

若两种方法中前k-1个数相同,则第k个数更小的在前.
*/

#include <iostream>

using namespace std;

const int maxN = 20;
int number[maxN] = {0};

int n = 0;

void dfs(int sum, int start, int count) { 
	if (sum == n) {
		for (int i = 0; i < count; i++) {
			cout << number[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = start; i <= n - sum; i++) {
		number[count] = i;
		dfs(sum + i, i, count + 1);
	}
}

int main()
{
	cin >> n;
	
    dfs(0, 1, 0);
	
	return 0;
}