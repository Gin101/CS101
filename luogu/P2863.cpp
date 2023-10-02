#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int maxN = 2e4 + 1;
vector<int> e[maxN];
stack<int> s;
int dfn[maxN] = {0};
bool used[maxN] = {0};
bool flag[maxN] = {false};
int low[maxN] = {0};
int color[maxN] = {0};
int num[maxN] = {0};

int cnt = 0;
int idx = 0;
void ope(int u) {
	s.pop();
	color[u] = idx;
	num[idx]++;
	flag[u] = false;
}
void tarjan(int u) {
	dfn[u] = ++cnt;
	low[u] = cnt;
	s.push(u);
	flag[u] = true;
	used[u] = true;
	
	for (int i = 0; i < e[u].size(); i++) {
		if (!dfn[e[u][i]]) {
			tarjan(e[u][i]);
			low[u] = min(low[u], low[e[u][i]]);
		} else if (flag[e[u][i]]) {
			low[u] = min(low[u], low[e[u][i]]);
		}
	}
	
	if (low[u] == dfn[u]) {
		idx++;
		while (s.top() != u) {
			ope(s.top());
		}
		ope(u);
	}
}

int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a = 0;
		int b = 0;
		cin >> a >> b;
		
		e[a].push_back(b);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			tarjan(i);
		}
	}
	
	int result = 0;
	for (int i = 1; i <= idx; i++) {
		if (num[i] > 1) {
			result++;
		}
	}
	
	cout << result << endl;
	
	return 0;
}