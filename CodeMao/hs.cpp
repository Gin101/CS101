#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>

using namespace std;

const int maxN = 1001;

bool flag[maxN] = {false};

struct Tree {
	vector<long long> next;
	int val = 0;
}p[maxN];
long long dfs(int u, int step) {
	long long t = step * p[u].val;
	
	flag[u] = 1;
	
	for(int i = p[u].next.size() - 1; i >= 0; i--) {
		if (!flag[p[u].next[i]]) {
			t += dfs(p[u].next[i], step + 1);
		}
	}
	return t;
}
int main()
{
	int n = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int l = 0;
		int r = 0;
		cin >> p[i].val >> l >> r;
		
		if (l) {
			p[l].next.push_back(i);
			p[i].next.push_back(l);
		}
		if (r) {
			p[r].next.push_back(i);
			p[i].next.push_back(r);
		}
	}
	
	long long result = LONG_MAX;
	for (int i = 1; i <= n; i++) {
		memset(flag, 0, sizeof(flag));

		long long tmp = dfs(i, 0);
		
		if (tmp < result) {
			result = tmp;
		}
	}
	
	cout << result << endl;
	
	return 0;
}